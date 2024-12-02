#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Node {
	string key;
	string value;
	Node(const string& key, string& value) : key(key), value(value) {}
};

class HashTable {
private:
	vector<list<Node>> table;
	int table_size;
	int hash(const string& key);

public:
	HashTable(int size) : table_size(size) { table.resize(table_size); }
	void insert(const string& key, const string& value);
	string get(const string& key);
	bool contains(const string& key);
	void remove(const string& key);
};

int HashTable::hash(const string& key) {
	return std::hash<string>()(key) % table_size;
}

void HashTable::insert(const string& key, const string& value) {
	int index = hash(key);

	for (auto& pair : table[index]) {
		if (pair.key == key) {
			pair.value = value;
			return;
		}
	}

	table[index].emplace_back(key, value);
}
	
string HashTable::get(const string& key) {
	int index = hash(key);

	for (const auto& pair : table[index]) {
		if (pair.key == key) {
			return pair.value;
		}
	}

	return "key_not_found";
}

bool HashTable::contains(const string& key) {
	return get(key) != "key_not_found";
}

void HashTable::remove(const string& key) {
	int index = hash(key);
	auto& bucket = table[index];

	for (auto it = bucket.begin(); it != bucket.end(); ++it) {
		if (it->key == key) {
			bucket.erase(it);
			return;
		}
	}
}

int main() {
	return 0;
}
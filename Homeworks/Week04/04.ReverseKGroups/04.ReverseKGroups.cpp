#include <iostream>

struct Node {
	int data;
	Node* next;

	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {};
};

void printLinkedList(Node* llist) {
	Node* curr = llist;
	while (curr != nullptr) {
		std::cout << curr->data << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

Node* reverseKGroups(Node* llist, int k) {

	Node* previous = nullptr;
	Node* current = llist;
	Node* next = current->next;
	Node* groupEnd = llist;
	Node* groupStart = llist;

	bool moveGroupStart = false;
	while (groupEnd != nullptr) {
		for (int i = 0; i < k; i++) {
			if (groupEnd == nullptr) {
				return llist;
			}
			groupEnd = groupEnd->next;
		}

		previous = groupEnd;
		while (current != groupEnd) {
			current->next = previous;
			previous = current;
			current = next;
			if (next != nullptr)
			{
				next = next->next;
			}
		}
		if (!moveGroupStart) {
			moveGroupStart = true;
			llist = previous;
		}
		else {
			groupStart->next = previous;
			for (int i = 0; i < k; i++) {
				groupStart = groupStart->next;
			}
		}
	}

	return llist;
}

int main()
{
	int n = 0;
	std::cin >> n;

	int val = 0;
	std::cin >> val;
	Node* llist = new Node(val);
	Node* curr = llist;
	for (int i = 0; i < n - 1; i++) {
		std::cin >> val;
		curr->next = new Node(val);
		curr = curr->next;
	}

	int k = 0;
	std::cin >> k;
	llist = reverseKGroups(llist, k);

	printLinkedList(llist);
}
#include <iostream>

struct Node {
	int data;
	Node* next;

	Node(int data, Node* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

struct LinkedList {
private:
	Node* head, * tail;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void print() const {
		Node* current = head;

		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}

		std::cout << '\n';
	}

	bool search(int x) const {
		Node* current = head;
		while (current != nullptr) {
			if (current->data == x) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void push_front(int x) {
		Node* newNode = new Node(x, head);
		head = newNode;

		if (tail == nullptr) { // if there are no elements
			tail = head;
		}
	}

	void push_back(int x) {
		if (head == nullptr) { // празен списък
			head = new Node(x);
			tail = head;
		}
		else {
			tail->next = new Node(x);
			tail = tail->next;
		}
	}

	void insert(int x, int pos) {
		if (pos == 0) {
			push_front(x);
			return;
		}
		else if (head == nullptr) {
			return; // Невалидна позиция, когато списъкът е празен
		}
		else {
			Node* current = head;
			Node* prev = nullptr;
			
			for (int i = 0; i < pos; i++) {
				if (current != nullptr) {
					prev = current;
					current = current->next;
				}
				else {
					return; // Невалидна позиция
				}
			}

			prev->next = new Node(x, current);

			if (tail == prev) {
				tail = prev->next;
			}
		}
	}

	void pop_front() {
		Node* temp = head;

		if (head != nullptr) {
			if (head == tail) {
				tail == nullptr;
			}
			head = head->next;

			delete temp;
		}
	}

	void pop_back() {
		Node* current;
		Node* previous;
		current = head;

		while (current != tail) {
			previous = current;
			current->next;
		}

		tail = previous;
		previous->next = nullptr;
		delete current;
	}

	void remove(int pos) {
		if (pos == 0) {
			pop_front();
			return;
		}
		else if (head == nullptr) {
			return; // Невалидна позиция, списъкът е празен
		}
		else {
			Node* current = head;
			Node* prev = nullptr;

			for (int i = 0; i < pos; i++) {
				if (current->next != nullptr) {
					prev = current;
					current = current->next;
				}
				else {
					return; // Невалидна позиция
				}
			}

			prev->next = current->next;

			if (tail == current) {
				tail = prev;
			}

			delete current;
		}
	}
};

/*
Основни операции

* Обхождане
** Принтиране
** Търсене
* Добавяне на лемент
** В началото на списъка
** В края на списъка
** На определена позиция
*Триене на елемент
** В началото на списъка
** В края на списъка
** На определена позиция
*/

int main()
{
	LinkedList* list = new LinkedList();

	return 0;
}
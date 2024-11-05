#include <iostream>

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode* next;
	SinglyLinkedListNode() : data(0), next(nullptr) {}
	SinglyLinkedListNode(int x) : data(x), next(nullptr) {}
	SinglyLinkedListNode(int x, SinglyLinkedListNode* next) : data(x), next(next) {}
};

void printSinglyLinkedList(SinglyLinkedListNode* list) {
	if (list != nullptr) {
		SinglyLinkedListNode* current = list;

		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
	}
	std::cout << std::endl;
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
	if (!llist) return nullptr;

	SinglyLinkedListNode* previous = nullptr;
	SinglyLinkedListNode* current = llist;

	while (current != nullptr) {
		previous = current;
		current = current->next;

		while (current != nullptr && previous->data == current->data) {
			SinglyLinkedListNode* temp = current;
			current = current->next;
			delete temp;
		}
		previous->next = current;
	}

	return llist;
}

int main()
{
	int T = 0, N = 0;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> N;

		if (N <= 0) {
			continue;
		}

		int val = 0;
		std::cin >> val;
		SinglyLinkedListNode* list = new SinglyLinkedListNode(val);
		SinglyLinkedListNode* tail = list;

		for (int i = 1; i < N; i++) {
			std::cin >> val;
			tail->next = new SinglyLinkedListNode(val);
			tail = tail->next;
		}

		removeDuplicates(list);

		printSinglyLinkedList(list);
	}
}
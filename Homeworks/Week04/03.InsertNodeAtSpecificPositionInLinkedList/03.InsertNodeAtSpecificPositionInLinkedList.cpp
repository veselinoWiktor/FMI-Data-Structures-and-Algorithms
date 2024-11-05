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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
	if (!llist) return nullptr;

	SinglyLinkedListNode* curr = llist;

	for (int i = 0; i < position - 1; i++) {
		curr = curr->next;
	}
	curr->next = new SinglyLinkedListNode(data, curr->next);

	return llist;
}

int main()
{
	int n = 0;
	std::cin >> n;

	SinglyLinkedListNode* llist = nullptr;

	if (n > 0) 
	{
		int val = 0;
		std::cin >> val;
		llist = new SinglyLinkedListNode(val);
		SinglyLinkedListNode* curr = llist;
		
		for (int i = 1; i < n; i++) {
			std::cin >> val;
			curr->next = new SinglyLinkedListNode(val);
			curr = curr->next;
		}
	}

	int data = 0, position = 0;

	std::cin >> data >> position;

	SinglyLinkedListNode* result = insertNodeAtPosition(llist, data, position);
	
	printSinglyLinkedList(result);
}

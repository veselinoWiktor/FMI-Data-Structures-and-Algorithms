#include <iostream>

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode* next;
	SinglyLinkedListNode() : data(0), next(nullptr) {}
	SinglyLinkedListNode(int x) : data(x), next(nullptr) {}
	SinglyLinkedListNode(int x, SinglyLinkedListNode* next) : data(x), next(next) {}
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* list1, SinglyLinkedListNode* list2) {
	if (list1 == nullptr) return list2;
	if (list2 == nullptr) return list1;

	SinglyLinkedListNode* resultHead = nullptr;
	SinglyLinkedListNode* resultTail = nullptr;

	if (list1->data <= list2->data) {
		resultHead = list1;
		list1 = list1->next;
	}
	else {
		resultHead = list2;
		list2 = list2->next;
	}
	resultTail = resultHead;

	while (list1 != nullptr && list2 != nullptr) {
		if (list1->data <= list2->data) {
			resultTail->next = list1;
			list1 = list1->next;
		}
		else {
			resultTail->next = list2;
			list2 = list2->next;
		}
		resultTail = resultTail->next;
	}

	resultTail->next = (list1 != nullptr) ? list1 : list2;

	return resultHead;
}

void printSinglyLinkedList(SinglyLinkedListNode* list) {
	SinglyLinkedListNode* current = list;

	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

int main()
{
	int T = 0, N = 0, M = 0;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> N;
		int val = 0;
		std::cin >> val;
		SinglyLinkedListNode* firstHead = new SinglyLinkedListNode(val);
		SinglyLinkedListNode* tail = firstHead;

		for (int i = 1; i < N; i++) {
			std::cin >> val;
			tail->next = new SinglyLinkedListNode(val);
			tail = tail->next;
		}

		std::cin >> M;
		std::cin >> val;
		SinglyLinkedListNode* secondHead = new SinglyLinkedListNode(val);
		tail = secondHead;

		for (int i = 1; i < M; i++) {
			std::cin >> val;
			tail->next = new SinglyLinkedListNode(val);
			tail = tail->next;
		}

		SinglyLinkedListNode* result = mergeLists(firstHead, secondHead);

		printSinglyLinkedList(result);
	}
}
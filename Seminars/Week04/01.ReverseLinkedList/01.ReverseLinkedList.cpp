#include <iostream>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int val, SinglyLinkedListNode* next = nullptr) : data(val), next(next) {};
};

void printSinglyLinkedList(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* curr = llist;

    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* previous = nullptr;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* next = current->next;

    while (current != nullptr) {
        current->next = previous;
        previous = current;
        current = next;
        if (next != nullptr) {
            next = next->next;
        }
    }

    return previous;
}

int main()
{
    int T = 0;
    std::cin >> T;

    int N = 0, val = 0;
    for (int i = 0; i < T; i++) {
        std::cin >> N;

        if (N <= 0) {
            continue;
        }
        std::cin >> val;
        SinglyLinkedListNode* llist = new SinglyLinkedListNode(val);
        SinglyLinkedListNode* current = llist;

        for (int j = 0; j < N - 1; j++) {
            std::cin >> val;
            current->next = new SinglyLinkedListNode(val);
            current = current->next;
        }

        llist = reverse(llist);

        printSinglyLinkedList(llist);
    }
}
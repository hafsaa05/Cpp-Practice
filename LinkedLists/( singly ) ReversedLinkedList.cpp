#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

Node* reverseList(Node* head) {
// Initialize three pointers: curr, prev and next
    Node *curr = head, *prev = nullptr, *next;

      // Traverse all the nodes of Linked List
    while (curr != nullptr) {
      
        // Store next
        next = curr->next;
      
        // Reverse current node's next pointer
        curr->next = prev;
      
        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }
      
      // Return the head of reversed linked list
    return prev;

}

void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(0);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(4);

    cout << "Linked list:";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);

    return 0;
}
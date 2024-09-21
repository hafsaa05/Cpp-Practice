#include<iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list from the kth node
Node* reverseFromK(Node* head, int k) {
    if (head == nullptr || k <= 1) return head;  // If the list is empty or k is 1 or less, no reversal is needed.

    Node* current = head;
    Node* prev = nullptr;

    // Traverse to the k-1 node
    for (int i = 1; current != nullptr && i < k; i++) {
        prev = current;
        current = current->next;
    }

    // Now `prev` is the k-1 node, `current` is the kth node
    if (current == nullptr) return head;  // If k is greater than the number of nodes, return the original list.

    Node* kthNode = current;  // Save the kth node as it will be the new tail of the reversed part.
    Node* nextNode = nullptr;
    Node* lastNode = prev;  // Last node before the reversal begins
    prev = nullptr;  // This will be used to reverse the list from kth node

    // Reverse from the kth node to the end
    while (current != nullptr) {
        nextNode = current->next;  // Save the next node
        current->next = prev;      // Reverse the current node's next pointer
        prev = current;            // Move prev to the current node
        current = nextNode;        // Move to the next node
    }

    // Connect the non-reversed part with the reversed part
    if (lastNode != nullptr) {
        lastNode->next = prev;  // Connect the k-1 node to the new head of the reversed part
    } else {
        head = prev;  // If k = 1, head changes to the new head of the reversed part
    }

    // Connect the kth node (which is now the tail of the reversed part) to the remaining nodes (if any)
    kthNode->next = current;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

int main() {
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List:\n";
    printList(head);

    int k = 3;
    head = reverseFromK(head, k);

    cout << "\nList after reversing from position " << k << ":\n";
    printList(head);

    return 0;
}

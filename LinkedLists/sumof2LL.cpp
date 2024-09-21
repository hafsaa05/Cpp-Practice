#include<iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}  // Constructor to initialize the node
};

// Function to add two linked lists
Node* addLists(Node* l1, Node* l2) {
    Node* result = nullptr;  // This will store the resultant linked list
    Node* temp = nullptr, *prev = nullptr;
    int carry = 0, sum = 0;

    // Traverse both lists while there are nodes in either or there's a carry
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        // Calculate the sum of corresponding digits and carry
        sum = carry + (l1 ? l1->data : 0) + (l2 ? l2->data : 0);

        // Update the carry for next calculation
        carry = sum / 10;

        // The digit to store in the result node (sum mod 10)
        sum = sum % 10;

        // Create a new node with the sum and add it to the result list
        temp = new Node(sum);

        // If result is empty, set the first node
        if (result == nullptr) {
            result = temp;
        } else {
            prev->next = temp;  // Attach the new node to the previous one
        }

        // Move the prev pointer for the next node
        prev = temp;

        // Move to the next nodes in l1 and l2, if they exist
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    return result;  // Return the head of the resultant list
}

// Function to print a linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr\n";
}

int main() {
    // Creating the first linked list (243)
    Node* l1 = new Node(3);
    l1->next = new Node(4);
    l1->next->next = new Node(2);

    // Creating the second linked list (867)
    Node* l2 = new Node(7);
    l2->next = new Node(6);
    l2->next->next = new Node(8);

    // Adding the two lists
    Node* result = addLists(l1, l2);

    // Printing the result list
    cout << "Resultant list is: ";
    printList(result);

    return 0;
}

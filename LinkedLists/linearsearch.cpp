#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int d): data(d), next(nullptr) {}
};

class singly_linkedlist {
    node* head;

    public:
    singly_linkedlist(): head(nullptr) {}

    void insertAtEnd(int val) {
        node* n = new node(val);
        if (head == nullptr) {
            head = n;
        } else {
            node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = n;
        }
    }

    bool linearSearch(int key) {
        node* curr = head;
        while (curr != nullptr) {
            if (curr->data == key) {
                return true;  // Found the key
            }
            curr = curr->next;
        }
        return false;  // Key not found in the list
    }

    void print() {
        node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "nullptr\n";
    }
};

int main() {
    singly_linkedlist list;

    // Inserting elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Linked list: ";
    list.print();

    // Searching for values
    int key = 30;
    if (list.linearSearch(key)) {
        cout << "Element " << key << " is found in the list.\n";
    } else {
        cout << "Element " << key << " is not found in the list.\n";
    }

    key = 100;
    if (list.linearSearch(key)) {
        cout << "Element " << key << " is found in the list.\n";
    } else {
        cout << "Element " << key << " is not found in the list.\n";
    }

    return 0;
}

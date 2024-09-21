#include<iostream>
using namespace std;

class node {
    int data;
    node* next, * prev;

    public:
    node(): data(0), prev(nullptr), next(nullptr){}
    node(int d): data(d), prev(nullptr), next(nullptr){}

    friend class doubly_linkedlist;
};

class doubly_linkedlist {
    node* head;

    public:
    doubly_linkedlist(): head(nullptr){}
    doubly_linkedlist(node* h): head(h){}

    void insertAFront(const int val){
        node* n = new node(val);
        if (head == nullptr) {
            head = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertAtEnd(const int val) {
        node* n = new node(val);
        if (head == nullptr) {
            head = n;
        } else {
            node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = n;
            n->prev = curr;
        }
    }

    void insertBeforeValue(int key, int newData) {
        node* curr = head;
        while (curr != nullptr && curr->data != key) {
            curr = curr->next;
        }
        if (curr != nullptr) {
            node* n = new node(newData);
            n->next = curr;
            n->prev = curr->prev;

            if (curr->prev != nullptr) {
                curr->prev->next = n;
            } else {
                head = n;
            }
            curr->prev = n;
        }
    }

    void insertAfter(int key, int newData) {
        node* curr = head;
        while (curr != nullptr && curr->data != key) {
            curr = curr->next;
        }
        if (curr != nullptr) {
            node* n = new node(newData);
            n->next = curr->next;
            n->prev = curr;
            if (curr->next != nullptr) {
                curr->next->prev = n;
            }
            curr->next = n;
        }
    }

    // Insert at a given position
    void insertAtPosition(int pos, int newData) {
        if (pos == 0) {
            insertAFront(newData);
            return;
        }

        node* curr = head;
        int currentIndex = 0;

        while (curr != nullptr && currentIndex < pos - 1) {
            curr = curr->next;
            currentIndex++;
        }

        if (curr != nullptr) {
            node* n = new node(newData);
            n->next = curr->next;
            n->prev = curr;
            if (curr->next != nullptr) {
                curr->next->prev = n;
            }
            curr->next = n;
        } else {
            cout << "Position out of bounds!" << endl;
        }
    }

    // Insert at the middle
    void insertAtMiddle(int newData) {
        if (head == nullptr) {
            insertAFront(newData);
            return;
        }

        node* slow = head;
        node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        insertBeforeValue(slow->data, newData);
    }

    // Delete at a given position
    void deleteAtPosition(int pos) {
        if (pos == 0) {
            deleteAtFront();
            return;
        }

        node* curr = head;
        int currentIndex = 0;

        while (curr != nullptr && currentIndex < pos) {
            curr = curr->next;
            currentIndex++;
        }

        if (curr != nullptr) {
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }
            delete curr;
        } else {
            cout << "Position out of bounds!" << endl;
        }
    }

    void deleteAtFront(){
        if (head != nullptr) {
            node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
        }
    }

    void deleteAtEnd(){
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->prev->next = nullptr;
            delete curr;
        }
    }

    void deleteValue(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        node* curr = head;
        while (curr != nullptr && curr->data != value) {
            curr = curr->next;
        }

        if (curr != nullptr) {
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            }
            delete curr;
        }
    }

    void print(){
        node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "nullptr\n";
    }
};

int main(){
    doubly_linkedlist l;

    // Insert elements at the end
    l.insertAtEnd(4);
    l.insertAtEnd(6);
    l.insertAtEnd(7);
    l.insertAtEnd(8);
    l.insertAtEnd(9);
    l.insertAtEnd(2);
    cout << "Original List:\n";
    l.print();

    // Insert at front
    cout << "Inserting at front:\n";
    l.insertAFront(3);
    l.print();

    // Insert before value 6
    cout << "Inserting before value 6:\n";
    l.insertBeforeValue(6, 5);
    l.print();

    // Insert after value 7
    cout << "Inserting after value 7:\n";
    l.insertAfter(7, 10);
    l.print();

    // Insert at a given position
    cout << "Inserting at position 2:\n";
    l.insertAtPosition(2, 15);
    l.print();

    // Insert at the middle
    cout << "Inserting at the middle:\n";
    l.insertAtMiddle(12);
    l.print();

    // Delete node at front
    cout << "Deleting node at front:\n";
    l.deleteAtFront();
    l.print();

    // Delete node at end
    cout << "Deleting node at end:\n";
    l.deleteAtEnd();
    l.print();

    // Delete node at position 3
    cout << "Deleting node at position 3:\n";
    l.deleteAtPosition(3);
    l.print();

    // Delete node with value 5
    cout << "Deleting node with value 5:\n";
    l.deleteValue(5);
    l.print();

    return 0;
}

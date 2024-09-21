#include<iostream>
using namespace std;

class node{
    int data;
    node* next, * prev;

    public:
    node(): data(0), prev(nullptr), next(nullptr){}
    node(int d): data(d), prev(nullptr), next(nullptr){}

    friend class doubly_linkedlist;
};

class doubly_linkedlist{
    node* head;

    public:
    doubly_linkedlist(): head(nullptr){}
    doubly_linkedlist(node* h): head(h){}

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

    void sort(){
        if(head==nullptr) return;
        int temp;
        node* i, *j;

        for(i=head; i != nullptr; i=i->next){
            for(j=i->next; j != nullptr; j=j->next){
                if(i->data > j->data){
                    temp = i->data;
                    i->data=j->data;
                    j->data=temp;
                } 
        }            
        }
    }

    void deleteValue(int value){
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

    void duplicate() {
    if (head == nullptr) return;

    for (node* i = head; i != nullptr; i = i->next) {
        for (node* j = i->next; j != nullptr; ) {
            if (i->data == j->data) {
                node* dup = j;
                j = j->next; 
                deleteValue(dup->data);  
            } else {
                j = j->next;
            }
        }
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

    l.insertAtEnd(6);
    l.insertAtEnd(4);
    l.insertAtEnd(1);
    l.insertAtEnd(9);
    l.insertAtEnd(6);
    l.insertAtEnd(0);
    l.insertAtEnd(2);
    cout << "Original:\n";
    l.print();

    cout<<"Sorted:\n";
    l.sort();
    l.print();

    cout<<"Removing Duplicates:\n";
    l.duplicate();
    l.print();

    return 0;
}
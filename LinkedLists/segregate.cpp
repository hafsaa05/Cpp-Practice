// Insert some elements in Singly Linked List and write a function to segregate even and
// odd numbers such that all even numbers precede odd numbers.
#include<iostream>
using namespace std;
class node{
    int data;
    node* next;

    public:
    node(): data(0), next(nullptr){}
    node(int d): data(d), next(nullptr){}

    friend class singly;
};

class singly{
    node* head;

    public:
    singly():head(nullptr){}
    singly(node* h):head(h){}

void display(){
    node* curr = head;
    while(curr != nullptr){
        cout<<curr->data<<" -->";
        curr = curr->next;
    } cout<<"nullptr\n";
}

void insert(const int val) {
        node* n = new node(val);
        if(head==nullptr){ 
            head = n;
         } else {
            node* curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = n;
         }
        
    }
node* segregate(){
    node* even  = nullptr;
    node* e  = nullptr;
    node* odd  = nullptr;
    node* o  = nullptr;

    while(head){
        if(head->data % 2 == 0){
            if(even==nullptr){
                even = head;
                e = head;
            } else {
                e->next = head;
                e = e->next;
            }
        } else {
            if(odd==nullptr){
                odd = head;
                o = head;
            } else {
                o->next = head;
                o = o->next;
            }
        }
        head = head->next;
    }
    if(e) e->next = odd;
    if(o) o->next = nullptr;
    if(even) return even;
    return odd;
}    
void updateHead(node* newHead) {
    head = newHead;  // Update the head pointer of the list
}
};
int main(){
    singly list;
    list.insert(10);
    list.insert(11);
    list.insert(12);
    list.insert(13);
    list.insert(15);
    cout<<"Original\n";
    list.display();
    cout<<"Segregating list\n";
    list.updateHead(list.segregate());
    list.display();

}
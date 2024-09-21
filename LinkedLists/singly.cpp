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

//_________________________________ Insert node at front ____________________________________________________________
void insertFront(const int val) {
        node* n = new node(val);
        n->next = head;
        head = n;
        cout << "After insertFront(" << val << "): ";
        display();
    }
//_________________________________ Insert node at end ____________________________________________________________
void insertTail(const int val) {
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
        cout << "After insert tail(" << val << "): ";
        display();
    }
//_________________________________ Insert node at pos ____________________________________________________________
void insertAtPos(const int val, int pos) {
        node* n = new node(val);
        
        if(pos == 1){ 
            n->next = head;
            head = n;
         } else {
            node* curr = head;
            int count=1; //to track pos in list
            while(count < pos-1 && curr != nullptr){
                curr=curr->next;
                count++;
            }
            if(curr != nullptr){
                n->next = curr->next;
                curr->next=n;
            }else{
                cout<<"Position out of bound.";
                delete n;
                return;
            }
        }
        cout << "After inserting at pos(" << pos << "): ";
        display();
    }
//_________________________________ Insert node at mid ____________________________________________________________
void insertAtMid(const int val) {
        node* n = new node(val);
        
        if(head == nullptr){
            head = n;
         } else {
            node* curr = head;
            int len=0; //to track length in list
            while(curr != nullptr){
                len++;
                curr=curr->next;
            }
            int mid = len/2;

            curr = head;  // reset to head for the second traversal since it was nullptr in prev traverse
            while(mid>1){
                curr=curr->next;
                mid--;
            }
            n->next=curr->next;
            curr->next=n;

        }

        cout << "After inserting at mid(" << val << "): ";
        display();
    }
//_________________________________ Delete node at front ____________________________________________________________
void delHead() {
        if (head != nullptr) {
            node* curr= head;
            head = curr->next;
            delete curr;
            cout << "After delHead(): ";
            display();
        } else {
            cout << "List is already empty" << endl;
        }
    }
//_________________________________ Delete node at end ____________________________________________________________
void delTail() {
    if(head==nullptr) return;//empty list
    if(head->next = nullptr){
        delete head;
        cout << "After deleting tail: ";
            display();
    }
        node* curr= head;

        while (curr->next->next != nullptr)
        //The condition while (curr->next->next != nullptr) ensures that you stop when curr is at the second-to-last node. 
        {
            curr = curr->next;
        }
            delete curr->next;
            cout << "After deleting tail: ";
            display();
        
    }
//_________________________________ Delete node of a particular value ____________________________________________________________
void delValue(const int val){
    if(head==nullptr) return;//empty list
    // else if(head->data == val){
    //     node* key = head;
    //     head = head->next;
    //     delete head;
    //     cout << "After delValue(" << val << "): ";
    //     display();
    //     return;
    // }
    else {
        node* curr = head;
        while(curr->next != nullptr && curr->next->data != val){
            curr = curr->next;
        }
        if(curr->next != nullptr){
            node* key = curr->next;
            curr->next = curr->next->next;
            delete key;
        }
        cout << "After delValue(" << val << "): ";
        display();
    }
}
//_________________________________ Delete node at pos ____________________________________________________________

void delPos(const int pos){
    if(head==nullptr) return ;
    else if(pos == 1){
        node* curr = head;
        head = curr->next;
        delete curr;
        curr = nullptr;
    }
    else{
        node* curr = head;
        node* prev = nullptr;
        int currPos = 1;
        
        while( curr != nullptr && currPos < pos){
            prev = curr;
            curr = curr->next;
            currPos++;
            }
        if(curr == nullptr){
            // The position is out of bounds (list is shorter than 'pos')
            return;
        }
        prev->next = curr->next;
        delete curr;
    }
    cout << "After deleleting at position(" << pos << "): ";
    display();
}
//________________________________________Count nodes _______________________________________________
int count(){
    if (head ==nullptr) return 0 ;
    else{
        int count=0;
        node *curr=head;
        while(curr != nullptr){
            count++;
            curr=curr->next;
        }
        return count;
    }
}
//_________________________________ Delete node at mid ____________________________________________________________
void DelAtMid(){
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or contains only one node, just return or handle as needed
        return;
    }
    
    node* curr = head;
    int len = 0;  // To track the length of the list
    
    // First, calculate the length of the list
    while (curr != nullptr) {
        len++;
        curr = curr->next;
    }

    int mid = len / 2;  // Find the middle position

    curr = head;  // Reset the current pointer to the head

    // Special case if we're deleting the head (for an odd number of nodes)
    if (mid == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
    } else {
        // Traverse to the node just before the middle node
        node* prev = nullptr;
        while (mid > 0) {
            prev = curr;
            curr = curr->next;
            mid--;
        }
        
        // `curr` is now pointing to the middle node, and `prev` is the node before it
        prev->next = curr->next;  // Bypass the middle node
        delete curr;  // Delete the middle node
    }

    cout << "After deleting at mid: ";
    display();
}
    };

int main() {
    singly list;
    list.insertFront(10);
    list.insertFront(11);
    list.insertFront(12);
    list.insertFront(13);
    list.insertFront(15);

    // list.insertAtPos(3,5);
    // list.insertAtMid(19);
    // list.delHead();
    // list.delTail();
     //list.delValue(13);
    //list.delPos(2);
    //cout<<list.count();
    //list.DelAtMid();
}
#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* prev;
        Node* next;
        Node();
        Node(int);
};

Node :: Node(){
    data=0;
    prev=NULL;
    next=NULL;
};

Node :: Node(int data){
    this->data=data;
    prev=NULL;
    next=NULL;
};

class DoublyLinkedList{
    Node *head;

    public:
        DoublyLinkedList(){
            head=NULL;
        }
        bool headNull(){
            return head==NULL;
        }
        void insertAtStart(int);
        void insertAtEnd(int);
        void insertInMid(int,int);
        void delFromStart();
        void delFromEnd();
        void delFromMidVal(int);
        void display();
};

void DoublyLinkedList :: insertAtStart(int data){
    Node* newNode=new Node(data);
    if(headNull()){
        head=newNode;
        cout << "New node added at the beginning of the list." << endl;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    cout << "New node added at the beginning of the list." << endl;
    return;
};

void DoublyLinkedList :: insertAtEnd(int data){
    Node* newNode=new Node(data);
    Node* current=head;

    while(current->next!=NULL){
        current=current->next;
    };
    newNode->prev=current;
    current->next=newNode;
    cout << "New node added at the end of the list." << endl;
    return;
};

void DoublyLinkedList :: insertInMid(int data,int pos){
    Node* newNode=new Node(data);
    Node* current=head;
    if(pos>1){
        for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    newNode->next=current->next;
    current->next->prev=newNode;
    current->next=newNode;
    newNode->prev=current;
    
    cout << "New node added at position " << pos << "." << endl;
    return;
    }
    newNode->next = head;
    head = newNode;
    cout << "New node added at position " << pos << "." << endl;
    return;
};

void DoublyLinkedList :: delFromStart(){
    Node* current=head;
    if(headNull()){
        cout<<"Linked List is already empty!"<<endl;
        return;
    }
    if(current->next==NULL){
        head=NULL;
        free(current);
        cout<<"Linked list is empty."<<endl;
        return;
    }
    head=head->next;
    free(current);
};

void DoublyLinkedList :: delFromEnd(){
    Node* current=head;
    if(head->next==NULL){
        head=NULL;
        free(current);
        cout<<"Linked list is empty."<<endl;
        return;
    }
    while(current->next!=NULL){
        current=current->next;
    };
    current->prev->next=NULL;
    free(current);
};

void DoublyLinkedList :: delFromMidVal(int data){
    Node* current = head;
    if(head->data==data){
        head=current->next;
        if(current->next==NULL){
            cout<<"Linked list is empty."<<endl;
            free(current);
            return;
        }
        free(current);
        return;
    }while (current!= NULL) {
        if(current->data==data){
            current->prev->next=current->next;
            current->next->prev = current->prev;
            free(current);
           return;
        }
        current = current->next;
    }
    cout<<"Node not found!"<<endl;
    return;
};

void DoublyLinkedList::display() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main(){
    DoublyLinkedList linkedList;
    linkedList.insertAtStart(4);
    linkedList.display(); 
    linkedList.insertAtEnd(8);
    linkedList.display(); 
    linkedList.insertInMid(5,1);
    linkedList.display();
    linkedList.insertAtStart(2); 
    linkedList.display();
    linkedList.delFromMidVal(5);
    linkedList.display();
    linkedList.delFromMidVal(4);
    linkedList.display();
    linkedList.delFromMidVal(2);
    linkedList.display();
    linkedList.delFromMidVal(9);
    linkedList.display();
    linkedList.insertAtStart(4);
    linkedList.display(); 
    linkedList.insertAtEnd(8);
    linkedList.display(); 
    linkedList.insertInMid(5,1);

    linkedList.display();
    return 0;
}

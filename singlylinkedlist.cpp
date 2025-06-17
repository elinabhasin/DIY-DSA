#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* ptr;
    Node();
    Node(int);
};

Node::Node() {
    data = 0;
    ptr = NULL;
}

Node::Node(int data) {
    this->data = data;
    ptr = NULL; 
}

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;

    }

    bool headNull() {
        return head==NULL;
    }

    void insertAtStart(int);
    void insertInMid(int,int);
    void insertAtEnd(int);
    void delFromStart();
    void delFromMidVal(int);
    void delFromEnd();
    void display();
};

//Given valid positions : (position checks have been omitted)
//Check to see if linkedlist is aready empty(underflow) is omitted

void SinglyLinkedList :: delFromStart(){

    Node* current=head;
    if(headNull()){
        cout<<"Linked List is already empty!"<<endl;
        return;
    }
    if(current->ptr==NULL){
        head=NULL;
        free(current);
        cout<<"Linked list is empty."<<endl;
        return;
    }
    head=head->ptr;
    free(current);
    
};

void SinglyLinkedList :: delFromMidVal(int data){
    Node* current = head;
    if(head->data==data){
        head=current->ptr;
        if(current->ptr==NULL){
            cout<<"Linked list is empty."<<endl;
            free(current);
            return;
        }
        free(current);
        return;
    }
    while (current->ptr != NULL) {
        if(current->ptr->data==data){
            Node* curr=current->ptr;
           current->ptr=current->ptr->ptr;
           free(curr);
           return;
        }
        current = current->ptr;
    }
    cout<<"Node not found!"<<endl;
    return;
};

void SinglyLinkedList :: delFromEnd(){
    Node* current = head;
    if(current->ptr==NULL){
        head=NULL;
        free(current);
        cout<<"Linked list is empty."<<endl;
        return;
    }
    while (current->ptr->ptr != NULL) {
        current = current->ptr;
    }
    Node* ptr=current->ptr;
    current->ptr=NULL;
    free(ptr);

};

void SinglyLinkedList :: insertAtStart(int data){
    Node* newNode = new Node(data);
    if (headNull()) {
        head = newNode;
        cout << "New node added at the beginning of the list." << endl;
        return;
    }else{
        newNode->ptr = head;
        head = newNode;
        cout << "New node added at the beginning of the list." << endl;
        return;
    }
};
void SinglyLinkedList :: insertInMid(int data,int pos){
    Node* newNode = new Node(data);
    Node* current = head;
    if(pos>1){
        for (int i = 1; i < pos - 1; i++) {
        current = current->ptr;
    }
    newNode->ptr = current->ptr;
    current->ptr = newNode;
    cout << "New node added at position " << pos << "." << endl;
    return;
    }
    newNode->ptr = head;
    head = newNode;
    cout << "New node added at position " << pos << "." << endl;
    return;
};

void SinglyLinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);
        Node* current = head;
        while (current->ptr != NULL) {
            current = current->ptr;
        }
        current->ptr = newNode; 
        cout << "New node added at the end of the list." << endl;
        return;

}

void SinglyLinkedList::display() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data;
        if (current->ptr != NULL) {
            cout << " -> ";
        }
        current = current->ptr;
    }
    cout << endl;
}

int main() {
    SinglyLinkedList linkedList;
    linkedList.insertAtStart(4); 
    linkedList.insertAtEnd(8); 
    linkedList.insertInMid(5,1);
    linkedList.insertAtStart(2); 
    linkedList.delFromMidVal(5);
    linkedList.delFromMidVal(4);
    linkedList.delFromMidVal(2);
    linkedList.delFromMidVal(9);
    linkedList.insertAtStart(4); 
    linkedList.insertAtEnd(8); 
    linkedList.insertInMid(5,1);

    linkedList.display();  

    return 0;
}

#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList{
   Node *head;

   public:
    CircularDoublyLinkedList() : head(nullptr) {}

    bool headNull() {
        return head == nullptr;
    }

    void insertAtStart(int);
    void insertAtEnd(int);
    void insertInMid(int, int);
    void delFromStart();
    void delFromEnd();
    void delFromMidVal(int);
    void display();
};

void CircularDoublyLinkedList :: insertAtStart(int data){
    Node* newNode=new Node(data);
    if(headNull()){
        head=newNode;
        newNode->next=head;
        newNode->prev=head;
    }else{
        newNode->next=head;
        newNode->prev=head->prev;
        head->prev->next=newNode;
        head->prev=newNode;
        head=newNode;
    }
    cout << "New node added at the beginning." << endl;
    
    return;
};

void CircularDoublyLinkedList :: insertAtEnd(int data){
    Node* newNode=new Node(data);
    if(headNull()){
        head=newNode;
        newNode->next=head;
        newNode->prev=head;
    }else{
        newNode->prev=head->prev;
        newNode->next=head;
        head->prev->next=newNode;
        head->prev=newNode;
    }
    cout << "New node added at the end." << endl;
    
    return;
};

void CircularDoublyLinkedList::insertInMid(int data, int pos) {
    Node* newNode = new Node(data);
    Node* current = head;
    if (pos < 1) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (pos == 1) {
        insertAtStart(data);
        return;
    }
    int count = 1; 

    while (current->next != head && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current->next == head) {
        newNode->next = head;
        newNode->prev = current;
        current->next = newNode;
        head->prev = newNode;
        cout << "Position exceeds list size; added node at the end." << endl;
    }else{
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        cout << "New node added at position " << pos << "." << endl;
    }

    return;
}

void CircularDoublyLinkedList :: delFromStart() {
    if (headNull()) { 
        cout << "Linked list is already empty!" << endl;
        return;
    }
    if (head->next == head) {
        delete head; 
        head = nullptr;
    } else {
        Node* last = head->prev; 
        Node* curr = head; 
        last->next = head->next;
        head->next->prev = last;
        head = head->next;
        delete curr;
    }
    cout << "Node deleted from the start." << endl;
}

void CircularDoublyLinkedList :: delFromEnd() {
    if (headNull()) { 
        cout << "Linked list is already empty!" << endl;
        return;
    }
    if (head->next == head) {
        delete head; 
        head = nullptr;
    } else {
        Node* last = head->prev; 
        last->prev->next = head;
        head->prev = last->prev;
        delete last;
    }
    cout << "Node deleted from the end." << endl;
}

void CircularDoublyLinkedList::delFromMidVal(int data) {
    Node* temp;
    if (headNull()) {
        cout << "Linked list is empty." << endl;
        return;
    }
    Node* current = head;
    if (head->data == data) {
        delFromStart();
        return;
    }
    while (current->next != head) {
        if (current->next->data == data) {
            temp = current->next;
            current->next = temp->next;
            if (temp == head->prev) {
                head->prev = current;
            }
            delete temp;
            cout << "Node with value " << data << " deleted." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Node not found!" << endl;
};

void CircularDoublyLinkedList::display() {
    if (headNull()) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* current = head;
        do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << " (Back to head)" << endl;
}

int main() {
    CircularDoublyLinkedList linkedlist;
    linkedlist.insertAtStart(4);
    linkedlist.insertAtEnd(5);
    linkedlist.insertAtEnd(6);
    linkedlist.insertInMid(10, 2);
    linkedlist.display();
    linkedlist.delFromStart();
    linkedlist.display();
    linkedlist.delFromEnd();
    linkedlist.display();
    linkedlist.delFromMidVal(10);
    linkedlist.display();
    linkedlist.delFromMidVal(5);
    linkedlist.display();

    return 0;
}

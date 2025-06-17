#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
};

class CircularLinkedList {
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    bool tailNull() {
        return tail == nullptr;
    }

    void insertAtStart(int);
    void insertAtEnd(int);
    void insertInMid(int, int);
    void delFromStart();
    void delFromEnd();
    void delFromMidVal(int);
    void display();
};

void CircularLinkedList::insertAtStart(int data) {
    Node* newNode = new Node(data);
    if (tailNull()) {
        tail = newNode;
        newNode->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    cout << "New node added at the beginning." << endl;
}

void CircularLinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (tailNull()) {
        tail = newNode;
        newNode->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    cout << "New node added at the end." << endl;
}

void CircularLinkedList::insertInMid(int data, int pos) {
    if (pos <= 1) {
        insertAtStart(data);
        return;
    }
    Node* newNode = new Node(data);
    if (tailNull()) {
        tail = newNode;
        newNode->next = tail;
        cout << "New node added at the end." << endl;
        return;
    }
    Node* current = tail->next;
    for (int i = 1; i < pos - 1 && current != tail; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    cout << "New node added at position " << pos << "." << endl;
}

void CircularLinkedList::delFromStart() {
    if (tailNull()) {
        cout << "Linked list is already empty." << endl;
        return;
    }
    Node* head = tail->next;
    if (tail == head) {
        delete tail;
        tail = NULL;
    } else {
        tail->next = head->next;
        delete head;
    }
    cout << "Node deleted from the start." << endl;
}

void CircularLinkedList::delFromEnd() {
    if (tailNull()) {
        cout << "Linked list is already empty." << endl;
        return;
    }
    Node* head = tail->next;
    if (tail == head) {
        delete tail;
        tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        delete tail;
        tail = current;
    }
    cout << "Node deleted from the end." << endl;
}

void CircularLinkedList::delFromMidVal(int data) {
    if (tailNull()) {
        cout << "Linked list is empty." << endl;
        return;
    }
    Node* current = tail->next;
    if (current->data == data) {
        delFromStart();
        return;
    }
    while (current->next != tail->next) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) {
                tail = current;
            }
            delete temp;
            cout << "Node with value " << data << " deleted." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Node not found!" << endl;
}

void CircularLinkedList::display() {
    if (tailNull()) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* current = tail->next;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != tail->next);
    cout << " (Back to head)" << endl;
}

int main() {
    CircularLinkedList linkedlist;
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

    return 0;
}

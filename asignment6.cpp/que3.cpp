#include <iostream>
using namespace std;


// Doubly Linked List

class DoublyLinkedList {
struct Node {
int data;
Node* prev;
Node* next;
Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
Node* head;

public:
DoublyLinkedList() : head(nullptr) {}
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int size() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display() {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
};
// Circular Linked List

class CircularLinkedList {
struct Node {
int data;
Node* next;
Node(int val) : data(val), next(nullptr) {}
};
Node* head;

public:
CircularLinkedList() : head(nullptr) {}
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

int size() {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void display() {
    if (!head) return;
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
};


int main() {
DoublyLinkedList dll;
CircularLinkedList cll;
// Insert some nodes
dll.insertAtEnd(10);
dll.insertAtEnd(20);
dll.insertAtEnd(30);

cll.insertAtEnd(5);
cll.insertAtEnd(15);
cll.insertAtEnd(25);
cll.insertAtEnd(35);

// Display lists
dll.display();
cll.display();

// Display sizes
cout << "Size of Doubly Linked List: " << dll.size() << endl;
cout << "Size of Circular Linked List: " << cll.size() << endl;

return 0;
}
#include <iostream>
#include <string>
using namespace std;

// ===================================================
// 1. DOUBLY LINKED LIST IMPLEMENTATION
// ===================================================
class DoublyLinkedList {
struct Node {
char data;
Node* prev;
Node* next;
Node(char val) : data(val), prev(nullptr), next(nullptr) {}
};
// Insert at beginning
void insertAtBeginning(char val) {
    Node* newNode = new Node(val);
    if (!head)
        head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(char val) {
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

// Delete a specific node
void deleteNode(char val) {
    if (!head) return;
    Node* temp = head;
    while (temp && temp->data != val)
        temp = temp->next;

    if (!temp) {
        cout << "Node not found.\n";
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
}

// Search for a node
bool search(char val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

// Display list
void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Find size
int size() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Check if palindrome
bool isPalindrome() {
    if (!head) return true;
    Node* left = head;
    Node* right = head;

    // Move right to the end
    while (right->next)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

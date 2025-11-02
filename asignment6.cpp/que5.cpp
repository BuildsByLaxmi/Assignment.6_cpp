#include <iostream>
using namespace std;

// Node structure
struct Node {
int data;
Node* next;
Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
Node* head;

public:
LinkedList() : head(nullptr) {}
// Insert node at end
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
}

// Make the list circular (for testing)
void makeCircular() {
    if (!head) return;
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head; // Last node points to head
}

// Function to check if the linked list is circular
bool isCircular() {
    if (!head) return false;
    Node* temp = head->next;

    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

// Display first few nodes (to avoid infinite loop)
void display() {
    if (!head) return;
    Node* temp = head;
    int count = 0;
    while (temp && count < 10) { // limit to prevent infinite print
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "..." << endl;
}
};
int main() {
LinkedList list;
int n;
cout << "Enter number of nodes: ";
cin >> n;

cout << "Enter node values:\n";
for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    list.insertAtEnd(val);
}

char choice;
cout << "Do you want to make the list circular? (y/n): ";
cin >> choice;
if (choice == 'y' || choice == 'Y')
    list.makeCircular();

list.display();

if (list.isCircular())
    cout << "True (The linked list is circular)" << endl;
else
    cout << "False (The linked list is not circular)" << endl;

return 0;
}
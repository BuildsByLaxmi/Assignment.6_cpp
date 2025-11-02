#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
char data;
Node* prev;
Node* next;
Node(char val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List Class
class DoublyLinkedList {
Node* head;

public:
DoublyLinkedList() : head(nullptr) {}
// Insert character at the end
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

// Function to check if the list is palindrome
bool isPalindrome() {
    if (!head) return true; // empty list is palindrome

    Node* left = head;
    Node* right = head;

    // Move right pointer to the last node
    while (right->next)
        right = right->next;

    // Compare from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

// Display function (optional)
void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
};
int main() {
DoublyLinkedList dll;
int n;
cout << "Enter number of characters: ";
cin >> n;

cout << "Enter characters one by one:\n";
for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    dll.insertAtEnd(ch);
}

dll.display();

if (dll.isPalindrome())
    cout << "True" << endl;
else
    cout << "False" << endl;

return 0;
}
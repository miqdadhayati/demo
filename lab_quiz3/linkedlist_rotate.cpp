#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// (a) Implement this function - 6 points
void insertAtEnd(Node*& head, int val){
    Node* temp = new Node(val);
    if (head == nullptr) {
        head = temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = temp;
}
// helper function:
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// (b) Implement this function - 14 points
Node* rotateRight(Node* head, int k){
    if (head == nullptr){
        return head;
    }
    // single node
    if (head->next == nullptr){
        return head;
    }
    // k = 0
    if (k == 0){
        return head;
    }
    
    Node* temp = head;
    // finding lenght
    int len = 1;
    while (temp->next != nullptr){
        len++;
        temp = temp->next;
    }
    k = k % len; 
    if (k == 0) {
        return head;
    }
    Node* new_head = head;
    for (int i = 1; i <(len - k); i++) {
        new_head = new_head->next;
    }
    Node* head1 = head;
    Node* head2 = new_head->next;
    new_head->next = nullptr; 
    head1 = reverse(head1);
    head2 = reverse(head2);
    temp = head1;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head2;
    head = reverse(head1);
    return head;
}

// Display function provided
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = nullptr;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        // Call insertAtEnd function here
        insertAtEnd(head, val);
    }

    cout << "Enter rotation count k: ";
    cin >> k;

    cout << "Original list: ";
    display(head);

    // call rotateRight function here
    head = rotateRight(head, k);
    cout << "Rotated list: ";
    display(head);

    return 0;
}




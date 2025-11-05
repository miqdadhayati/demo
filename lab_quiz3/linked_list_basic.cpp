#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// printing every element
void printList(Node* head){
    Node* current = head;
    while (current!= nullptr) {
        cout << current->data << endl;
        current= current->next; 
    }
    cout << "NULL\n";
}
// finding middle (two ptr approach)
Node* findMiddle(Node* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast!=nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// reversing :(
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
    }
// merging sorted lists
Node* mergeSortedLists(Node* head1, Node* head2){
    Node dummy(0);
    Node* tail = &dummy;

    while(head1 !=nullptr && head2 != nullptr){
        if (head1->data <= head2->data){
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    // if one list is bigger than other, few elements will be left, manually attach them
    if (head1 != nullptr){
        tail->next = head1;
    } else {
        tail->next = head2;
    }
    }
    return dummy.next;
}

// --- MAIN FUNCTION ---
// (This is where you create lists and call your functions)
int main() {
    
    // --- Test 1: Create a list, print it, find middle ---
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original List: " << endl;
    printList(head); // Call printList

    Node* middle = findMiddle(head); // Call findMiddle
    cout << "Middle element: " << middle->data << endl;
    cout << "---" << endl;

    // --- Test 2: Reverse the list ---
    cout << "Reversing List: " << endl;
    head = reverse(head); // Call reverse and UPDATE the head pointer
    printList(head); // Print the new, reversed list
    cout << "---" << endl;

    // --- Test 3: Merge two sorted lists ---
    // Create two new sorted lists
    Node* list1 = new Node(1);
    list1->next = new Node(5);
    list1->next->next = new Node(10);

    Node* list2 = new Node(2);
    list2->next = new Node(7);
    list2->next->next = new Node(12);

    cout << "Merging Lists:" << endl;
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* mergedHead = mergeSortedLists(list1, list2); // Call merge
    cout << "Merged List: " << endl;
    printList(mergedHead); // Print the final merged list

    return 0; // Good practice
}

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int n) {
        data = n;
        next = nullptr;
    }
};

void traverse(Node* head);
Node* insertion(Node* head, Node* elem, int position=0);
Node* deletion(Node* head, int position=0);

int main(void) {
    Node* nodeZero = new Node(0);
    Node* nodeOne = new Node(1);
    Node* nodeTwo = new Node(2);
    Node* nodeFour = new Node(4);
    Node* nodeFive = new Node(5);

    Node* head = nodeZero;
    nodeZero->next = nodeOne;
    nodeOne->next = nodeTwo;
    nodeTwo->next = nodeFour;
    nodeFour->next = nodeFive;

    traverse(head);

    // Insertion in the middle
    Node* nodeThree = new Node(3);
    head = insertion(head, nodeThree, 2);
    std::cout << "\nInserted 3 at index 2\n";
    traverse(head);

    // Insertion at the beginning
    Node* newElem1 = new Node(-1);
    head = insertion(head, newElem1);
    std::cout << "\nInserted -1 at the beginning\n";
    traverse(head);

    
    // Insertion at the end
    Node* newElem2 = new Node(6);
    head = insertion(head, newElem2, -1);
    std::cout << "\nInserted 6 at the end\n";
    traverse(head);

    head = deletion(head, 2);
    std::cout << "Element at position 2 is deleted\n";
    traverse(head);

    head = deletion(head);    
    std::cout << "Element at position 0 is deleted\n";
    traverse(head);

    head = deletion(head, -1);
    std::cout << "Element at the end of linked list is deleted\n";
    traverse(head);
}

// traverse through the whole linked list
void traverse(Node* head) {
    std::cout << "Current linked list: ";

    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ---> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}
// returns nothing 

// insert an element at a specific position (default at the beginning, -1 at the end)
Node* insertion(Node* head, Node* elem, int position) {
    if (position == 0) {
        elem->next = head;
        head = elem;
    }

    else if (position == -1) {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = elem;
    }

    else {
        Node* curr = head;
        for (int i=0; i < position; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = elem;
        elem->next = **temp;
    }
    
    return head;
}
// returns the head of the updated linked list

// deletes an element at a specific position 
Node* deletion(Node* head, int position) {
    Node* curr = head;
    Node* toDel = nullptr;

    if (position == 0) {
        toDel = head;
        head = head->next;
    }
    
    else if (position == -1) {
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        toDel = curr->next;
        curr->next = nullptr;
    }
    
    else {
        for (int i = 0; i < position-1; i++) {
            curr = curr->next;
        }
        toDel = curr->next;
        curr->next = curr->next->next;
    }

    delete toDel;
    std::cout << "\n" << toDel->data << " is going to be deleted" << std::endl;
    return head;
}
// returns the head of the updated linked list

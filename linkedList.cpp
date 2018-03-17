#include <iostream>


struct node {
	int data;
    node* next;
};

class linkedList {
private:
    node* head;
    node* tail;

public:
    linkedList() {
        head = NULL;
        tail = NULL;
    }
    void appendNode(int);
    void deleteNode(int);
    void displayList();
    void reverseList();
};

int main(int argc, char const *argv[]) {
	linkedList newList;

    newList.appendNode(1);
    newList.appendNode(2);
    newList.appendNode(3);
    newList.appendNode(4);
    newList.appendNode(5);
    newList.appendNode(6);
    newList.appendNode(7);
    newList.appendNode(8);

    std::cout << "linked list\n";
    std::cout << "-----------\n";
    newList.displayList();

    newList.reverseList();

    std::cout << "\nreversed list\n";
    std::cout << "-------------\n";
    newList.displayList();

    //newList.deleteNode(5);

    std::cout << "\nmodified list\n";
    std::cout << "-------------\n";
    //newList.displayList();

	return 0;
}

void linkedList::appendNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void linkedList::deleteNode(int data) {
    node* currentNode = new node;
    node* previousNode = new node;

    currentNode = head;
    previousNode = NULL;

    while(currentNode->data != data) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode == head) {
        head = currentNode->next;
        delete currentNode;
    }

    else if(currentNode == tail) {
        tail = previousNode;
        tail->next = NULL;
        delete currentNode;
    }

    else {
        previousNode->next = currentNode->next;
        delete currentNode;   
    }
    
}

void linkedList::displayList() {
    node* nodePtr = new node;
    nodePtr = head;

    while(nodePtr != NULL) {
        std::cout << nodePtr->data << std::endl;
        nodePtr = nodePtr->next;
    }
}

void linkedList::reverseList() {
    node* previousNode = new node;
    node* currentNode = new node;
    node* nextNode = new node;

    previousNode = NULL;
    currentNode = head;

    while(currentNode != NULL) {
        nextNode = currentNode->next;

        currentNode->next = previousNode;

        previousNode = currentNode;
        currentNode = nextNode;
    }

    node* tempNode = new node;

    tempNode = head;
    head = tail;
    tail = tempNode;
}
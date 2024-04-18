#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
    //TODO - Implementation
    if(nrLines<=0 || nrCols<=0){
        throw exception();
    }
    head= nullptr;
    lines=nrLines;
    cols=nrCols;
}

// best case: theta 1
// worst case: theta 1
// average case: theta 1
// general case: theta 1
int Matrix::nrLines() const {  //Returns the number of lines from the matrix
    //TODO - Implementation
    return lines;
}

// best case: theta 1
// worst case: theta 1
// average case: theta 1
// general case: theta 1
int Matrix::nrColumns() const {  //Returns the number of columns from the matrix
	//TODO - Implementation
    return cols;
}

// best case: theta 1
// worst case: theta n
// average case: O(n)
// general case: O(n)
TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
    if(i >= this->nrLines() || i < 0 || j  >= this->nrColumns() || j < 0){  //Checks if the given positions are outside the matrix or not and if they are throws an exception
        throw exception();
    }
    NodeSLL* current=head;
    while(current!= nullptr){                       // Checks the matrix node by node with linear search until the positon is found or it has iterated through all nodes.
        if(current->row==i && current->col==j){     // If a node is found it returns the value from the node, if not it means that the value of the element is 0 and returns NULLTELEM.
                return current->value;
        }
        current=current->next;
    }
    return NULL_TELEM;
}

// best case: theta 1
// worst case: theta n
// average case: O(n)
// general case: O(n)
TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
    if(i >= this->nrLines() || i < 0 || j  >= this->nrColumns() || j < 0){      //Checks if the given positions are outside the matrix or not and if they are throws an exception
        throw exception();
    }
    if(checkLexOrder() == false){        // Checks if the matrix is in lexicographical order, if not it sorts it in that order.
        orderInLex();
    }
    if(e==NULL_TELEM){                 // Checks if the element to be modified is NULLTELEM, if it is then that means that if there is a node on that position it needs to be removed
        NodeSLL* current=head;
        NodeSLL* previous=nullptr;
        while(current!= nullptr){                     // Searches through the matrix for the node at the given positions and if found checks if it is the head or not and deletes it and
            if(current->row==i && current->col==j){   // returns the old value. If a node is not found then it means that the element from that position is 0 and there is nothing more
                TElem old=current->value;             // to do and returns NULLTELEM.
                if(previous== nullptr){
                    head=current->next;
                }
                else{
                    previous->next=current->next;
                }
                delete current;
                return old;
            }
            previous=current;
            current=current->next;
        }
        return NULL_TELEM;
    }
    NodeSLL* current=head;       // If the new value is different from 0, than it searches through the matrix and if it finds the node changes the value and returns the old value.
    NodeSLL* previous=nullptr;
    while(current != nullptr && (current->row<i || (current->row == i && current->col < j))){
        previous=current;
        current=current->next;
    }
    if(current != nullptr && current->row==i && current->col==j){
        TElem old=current->value;
        current->value=e;
        return old;
    }
    NodeSLL* newNode=new NodeSLL;       // If it doesn't find the position than it creates a new node before the current node and links it up with the rest of the list.
    newNode->row=i;
    newNode->col=j;
    newNode->value=e;
    newNode->next=current;
    if(previous== nullptr){         // Checks if the node will be the new head of the matrix or not and preforms a final lexicographical verification.
        head=newNode;
    }
    else{
        previous->next=newNode;
    }
    if(checkLexOrder()== false){
       orderInLex();
    }
    return NULL_TELEM;
}

// best case: theta 1
// worst case: theta n
// average case: O(n)
// general case: O(n)
bool Matrix::checkLexOrder() {
    NodeSLL* current=head;      // Checks if the matrix is in lexicographical order and returns true if it is.
    while(current!= nullptr && current->next!= nullptr){
        if(current->row>current->next->row || (current->row==current->next->row && current->col>current->next->col)){
            return false;
        }
        current=current->next;
    }
    return true;
}

// best case: theta 1
// worst case: theta n
// average case: O(n)
// general case: O(n)
void Matrix::orderInLex() {
        NodeSLL* sorted = nullptr;         // Initialize new sorted matrix.
        NodeSLL* current = head;
        while (current != nullptr) {
            NodeSLL* nextNode = current->next;
            // Insert current node into sorted list
            if (sorted == nullptr || sorted->row > current->row || (sorted->row == current->row && sorted->col > current->col)) {   // Checks if current node should be inserted at the beginning

                current->next = sorted;
                sorted = current;               // Update sorted to point to the newly inserted node
            } else {                           // Checks through the sorted matrix for the correct position to put the current node.
                NodeSLL* prevSorted = sorted;
                while (prevSorted->next != nullptr && (prevSorted->next->row < current->row || (prevSorted->next->row == current->row && prevSorted->next->col < current->col))) {
                    prevSorted = prevSorted->next;
                }
                current->next = prevSorted->next;
                prevSorted->next = current;
            }
            // Move to the next node in the original list
            current = nextNode;
        }
        // Update head to point to the first element of the sorted list
        head = sorted;
}

// best case: theta n
// worst case: theta n
// average case: theta n
// general case: theta n
Matrix::~Matrix() {
	//TODO - Implementation
    NodeSLL* current=head;
    while(current!= nullptr){
        NodeSLL* nextNode=current->next;
        delete current;
        current=nextNode;
    }
}



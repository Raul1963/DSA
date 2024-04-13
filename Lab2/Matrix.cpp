#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
    //TODO - Implementation
    if(nrLines<=0 || nrCols<=0){
        throw exception();
    }
    head= nullptr;
//    for(int i=nrLines-1;i>=0;i--){
//        for(int j=nrCols-1;j>=0;j--){
//            NodeSLL* newNode= new NodeSLL;
//            newNode->row=i;
//            newNode->col=j;
//            newNode->value=NULL_TELEM;
//            newNode->next= head;
//            head= newNode;
//        }
//    }
    NodeSLL* tail = nullptr; // Pointer to the last node
    for(int i = 0; i < nrLines; i++) { // Start from the first row
        for (int j = 0; j < nrCols; j++) { // Start from the first column
            NodeSLL *newNode = new NodeSLL;
            newNode->row = i;
            newNode->col = j;
            newNode->value = NULL_TELEM; // Default value for TElem
            newNode->next = nullptr;

            if (head == nullptr) { // If the list is empty
                head = newNode;
                tail = newNode; // Update tail to point to the new node
            } else {
                tail->next = newNode; // Append newNode after the current last node
                tail = newNode; // Update tail to point to the new last node
            }
        }
    }
}


int Matrix::nrLines() const {
    //TODO - Implementation
    int lines=0;
    NodeSLL* current=head;
    int lastRow=-1;
    while(current!= nullptr){
        if(current->row!=lastRow){
            lines++;
            lastRow=current->row;
        }
        current=current->next;
    }
	return lines;
}


int Matrix::nrColumns() const {
	//TODO - Implementation
    int cols=0;
    NodeSLL* current=head;
    int lastCol=-1;
    while(current != nullptr){
        if(current->col!=lastCol && current->row==0){
            cols++;
            lastCol=current->col;
        }
        current=current->next;
    }
    return cols;
}


TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
    NodeSLL* current=head;
    if(i >= this->nrLines() || i < 0 || j  >= this->nrColumns() || j < 0){
        throw exception();
    }
    while(current!= nullptr){
        if(current->row==i && current->col==j){
//            if(current->value==NULL_TELEM)
//            return NULL_TELEM;
//            else{
                return current->value;
//            }
        }
        current=current->next;
    }
}

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
    NodeSLL* current=head;
    if(i >= this->nrLines() || i < 0 || j  >= this->nrColumns() || j < 0){
        throw exception();
    }
    while(current!= nullptr){
        if(current->row==i && current->col==j){
            TElem temp=current->value;
            current->value=e;
            return temp;
        }
        current=current->next;
    }
}

Matrix::~Matrix() {
	//TODO - Implementation
    NodeSLL* current=head;
    while(current){
        NodeSLL* nextNode=current->next;
        delete current;
        current=nextNode;
    }
    delete current;
}



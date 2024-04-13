#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"

IndexedList::IndexedList() {
    //TODO - Implementation
    this->cap=2;
    this->nodes=new DLLANode[this->cap];
    for(int i=0; i<this->cap;i++){
        this->nodes[i].info=NULL_TELEM;
        this->nodes[i].next=NULL_TELEM;
        this->nodes[i].prev=NULL_TELEM;
    }
    this->firstEmpty=-1;
    this->head=-1;
    this->tail=-1;
    this->length=0;
}

int IndexedList::size() const {
    //TODO - Implementation
	return this->length;
}


bool IndexedList::isEmpty() const {
    //TODO - Implementation
    if(this->length!=0){
        return false;
    }
	return true;
}

TElem IndexedList::getElement(int pos) const {
    //TODO - Implementation
	return NULL_TELEM;
}

TElem IndexedList::setElement(int pos, TElem e) {
    //TODO - Implementation
	return NULL_TELEM;
}

void IndexedList::addToEnd(TElem e) {
    //TODO - Implementation
}

void IndexedList::addToPosition(int pos, TElem e) {
    //TODO - Implementation
}

TElem IndexedList::remove(int pos) {
    //TODO - Implementation
	return NULL_TELEM;
}

int IndexedList::search(TElem e) const{
    //TODO - Implementation
	return 0;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	//TODO - Implementation
//    for(int i=0;i<this->length;i++){
//        delete[] nodes;
//    }
    delete[] nodes;
}
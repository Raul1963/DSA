#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

ListIterator::ListIterator(const IndexedList& list) : list(list){
   //TODO - Implementation
   this->currentElem=this->list.head;
}

void ListIterator::first(){
    //TODO - Implementation
}

void ListIterator::next(){
    //TODO - Implementation
}

bool ListIterator::valid() const{
    //TODO - Implementation
	return false;
}

TElem ListIterator::getCurrent() const{
   //TODO - Implementation
	return NULL_TELEM;
}
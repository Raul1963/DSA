#include "SortedSetIterator.h"
#include <exception>
#include <iostream>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//TODO - Implementation
    this->index=0;
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
void SortedSetIterator::first() {
	//TODO - Implementation
    this->index=0; // Verschiebt den Iterator auf der ersten Stelle.
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
void SortedSetIterator::next() {
	//TODO - Implementation
    if(this->index<this->multime.len){ // Verschiebt den Iterator auf der nachste Position, wenn es nicht am Ende des Sets ist.
        this->index++;
    }
    else{
        throw exception();
    }
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
    if(this->index<this->multime.len){  // Gibt den Element auf welche Postion der Iterator steht, nur wenn der Index nicht ausserhalb der Lange des Sets ist.
        return this->multime.elements[this->index];
    }
    else{
        throw exception();
    }
}
// best case: theta(1)
// worst case: theta(n)
// average case: O(n)
// general case: O(n)
void SortedSetIterator::modifyCurrent(TComp newElem) {
    if(this->index<this->multime.len){                  //Uberpruft ob der Iterator am Ende des Sets ist und wenn ja gibt ein exception zuruck
        this->multime.elements[this->index]=newElem;
    }
    else{
        throw exception();
    }
    TComp obj=newElem;
    TComp temp;
    int i=this->index;
    while(i<this->multime.len && !multime.relation(newElem,multime.elements[i+1]) ){   // Uberpruft ob der modifizierte Element nicht in Relation mit nachsten Element und wenn nicht tasuchen sie die Platze um
        temp = multime.elements[i+1];
        multime.elements[i+1] = obj;
        obj = temp;
        i++;
    }
    while(i>0 && !this->multime.relation(multime.elements[i-1],newElem)){ // Uberpruft ob der modifizierte Element nicht in Relation mit der vorigen Element und wenn nicht tasuchen sie die Platze um
        temp = multime.elements[i-1];
        multime.elements[i-1] = obj;
        obj = temp;
        i--;
    }
//    if(multime.relation(multime.elements[multime.len-1],newElem)){
//
//    }
//
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
bool SortedSetIterator::valid() const {
	//TODO - Implementation
    if(this->index<this->multime.len){ //Uberpruft ob der Index innerhalb der Lange des Sets ist.
        return true;
    }
	return false;
}


#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    //TODO - Implementation
    this->relation=r;
    this->cap=1;
    this->len=0;
    this->elements=new TComp[this->cap];
}

//best case: theta(1)
//worst case: theta(n)
//average case: O(n)
//general case: O(n)
bool SortedSet::add(TComp elem) {
        //TODO - Implementation
    if (this->len == 0) {        // Uberpruft ob der Set leer ist, und wenn ja, dann fugt den Element hinzu.
        this->elements[0] = elem;
        this->len++;
        return true;
    }
    for(int i=0;i<this->len;i++){   // Uberpruft ob der Element schon in Set ist.
        if(this->elements[i]==elem){
            return false;
        }
    }
    if(this->size()==this->cap){ // Uberpruft ob das Nummer der Elemente von dem Set gleich der Kapazitat ist und wenn ja dann wird ein resize up durchgefuhrt.
        resizeUp();
    }
    TComp obj;
    TComp temp;
    if(this->len==1){                                // Uberpruft ob der Set nur ein Element ist, und wenn ja, dann uberpruft man den Element von den Set mit der Relation,
        if(!this->relation(this->elements[0],elem)){ // um zu wissen, wo man es tun soll.
            obj = this->elements[0];
            this->elements[0] = elem;
            this->elements[1]=obj;
            this->len++;
            return true;
        }
        else{
            this->elements[1]=elem;
            this->len++;
            return true;
        }
    }
    if(!this->relation(this->elements[0],elem)){ // Uberpruft ob der Element am erster Stelle vom Set hinzugefugt sein soll.
        obj = this->elements[0];
        this->elements[0] = elem;
        for (int j = 1; j < (this->len)+1; j++) {
            temp = this->elements[j];
            this->elements[j] = obj;
            obj = temp;
        }
        this->len++;
        return true;
    }
        int start=0,final=this->len-1,found=NULL_TELEM;                                  // Mit der binaren Suche wird  die Mitte vom Set mit dem vorherigen Element verglichen.
        while (start <= final) {
            int mid = start + (final - start) / 2;
            if (!this->relation(this->elements[mid], elem)&& this->relation(this->elements[mid-1],elem)) {
                found=mid;
                break;
            }
            if (this->relation(this->elements[mid], elem)) {
                start = mid + 1;
            }
            else {
                final = mid - 1;
            }
        }
        if(found!=NULL_TELEM){
            obj = this->elements[found];
            this->elements[found] = elem;
            for (int j = found + 1; j < (this->len)+1; j++) {
                temp = this->elements[j];
                this->elements[j] = obj;
                obj = temp;
            }
            this->len++;
            return true;
        }
    this->elements[this->len] = elem;
    this->len++;
    return true;
}

//best case: theta(1)
//worst case: theta(n)
//average case: O(n)
//general case: O(n)
bool SortedSet::remove(TComp elem) {
    //TODO - Implementation
    int start = 0, final = this->len - 1, found=NULL_TELEM;     // Uberpruft mit binaren Suche ob der Element eigentlich in der Set existiert und
    while (start <=final) {                                     // wenn ja, loscht man den Element und verschiebt die Elemente von rechts der gesuchten Element
        int mid = start + (final - start) / 2;                  // eine Position nach links und die Lange der Set wird mit 1 versenkt.
        if (this->elements[mid] == elem) {
            found = mid;
            break;
        }
        if (this->relation(this->elements[mid], elem)) {
            start = mid + 1;
        } else {
            final = mid - 1;
        }
    }
    if(found!=NULL_TELEM) {
        for (int i = found; i < this->len-1; i++) {
            this->elements[i] = this->elements[i + 1];
        }
        this->len--;
        if (this->len == (1 / 4) * this->cap) {
            resizeDown();
        }
        return true;
    }
    return false;

}


//best case: theta(1)
//worst case: theta(log(n))
//average case: theta(log(n))
//general case: O(log(n))
bool SortedSet::search(TComp elem) const {
	//TODO - Implementation

    int start = 0, final = this->len - 1;     //Sucht nach einem Element im Set und wird mit falsch gewertet, wenn das Element nicht gibt.
    while (start <=final) {
        int mid = start + (final - start) / 2;
        if (this->elements[mid] == elem) {
            return true;
        }
        if (this->relation(this->elements[mid], elem)) {
            start = mid + 1;
        } else {
            final = mid - 1;
        }
    }
    return false;
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
int SortedSet::size() const {
	//TODO - Implementation
	return this->len; // Gibt die Anzahl der Elemente aus dem Set zuruck
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
bool SortedSet::isEmpty() const {
	//TODO - Implementation
    if(this->len==0){ // Uberpruft ob das Set keine Elemente hat
        return true;
    }
	return false;
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this); //Gibt ein Iterator fur den Set zuruck
}

//best case: theta(n)
//worst case: theta(n)
//average case: theta(n)
//general case: theta(n)
void SortedSet::resizeUp() {
    int newCap=this->cap*2;             // Verdoppelt die Kapazitat des Sets, indem man das aktuelle Set in ein neues Set kopiert
    auto *newElems=new TComp[newCap];   //und der Alte loscht und nachher das Neue in das Alte wieder kopiert
    for(int i=0;i<this->len;i++){
        newElems[i]=this->elements[i];
    }
    delete[] this->elements;
    this->elements=newElems;
    this->cap=newCap;
}

//best case: theta(n)
//worst case: theta(n)
//average case: theta(n)
//general case: theta(n)
void SortedSet::resizeDown() {
    int newCap=this->cap/2;             // Halbiert die Kapazitat des Sets, indem man das aktuelle Set in ein neues Set kopiert
    auto *newElems=new TComp[newCap];   // und der Alte loscht und nachher das Neue in das Alte wieder kopiert
    for(int i=0;i<this->len;i++){
        newElems[i]=this->elements[i];
    }
    delete[] this->elements;
    this->elements=newElems;
    this->cap=newCap;
}

//best case: theta(1)
//worst case: theta(1)
//average case: theta(1)
//general case: theta(1)
SortedSet::~SortedSet() {
	//TODO - Implementation
    delete[] this->elements;
}
#include "LLQueue.h"


void LLQueue::enqueue(int el){ //all queue insertions take place at tail (FIFO)
			lst.addToTail(el);
}


int LLQueue::dequeue(){ //all queue deletions take place at head (FIFO)
			return lst.deleteFromHead();
}


int LLQueue::firstEl() { //reads from front of queue w/out changing queue contents
			int front_el;
			front_el=lst.deleteFromHead();
			lst.addToHead(front_el);
			return front_el;
}


void LLQueue::clear() {
			while(!lst.isEmpty()){
				lst.deleteFromHead();
			}
}


#ifndef LL_QUEUE
#define LL_QUEUE
#include "intDLList.h"

class LLQueue
{
	public:
		LLQueue(){};

		bool isEmpty() { 
			return (lst.isEmpty());}

		void enqueue(int el); //all queue insertions take place at tail (FIFO)
			

		int dequeue(); //all queue deletions take place at head (FIFO)


		int firstEl(); //reads from front of queue w/out changing queue contents

		void clear();

		void printqueue() {lst.printlist();}
		
		~LLQueue() {clear();}

	private:
		IntDLList lst; //Declare list object for use as stack
};

#endif
			
			
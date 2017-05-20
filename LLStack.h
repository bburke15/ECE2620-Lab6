#ifndef LL_STACK
#define LL_STACK
#include "intDLList.h"

class LLStack
{
	public:
		LLStack(){}; //empty constructor

		bool isEmpty() {return lst.isEmpty();}

		void clear();

		int pop(); //pop element from stack
			
		void push(const int& el);//push element onto stack

		int topEl(); //Read from top of stack and leave state of stack unchanged
			
		~LLStack() {clear();} //Destroy stack when done

		void printstack() {lst.printlist();}

	private:
		IntDLList lst; //Declare/create a list; use as stack
};

#endif
		

		
			
			
		
		
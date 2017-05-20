#include "LLStack.h"

void LLStack::clear() {
			while(!lst.isEmpty()){
				lst.deleteFromHead();}
		}

void LLStack::push(const int& el) { //push element onto stack
			lst.addToHead(el);}

int LLStack::pop() { //pop element from stack
			return (lst.deleteFromHead());}

int LLStack::topEl() { //Read from top of stack and leave state of stack unchanged
			int topelement;
			topelement = lst.deleteFromHead(); //read and delete
			lst.addToHead(topelement); //undo delete
			return(topelement);
		}


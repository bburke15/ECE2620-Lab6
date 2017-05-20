//NULL already defined as 0
#include "intDLLNode.h"
#ifndef _INT_DL_LIST_H_
#define _INT_DL_LIST_H_


class IntDLList
{

public:
IntDLList() {head=tail=NULL;} //default constructor
	
~IntDLList(); //destructor

void addSorted(int i); //insert an integer element in sorted order w/in list

void printlist(); //print all integer elements from list in order
	
int isEmpty() {return (head == NULL);} //determine if list is empty

void addToHead(int); //add integer element to head of list

void addToTail(int); //add integer element to tail of list

int deleteFromHead();
//delete head and return its info

int deleteFromTail();
//delete tail and return its info

void deleteNode(int); //search for integer in list and, if found, delete it

bool isInList(int); //find integer in list

protected:

private:
const int EMPTY_LIST=1;

IntDLLNode *head, *tail; //head and tail pointers
};

#endif // _INT_DL_LIST_H_


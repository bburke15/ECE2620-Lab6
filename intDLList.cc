#include "intDLList.h"
#include <iostream>
using namespace std;

void IntDLList::addSorted(int i) {
	IntDLLNode *tmp=head;
	IntDLLNode *b=new IntDLLNode(i);
	if(!isEmpty()){ //non-empty list

		if(i<tmp->info){ //element to be inserted is less than head->info; insert new node at head
			addToHead(i);
		}
		else if(i>tail->info){ //element is greater than tail->info; insert new node at tail 
			addToTail(i);
		}
		//element is somewhere in the middle of the list
		for(tmp=head;tmp!=tail;tmp=tmp->next) //advance pointer
		{
			if(i>tmp->info && i<tmp->next->info)
			{
				b->prev=tmp;
				b->next=tmp->next;
				tmp->next=b;
				tmp->next->prev=b;
			}
		}
	}
	else //list is empty, so add a new node intialized with element i in its info field
	{ 
		head=tail=b;
	}
}

void IntDLList::printlist() { //print integer elements of list in order
	if(!isEmpty()){
		IntDLLNode *tmp=head;
		for(;tmp!=NULL;tmp=tmp->next){ //advance pointer
		cout << tmp->info << endl; //print integer element
		}
	}
}

IntDLList::~IntDLList() { //destructor
	for(IntDLLNode *p; !isEmpty(); head=p) {
		p=head->next;
		delete head;
	}
}

void IntDLList::addToHead(int el) { //add node of element el to head of list

	if(!isEmpty()) { //if list isn't empty, add new node of element el to head and set pointers accordingly
	head = new IntDLLNode(el,head,NULL);
	head->next->prev=head;
	}
	else{ //list is empty, just add new node of element el
	head =tail= new IntDLLNode(el);}
}

void IntDLList::addToTail(int el) { //add node with element el to tail of list
	if(tail!=NULL) { //if list is not empty, create new node and set pointers accordingly
		IntDLLNode *tmp=tail;
		tail=new IntDLLNode(el,NULL,tmp);
		tmp->next=tail;
	}
	else { //list is empty, so just add new node
		head=tail=new IntDLLNode(el);
	}
}

int IntDLList::deleteFromHead() { //delete node from head of list
	if(!isEmpty()) { //list is not empty 
		int el = head -> info; //catch element to return after deleting node
		IntDLLNode *tmp;
		if(head==tail){ //one node, delete head, set pointers to null
			delete head;
			head=tail=NULL;
		}
		else{ //more than one node in list, set pointers, and delete tmp (=old head) 
			tmp=head;
			head=tmp->next;
			head->prev=NULL;
			delete tmp;
		}
		return el;
	}
		else throw(EMPTY_LIST); //exception in case try to delete from empty list
}


int IntDLList::deleteFromTail() { //delete node from tail of list
	if(head!=NULL){ //if list is not empty
		int el = tail -> info; //catch element to return after deleting node
		if(head==tail){ //one node, delete tail, set pointers to null
			delete tail;
			head=tail=NULL;
		}
		else{ //more than one node, set pointers accordingly
			tail=tail -> prev;
			delete tail->next;
			tail->next=NULL;
		}
		return el;
	}
		else throw(EMPTY_LIST); //exception in case try to delete from empty list
}

void IntDLList::deleteNode(int el){ //search for element and list; if found, delete corresponding node
	if(!isEmpty()) 
	{
		if(head==tail && el==head->info) { //one item in list that contains element
			delete head;
			head=tail=NULL;
		}
		else if(el==head->info){ //more than one item in list; head contains element
			IntDLLNode *temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
		}	
		else //element is somewhere in middle of list
		{
			IntDLLNode *temp, *back;
			for(back=head, temp=head->next;temp!=NULL && temp->info!=el; back=back->next,temp=temp->next); //advance pointer
			if(temp!=NULL){
				back->next=temp->next;
			}
			if(temp==tail)
			{
				tail=back;
				delete temp;
			}
		}
	}
	else //list is empty
	{
		cout << "List is Empty" << endl;
	}
}
			

bool IntDLList::isInList(int el) {
	IntDLLNode *tmp;
	for(tmp=head; tmp!=NULL && tmp->info != el; tmp=tmp->next);
	return(tmp!=NULL);
}
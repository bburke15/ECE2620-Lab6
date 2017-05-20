#define NULL 0
#ifndef _INT_DLL_NODE_H_
#define _INT_DLL_NODE_H_

class IntDLLNode
{
friend class IntDLList;	

public:
IntDLLNode() {next=prev=NULL;}

const int EMPTY_LIST=1;

IntDLLNode(const int el, IntDLLNode *n=NULL, IntDLLNode *p=NULL){ //constructor of type "C"
	info=el;
	next=n;
	prev=p;
}

protected:


int info;

IntDLLNode *next, *prev;

};

#endif // _INT_DLL_NODE_H_


//Brendan Burke
//ECE 2620
//Lab 6
#include <iostream>
#include "LLStack.h"
#include "intDLList.h"
#include "LLQueue.h"

using namespace std;

void menu() {
	cout << "(1) Create Simple (Unsorted) List" << endl;
	cout << "(2) Create Sorted List" << endl;
	cout << "(3) Create Queue (FIFO)" << endl;
	cout << "(4) Create Stack (LIFO)" << endl;
	cout << "(5) Exit program" << endl;
} //Menu function outputs text for the five options to the screen

void menu1() {
	cout << "(1) Enter integer for insertion at head of list" << endl;
	cout << "(2) Enter integer for insertion at tail of list" << endl;
	cout << "(3) Display and delete integer from head of list" << endl;
	cout << "(4) Display and delete integer from tail of list" << endl;
	cout << "(5) Search for integer in list, and delete that node" << endl;
	cout << "(6) Display contents of list from head to tail, in order" <<endl;
	cout << "(7) Exit program" << endl;
} /*Menu function outputs text for the seven options to the screen if option 1
 * is selected*/

void menu2() {
	cout << "(1) Enter integer for sorted insertion (increasing order) into list" << endl;
	cout << "(2) Search and delete integer, if present in list" << endl;
	cout << "(3) Display contents of sorted list of integers, in increasing order" << endl;
	cout << "(4) Exit  Program" << endl;
} //Menu function outputs text for the 4 options to screen if option 2 selected

void menu3() {
	cout << "(1) ENQUEUE (Enter integer for insertion into queue)" << endl;
	cout << "(2) DEQUEUE (Display and delete integer from queue)" << endl;
	cout << "(3) PRINT QUEUE (Display queue contents without deleting anything, first element first)" << endl;
	cout << "(4) Exit program" << endl;
} //Menu function outputs text for the 4 options to screen if option 3 selected

void menu4() {
	cout << "(1) PUSH (Enter integer for insertion into stack)" << endl;
	cout << "(2) POP (Display integer and delete it from stack)" << endl;
	cout << "(3) PRINT STACK (Display stack contents without deleting anything, last element first" << endl;
	cout << "(4) Exit program" << endl;
} //Menu function outputs text for the five options to the screen

int main()
{
	int option; //declare variable
	menu(); //user is prompted with menu options printed to screen
	cout << "Select an operation: ";
	cin >> option; //user inputs an option
	while(option != 5){

		switch (option) {		

			case 1: //if option 1, create unsorted list and provided new option set
			{IntDLList my_list;
			int option1a;
			menu1();
			cout << "Select an operation: ";
			cin >> option1a;
			while(option1a != 7) {

				switch(option1a) {

					case 1:
						int el;
						cout << "Enter integer for insertion at head: ";
						cin >> el;
						my_list.addToHead(el);
						break;
					case 2:
						int el2;
						cout << "Enter integer for insertion at tail: ";
						cin >> el2;
						my_list.addToTail(el2);
						break;
					case 3:
						try { //try catch clause to catch thrown exception
							int val = my_list.deleteFromHead();
							cout << val << endl;
						}
						catch(int error_code){
							cerr << "Error: " << error_code << endl;
							switch(error_code){
							cout << "Error" << endl;}
						}
						break;
					case 4:
						try {
							int val2 = my_list.deleteFromTail();
							cout << val2 << endl;
						}
						catch(int error_code){
							cerr << "Error: " << error_code << endl;
							switch(error_code){
								cout << "Error" << endl;
							}
						}
						break;
					case 5:
						int el_find;
						cout << "Enter integer to search for in list, and delete corresponding node: ";
						cin >> el_find;
						my_list.deleteNode(el_find);
						break;
					case 6:
						my_list.printlist();
						break;
					case 7:
						break;
				}
				menu1();
				cout << "Select an operation: ";
				cin >> option1a;
			}
				break;
			}

			case 2: //if option 2, created sorted list and provide new option set
			{IntDLList my_list1;
			int option1b;
			menu2();
			cout << "Select an operation: ";
			cin >> option1b;
			while(option1b != 4) {

				switch(option1b) {

					case 1:
						int el_sort;
						cout << "Enter integer for sorted insertion (increasing) into list: ";
						cin >> el_sort;
						my_list1.addSorted(el_sort);
						break;
					case 2:
						int el_delete;
						cout << "Enter integer to be deleted in list: ";
						cin >> el_delete;
						my_list1.deleteNode(el_delete);
						break;
					case 3:
						my_list1.printlist();
					case 4:
						break;
				}
				menu2();
				cout << "Select an operation: ";
				cin >> option1b;
			}
				break;
			}

			case 3: //if option 3, create queue and provide new option set
			{LLQueue my_queue;
			int option1c;
			menu3();
			cout << "Select an operation: ";
			cin >> option1c;
			while(option1c != 4) {

				switch(option1c) {
					case 1:
						int el_q;
						cout << "Enter integer for insertion into queue: ";
						cin >> el_q;
						my_queue.enqueue(el_q);
						break;
					case 2:
						try {
							int val3 = my_queue.dequeue();
							cout << val3 << endl;
						}
						catch(int error_code){
							cerr << "Error: " << error_code << endl;
							switch(error_code){
								cout << "Error" << endl;
							}
						}
						break;
					case 3:
						my_queue.printqueue();
					case 4:
						break;
				}
				menu3();
				cout << "Select an operation: ";
				cin >> option1c;
			}
				break;
			}
			
			case 4: //if option 4, create stack and provide new option set
			{LLStack my_stack;
			int option1d;
			menu4();
			cout << "Select an operation: ";
			cin >> option1d;
			while(option1d != 4) {

				switch(option1d) {
					case 1:
						int el_s;
						cout << "Enter integer for insertion into stack: ";
						cin >> el_s;
						my_stack.push(el_s);
						break;
					case 2:
						try {
							int val4 = my_stack.pop();
							cout << val4 << endl;
						}
						catch(int error_code){
							cerr << "Error: " << error_code << endl;
							switch(error_code){
								cout << "Error" << endl;
							}
						}
						break;
					case 3:
						my_stack.printstack();
						break;
					case 4:
						break;
				}
				menu4();
				cout << "Select an operation: ";
				cin >> option1d;
			}
				break;
			}
			case 5: //exit
				break;

			
			default: //try again with a valid numerical input
				cout << "Not Valid" << endl;
			break;
		}
		menu(); //print menu options again
		cout << "Select an operation: ";
		cin >> option; //user inputs an option
	}
	return 0;
}

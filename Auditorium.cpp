/*
 * SSK190013
 * Saahit Karumuri
 *
 */

#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Auditorium.h"
#include "Seat.h"
#include "Node.h"
#include <bits/stdc++.h>

using namespace std;

template<class T>
Auditorium<T>::Auditorium(string &fileName) {
	const string fileName2 = "input.txt";
	head = (Node<Seat>*) malloc(sizeof(Node<Seat> ));
	//set the value of head to the first node
	//create new node to make the linked
	//Searchmethod that returns a node<seat>*
	// look for head and head had a null to right
	//if head is not null,
	//cout << "Before Reading File";
	ifstream file(fileName2);
	//cout << "After Reading File";
	string inputLine;
	int row = 1;
	auto prevLineStart = head;
	while (getline(file, inputLine)) {
		Node<Seat>* currLineStart = (Node<Seat>*) malloc(sizeof(Node<Seat>));
		Seat obj(row,1,inputLine[0]);
		currLineStart -> load = obj;
		prevLineStart -> down = currLineStart;
		prevLineStart = currLineStart;
		//createHead
		/*
		if (headM == 0) {
			char headC = line1[0];
			Seat s(1, 1, headC);
			head -> load = s;
			headM++;
			cout << head ->load.getRow() << " " << head -> load.getCol() << " " ;
		}
		*/
		//
		Node<Seat> *currSeat = currLineStart;
		for (long unsigned int col = 1; col < inputLine.length(); col++) {
			Node<Seat> *nextSeat = (Node<Seat>*) malloc(sizeof(Node<Seat> ));
			char seat = inputLine[col];
			Seat data(row, col+1, seat);
			//
			nextSeat -> load = data;
			currSeat -> right = nextSeat;
			currSeat = nextSeat;
		}
		row++;
	}
	//head = head -> down;
	setHead(head);
	//
	rowCount = row-1;
	colCount = inputLine.length();
	//
}
//function used to create a new node, which is of node type containing a seat
/*
 template<class T>
 Node<T>* createN(char val) {
 Node<T> *temp = new Node<T>(val);
 temp  ->  load = &(val);
 return temp;
 }
 //
 template<class T>
 Node<T>* LL(string s, int row, int col, Node<T> val) {
 char vals[s.length()];
 Seat obj = new Seat(row, col, val.getload());
 strcpy(vals, s.c_str());
 int i = 0;
 Node<Seat> *temp = &obj;
 i++;
 temp  ->  setUp(&val);
 temp  ->  setLeft(&val);
 temp  ->  setRight(LL(s, row, col + 1, val));
 temp  ->  setDown(LL(s, row + 1, col, val));
 return temp;
 }

 //
 template<class T>
 Node<T>* createHead(string input) {
 Node<T> vals(NULL);
 return LL(input, 0, 0, vals);
 }
 //
 template<class T>
 void printAud(Node<T> *head) {
 Node<T> *r;
 Node<T> *d = head;
 while (d) {
 r = d;
 while (r) {
 std::cout << r  ->  data << " ";
 r = r  ->  next;
 }
 cout << "\n";
 d = d  ->  down;
 }
 }
 */

//
template<class T>
void Auditorium<T>::displayReport(Node<T> *begin) {
	Node<T> *tempHead = begin;
	Seat obj;
	int e = 0; // used for going down on rows
	obj = begin -> getload();
	int adult = 0, child = 0, senior = 0, totalTickets = 0, totalSeats = 0;
	double total = 0;
	//
	while (tempHead -> getDown() != nullptr) {
		while (tempHead -> getLeft() != nullptr) {
			if (obj.getTicketType() == 'A') {
				adult++;
				totalTickets++;
			}
			if (obj.getTicketType() == 'C') {
				child++;
				totalTickets++;
			}
			if (obj.getTicketType() == 'S') {
				senior++;
				totalTickets++;
			}
			totalSeats++;
			tempHead = tempHead -> getLeft();
			obj = tempHead -> getload();
		}
		//get down and change rows
		tempHead = begin;
		for (int i = 0; i < e; i++) {
			tempHead = tempHead -> getDown();
		}
		e++;
	}
	//
	total = (adult * 10) + (child * 5) + (senior * 7.5);
	//
	cout << "Total Seats:\t" << totalSeats << endl;
	cout << "Total Tickets:\t" << (adult + child + senior) << endl;
	cout << "Adult Tickets:\t" << adult << endl;
	cout << "Child Tickets:\t" << child << endl;
	cout << "Senior Tickets:\t" << senior << endl;
	cout << "Total Sales:\t$";
	printf("%.2f", total);
}

template class Auditorium<Seat>::Auditorium<Seat>;

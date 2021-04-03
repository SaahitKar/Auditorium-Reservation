/*
 * SSK190013
 * Saahit Karumuri
 *
 */
#ifndef AUDITORIUM_H_
#define AUDITORIUM_H_

#include <string>
#include "Node.h"
#include "Seat.h"

template<class T> class Auditorium {
public:
	Node<T> *head;
	void setHead(Node<T> *h) {
		head = h;
	}
	Node<T>* getHead() {
		return head;
	}
	//
	int rowCount;
	int getRow() {
		return rowCount;
	}
	int colCount;
	int getCol() {
		return colCount;
	}
	double checkAvailability(Node<T> *start, int numOfSeats);
	void displayReport(Node<T> *begin);
	//
	Node<T>* getBestSeatAvailable(int numOfSeats);
	//
	Auditorium<T>(std::string &filename);
	//Node<T>* LL(Seat&);
	Seat InsertAfter(Seat*);
	Node<T>* createN(T);
	Node<T>* createHead();
};

/*
 template <class T>
 Auditorium<T>::Auditorium(int a) {
 next = nullptr;
 head = nullptr;
 tail = nullptr;
 }
 */
/*

 template <class T>
 Node<T>* Auditorium<T>::createN(T val) {
 Node<T>* temp = new Node<T>(val);
 temp -> load = (val);
 std::cout << temp -> load;
 return temp;
 }

 template <class T>
 Node<T>* Auditorium<T>::createHead() {
 Node<T>* vals = new Node<T>(NULL);
 head = vals;
 std::cout << head -> load;
 return vals;
 }
 */
//
/*
 template <class T>
 Node<T>* Auditorium<T>::LL( Seat& s) {
 //Seat s2(s.getRow(), s.getCol(), s.getTicketType());
 Node<Seat>* curr = new Node<Seat>{s};
 //temp -> setLeft(NULL);
 //
 if(head == NULL) {
 head = curr;
 tail = curr;
 } else {
 tail -> setLeft(curr);
 tail = curr;
 }
 }
 */
/*
 Get Best Seat Available

 template<class T>
 Node<T>* Auditorium<T>::getBestSeatAvailable(int numOfSeats) {
 Node<T> *start = head;
 Node<T> *rowStart = head;
 double lowestAvgDistance = -1;
 int rowOfLowestAvgDistance = -1;
 auto *res = (Node<Seat>*) malloc(sizeof(Node<Seat> ));
 for (int i = 0; i < rowCount; i++) {
 for (int j = 0; j < colCount; j++) {
 double avgDistance = checkAvailability(start, numOfSeats);
 if (avgDistance != -1) {
 if (lowestAvgDistance == avgDistance) {
 if (abs(rowOfLowestAvgDistance - (rowCount - 1) / 2.0)
 > abs(start -> load.row - (rowCount - 1) / 2.0)) {
 rowOfLowestAvgDistance = start -> load.row;
 res = start;
 }
 if (abs(rowOfLowestAvgDistance - (rowCount - 1) / 2.0)
 == abs(start -> load.row - (rowCount - 1) / 2.0)) {
 if (start -> load.row < rowOfLowestAvgDistance) {
 res = start;
 }
 rowOfLowestAvgDistance = min(start -> load.row,
 rowOfLowestAvgDistance);
 }
 }
 if (lowestAvgDistance > avgDistance
 || lowestAvgDistance == -1) {
 lowestAvgDistance = avgDistance;
 rowOfLowestAvgDistance = start -> load.row;
 res = start;
 }
 }
 start = start -> right;
 }
 rowStart = rowStart -> down;
 start = rowStart;
 }
 return res;
 }
 */
//
/*
 template<class T> class Auditorium {
 public:
 Node<T> *head;
 Auditorium<T>();
 Auditorium<T>(Node<T>*): head(head){};

 };
 */
/*
 template <class T>
 Node<T>* Auditorium<T>::LL(std::string s, int row, int col, Node<T> val) {
 char vals[s.length()];
 strcpy(vals, s.c_str());
 std::cout << s.length();

 int i = 0;
 Node<T>* temp = createN((vals[i]));
 i++;

 //temp -> setUp(&val);
 temp -> setLeft(&val);
 //temp -> setRight(LL(s, row, col+1, val));
 //temp -> setDown(LL(s, row+1, col, val));

 return temp;
 }
 //
 */
/*
 template <class T>
 void printAud(Node<T>* head)
 {
 Node<T>* r;
 Node<T>* d = head;
 while (d) {
 r = d;
 while (r) {
 std::cout << r->data << " ";
 r = r->next;
 }

 std::cout << "\n";
 d = d->down;
 }
 } */

/*


 */
#endif /* AUDITORIUM_H_ */

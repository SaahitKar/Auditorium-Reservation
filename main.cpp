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
#include <limits>
#include "Auditorium.h"
#include "Seat.h"
#include "Node.h"

using namespace std;

bool checkAvailability(Auditorium<Seat> auditorium, int row, int num, int i);
void displayAud(Auditorium<Seat> aud);
void reserve(Auditorium<Seat> auditorium, int row, int num, int adult,
		int child, int senior);

int main() {
	string inputF = "input.txt";
	cout << "Enter File Name >>> " << endl;
	//cin >> inputF;
	Auditorium<Seat> aud(inputF);
	Node<Seat> *headT = aud.getHead();
	int option = 1;
	int rowC = 0;
	char let = ' ';
	int colNumber = 1;
	int adultT = 0;
	int childT = 0;
	int seniorT = 0;
	int totalTickets = 0;
	int bseatNum = 0;
	int i;
	int rowNum = aud.getRow();
	int colNum = aud.getCol();
	//
	while (option == 1) {
		//
		if (option == 2) {
			break;
		}
		//
		if (option == 1) {
			char colNum[26];
			colNum[0] = 'A';
			int v = 65;
			cout << "  ";
			for (int i = 0; i < aud.getCol(); i++) {
				colNum[i] = (char) v;
				v++;
				cout << colNum[i];
			}
			cout << endl;
			displayAud(aud);
			//
			do {
				cout << "Main Menu: " << endl << "1. Reserve Seats" << endl
						<< "2. Exit" << endl;
				cout << "Choose an option >>> " << endl;
				cin >> option;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Choose an option >>> " << endl;
					cin >> option;
					if (!cin.fail()) {
						break;
					}
				}
			} while (option != 1 && option != 2);
			//
			if (option == 2) {
				break;
			}
			//
			//cout << aud.head -> load.tType << aud.getRow() << " " << aud.getCol();
			i = 0;
			do {
				cout << "Enter row number >> ";
				cin >> rowC;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter row number >> ";
					cin >> rowC;
					if (!cin.fail()) {
						break;
					}
				}
			} while (rowC < 0 || rowC > rowNum);
			//
			do {
				cout << "Enter seat letter >> ";
				cin >> let;
				colNumber = (int) let - 97;
			} while (colNumber < 0 || colNumber > 25 || rowC > rowNum);
			//
			do {
				cout << "Enter number of adult >> ";
				cin >> adultT;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter number of adult >> ";
					cin >> adultT;
					if (!cin.fail()) {
						break;
					}
				}
			} while (adultT < 0);
			//
			do {
				cout << "Enter number of child >> ";
				cin >> childT;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter number of child >> ";
					cin >> childT;
					if (!cin.fail()) {
						break;
					}
				}
			} while (childT < 0);
			//
			do {
				cout << "Enter number of senior >> ";
				cin >> seniorT;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter number of senior >> ";
					cin >> seniorT;
					if (!cin.fail()) {
						break;
					}
				}
			} while (seniorT < 0);
			//
			bool checkAvail = checkAvailability(aud, rowC, colNumber,
					(adultT + seniorT + childT));
			cout << "Check Availability: ";
			if (checkAvail == true) {
				cout << "True" << endl;
			}
			if (checkAvail == false) {
				cout << "False" << endl;
			}
			if (checkAvail == true) {
				reserve(aud, rowC, let, adultT, childT, seniorT);
			} else {
				/*
				 cout << rowC << bestSeats << " - " << rowC << endSeat << endl;
				 cout << "Do you want to reserve(Y/N) >>> ";
				 cin >> bestSeatResponse;
				 */
			}
		}
		//Ticket Report
	}
	//
	displayAud(aud);
	aud.displayReport(headT);
	return 0;
}
//
bool checkAvailability(Auditorium<Seat> auditorium, int rows, int cols,
		int numSeats) {
	bool check = true;
	Node<Seat> *head = auditorium.head;
	cout << auditorium.head -> load.tType << "Row: " << auditorium.getRow() << " " << auditorium.getCol();
	for (int i = 0; i < rows; i++) {
		head = head -> down;
	}
	for (int i = 0; i < cols; i++) {
		head = head -> right;
	}
	//
	for (int i = 0; i < numSeats; i++) {
		if (head == nullptr || head -> load.tType != '.') {
			check = false;
		} else {
			check = true;
		}
		head = head -> right;
	}
	return check;
}
//
void displayAud(Auditorium<Seat> aud) {
	//
	Node<Seat> *rowStart = aud.head;
	Node<Seat> *rightptr = (Node<Seat>*) malloc(sizeof(Node<Seat>));
	int rowN = 1;
	//
	rowStart = rowStart -> getDown();
	while (rowStart != nullptr) {
		rightptr = rowStart;
		cout << rowN << " ";
		while (rightptr -> getRight() != nullptr) {
			cout << rightptr -> load.tType;
			rightptr = rightptr -> getRight();
		}
		cout << rightptr -> load.tType;
		cout << endl;
		//get down and change rows
		/*
		rowStart = aud.head;
		for (int i = 0; i <= rowN; i++) {
			rowStart = rowStart -> getDown();
		} */
		rowN++;
		rowStart = rowStart -> getDown();
	}
}
//
void reserve(Auditorium<Seat> aud, int row, int cols, int adult, int child,
		int senior) {
	Node<Seat> *headT = aud.head;
	Seat obj;
	for (int i = 0; i < row; i++) {
		headT = headT -> down;
	}
	for (int i = 0; i < cols; i++) {
		headT = headT -> right;
	}
	for (int i = 0; i < adult; i++) {
		obj = Seat(row, cols, 'A');
		cols += 1;
		headT -> load = obj;
		headT = headT -> right;
	}
	for (int i = 0; i < child; i++) {
		obj = Seat(row, cols, 'C');
		cols += 1;
		headT -> load = obj;
		headT = headT -> right;
	}
	for (int i = 0; i < senior; i++) {
		obj = Seat(row, cols, 'S');
		cols += 1;
		headT -> load = obj;
		headT = headT -> right;
	}
}

/*
 * SSK190013
 * Saahit Karumuri
 *
 */

#ifndef SEAT_H_
#define SEAT_H_

class Seat {
public:
    int row;
    int col;
    char tType;
    //Seat* next;
    //get and set for Row
    int getRow(){return row;}
    void setRow(int r){row = r;}
    //get and set for Column
    int getCol(){return col;}
    void setCol(int c){col = c;}
    //get and set for Ticket Type
    char getTicketType(){return tType;}
    void setTicketType(char t){tType = t;}
    //
    Seat(int r, int c, char tType);
    Seat() {
    	row = 0;
    	col = 0;
    	tType = ' ';
    }
};


#endif /* SEAT_H_ */

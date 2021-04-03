/*
 * SSK190013
 * Saahit Karumuri
 *
 */

#ifndef NODE_H_
#define NODE_H_

#include "Seat.h"

template <class T>
class Node {
public:
    Node* up;
    Node* down;
    Node* left;
    Node* right;
    T load;
    Node<T>(Node* up, Node* down, Node* left, Node* right, T load) : up(up), down(down), left(left), right(right), load(load) {}
    //
    Node<T>(T load) : load(load){}
    //
    Node* getUp(){return up;}
    void setUp(Node* u) { up = u;}
    //
    Node* getDown(){return down;}
    void setDown(Node* d) {down = d;}
    //
    Node* getLeft(){return left;}
    void setLeft(Node* l) {left = l;}
    //
    Node* getRight(){return right;}
    void setRight(Node *r) {right = r;}
    //
    T getload(){return load;}
    void setload(T l) {load = l;}
    //
};
#endif /* NODE_H_ */

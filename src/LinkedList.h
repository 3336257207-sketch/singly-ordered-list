#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* initList();
void insertOrdered(Node* head, int value);
bool deleteNode(Node* head, int value);
bool searchNode(Node* head, int value, int& pos);
int getLength(Node* head);
void destroyList(Node* head);
void displayList(Node* head);

#endif
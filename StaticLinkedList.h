/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:45
*@Version
*/

#ifndef LINKLIST_STATICLINKEDLIST_H
#define LINKLIST_STATICLINKEDLIST_H

#include "stdio.h"
#define MAXSIZE 100

typedef struct node {
    int data;
    int cursor;
}cursorSpace[MAXSIZE];
cursorSpace space;

static int cursorAlloc();
static void cursorFree(int p);
void initList();
void insertTailNode(int data);
void createList();
void insertNode();
void delNode();
void modifyNode();
void findData();
void findPosition();
void printList();
void project();

#endif //LINKLIST_STATICLINKEDLIST_H

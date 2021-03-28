//
// Created by Ð¡Õñ on 2021/3/2.
//

#ifndef LINKLIST_DOUBLELINKEDLIST_H
#define LINKLIST_DOUBLELINKEDLIST_H

#include "stdio.h"
#include "stdlib.h"

typedef struct dnode {
    struct dnode *pre;
    int data;
    struct dnode *next;
}DNode;

void initHeadD(DNode **head);
void insertTailNodeD(DNode *head, int data);
void createListD(DNode *head);
void insertNodeD(DNode *head);
void delNodeD(DNode *head);
void modifyNodeD(DNode *head);
void findDataD(DNode *head);
void findPositionD(DNode *head);
void emptyListD(DNode *head);
void printListD(DNode *head);
void projectDouble(DNode *head);

#endif //LINKLIST_DOUBLELINKEDLIST_H

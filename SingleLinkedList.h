//
// Created by Ð¡Õñ on 2021/3/2.
//

#ifndef LINKLIST_SINGLELINKEDLIST_H
#define LINKLIST_SINGLELINKEDLIST_H

#include "stdio.h"
#include "stdlib.h"

typedef struct snode {
    int data;
    struct snode *next;
}SNode;

void initHeadS(SNode **head);
void insertTailNodeS(SNode *head, int data);
void createListS(SNode *head);
void insertNodeS(SNode *head);
void delNodeS(SNode *head);
void modifyNodeS(SNode *head);
void findDataS(SNode *head);
void findPositionS(SNode *head);
void emptyListS(SNode *head);
void printListS(SNode *head);
void projectSingle(SNode *head);
void reverse(SNode *head, int n);

#endif //LINKLIST_SINGLELINKEDLIST_H

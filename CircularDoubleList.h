/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:42
*@Version
*/

#ifndef LINKLIST_CIRCULARDOUBLELIST_H
#define LINKLIST_CIRCULARDOUBLELIST_H

#include "stdio.h"
#include "stdlib.h"

typedef struct cdnode {
    struct cdnode *pre;
    int data;
    struct cdnode *next;
}CDNode;

void initHeadCD(CDNode **head);
void insertTailNodeCD(CDNode *head, int data);
void createListCD(CDNode *head);
void insertNodeCD(CDNode *head);
void delNodeCD(CDNode *head);
void modifyNodeCD(CDNode *head);
void findDataCD(CDNode *head);
void findPositionCD(CDNode *head);
void printListCD(CDNode *head);
void projectCD(CDNode *head);

#endif //LINKLIST_CIRCULARDOUBLELIST_H

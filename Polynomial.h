/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 12:00
*@Version
*/

#ifndef LINKLIST_POLYNOMIAL_H
#define LINKLIST_POLYNOMIAL_H

#include"stdio.h"
#include"stdlib.h"

typedef struct pnode {
    int coefficient;
    int index;
    struct pnode *next;
}Node;

void attach(int coefficient, int index, Node **rear);
Node *scanEquation();
void addEquation(Node *equationOne, Node *equationTwo);
void multiplyEquation(Node *equationOne, Node *equationTwo);
void printEquation(Node *equation);

#endif //LINKLIST_POLYNOMIAL_H

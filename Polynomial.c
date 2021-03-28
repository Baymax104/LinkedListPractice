/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 12:01
*@Version
*/
#include "Polynomial.h"
void attach(int coefficient, int index, Node **rear) {
    Node *s = (Node *)malloc(sizeof (Node));
    s->coefficient = coefficient;
    s->index = index;
    s->next = NULL;
    (*rear)->next = s;
    *rear = s;
}
Node *scanEquation() {
    Node *head, *rear;
    int coefficient, index;
    head = (Node *)malloc(sizeof (Node));
    head->next = NULL;
    rear = head;
    printf("请输入多项式系数和指数:(a,b)(输入-1,-1结束输入)\n");
    while (1) {
        scanf("%d,%d", &coefficient, &index);
        if (coefficient == -1 && index == -1) {
            break;
        }
        attach(coefficient, index, &rear);
    }
    return head;
}
void printEquation(Node *equation) {
    while (equation->next) {
        equation = equation->next;
        printf("%dX^%d ", equation->coefficient, equation->index);
    }
    putchar('\n');
}
void addEquation(Node *equationOne, Node *equationTwo) {
//     * 遍历两个链表，判断指数是否相等
//     * 相等则相加后插入，否则直接插入
//     * 链表长度不一定相等，需要处理剩下的项
    Node *resultHead, *resultRear;
    int sum;
    resultHead = (Node *)malloc(sizeof (Node));
    resultHead->next = NULL;
    resultRear = resultHead;
    Node *first = equationOne->next;
    Node *second = equationTwo->next;
    while (first && second) {
        if (first->index == second->index) {
            sum = first->coefficient + second->coefficient;
            if (sum != 0) {
                attach(sum, first->index, &resultRear);
            }
            first = first->next;
            second = second->next;
        } else if (first->index > second->index) {
            attach(first->coefficient, first->index, &resultRear);
            first = first->next;
        } else {
            attach(second->coefficient, second->index, &resultRear);
            second = second->next;
        }
    }
    // 若①式还有项未处理，则继续添加项
    while (first) {
        attach(first->coefficient, first->index, &resultRear);
        first = first->next;
    }
    // 若②式还有项未处理，则继续添加项
    while (second) {
        attach(second->coefficient, second->index, &resultRear);
        second = second->next;
    }
    printEquation(resultHead);
}
void multiplyEquation(Node *equationOne, Node *equationTwo) {
//     * 一个链表的每一项乘以另一链表的每一项
//     * 处理:用一个链表的第一项乘以另一链表的每一项，得到一个结果链表
//     * 再用该链表的后续每一项乘以另一链表的每一项，得到的结果插入到结果链表中
    Node *resultHead, *resultRear;
    int coefficient, index;
    Node *first = equationOne->next;
    Node *second = equationTwo->next;
    resultHead = (Node *)malloc(sizeof (Node));
    resultHead->next = NULL;
    resultRear = resultHead;
    Node *copy = second;// 保存②式的头指针
    while (second) {
        attach(first->coefficient * second->coefficient,
               first->index + second->index, &resultRear);
        second = second->next;
    }
    first = first->next;// ①式从第二项开始
    while (first) {
        second = copy;
        resultRear = resultHead;
        while (second) {
            coefficient = first->coefficient * second->coefficient;
            index = first->index + second->index;
            // 移动到要插入的节点之前，resultRear取得前驱
            while (resultRear->next && resultRear->next->index > index) {
                resultRear = resultRear->next;
            }
            if (resultRear->next && resultRear->next->index == index) {
                if (resultRear->index + index != 0) {
                    resultRear->next->coefficient += coefficient;
                } else {
                    Node *temp = resultRear->next;
                    resultRear->next = temp->next;
                    free(temp);
                }
            } else {
                Node *temp = (Node *)malloc(sizeof (Node));
                temp->coefficient = coefficient;
                temp->index = index;
                temp->next = resultRear->next;
                resultRear->next = temp;
                resultRear = resultRear->next;
            }
            second = second->next;
        }
        first = first->next;
    }
    printEquation(resultHead);
}

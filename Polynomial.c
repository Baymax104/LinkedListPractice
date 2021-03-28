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
    printf("���������ʽϵ����ָ��:(a,b)(����-1,-1��������)\n");
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
//     * �������������ж�ָ���Ƿ����
//     * �������Ӻ���룬����ֱ�Ӳ���
//     * �����Ȳ�һ����ȣ���Ҫ����ʣ�µ���
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
    // ����ʽ������δ��������������
    while (first) {
        attach(first->coefficient, first->index, &resultRear);
        first = first->next;
    }
    // ����ʽ������δ��������������
    while (second) {
        attach(second->coefficient, second->index, &resultRear);
        second = second->next;
    }
    printEquation(resultHead);
}
void multiplyEquation(Node *equationOne, Node *equationTwo) {
//     * һ�������ÿһ�������һ�����ÿһ��
//     * ����:��һ������ĵ�һ�������һ�����ÿһ��õ�һ���������
//     * ���ø�����ĺ���ÿһ�������һ�����ÿһ��õ��Ľ�����뵽���������
    Node *resultHead, *resultRear;
    int coefficient, index;
    Node *first = equationOne->next;
    Node *second = equationTwo->next;
    resultHead = (Node *)malloc(sizeof (Node));
    resultHead->next = NULL;
    resultRear = resultHead;
    Node *copy = second;// �����ʽ��ͷָ��
    while (second) {
        attach(first->coefficient * second->coefficient,
               first->index + second->index, &resultRear);
        second = second->next;
    }
    first = first->next;// ��ʽ�ӵڶ��ʼ
    while (first) {
        second = copy;
        resultRear = resultHead;
        while (second) {
            coefficient = first->coefficient * second->coefficient;
            index = first->index + second->index;
            // �ƶ���Ҫ����Ľڵ�֮ǰ��resultRearȡ��ǰ��
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

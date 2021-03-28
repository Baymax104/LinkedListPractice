/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 12:32
*@Version
*/
#include"stdio.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "CircularDoubleList.h"
#include "StaticLinkedList.h"
#include "BucketSort.h"
#include "CardinalSort.h"
#include "Polynomial.h"
int main () {
    SNode *Shead;
    DNode *Dhead;
    CDNode *CDhead;
    int arr[5] = {4, 2, 67, 54, 12};
    int arr1[10] = {6, 56, 89, 12, 39, 21, 11, 156, 657, 90};
    Node *equationFirst, *equationSecond;
    int op;
    do {
        puts("1)������");
        puts("2)˫������");
        puts("3)ѭ��˫������");
        puts("4)��̬����");
        puts("5)Ͱʽ����");
        puts("6)��������");
        puts("7)����ʽ�ӷ���˷�");
        puts("8)�˳�");
        printf("���������ѡ��:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                initHeadS(&Shead);
                createListS(Shead);
                projectSingle(Shead);
                break;
            case 2:
                initHeadD(&Dhead);
                createListD(Dhead);
                projectDouble(Dhead);
                break;
            case 3:
                initHeadCD(&CDhead);
                createListCD(CDhead);
                projectCD(CDhead);
                break;
            case 4:
                initList();
                createList();
                project();
                break;
            case 5:
                bucketSort(arr);
                for (int i = 0; i < 5; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 6:
                cardinalSort(arr1);
                for (int i = 0; i < 10; i++) {
                    printf("%d ", arr1[i]);
                }
                printf("\n");
                break;
            case 7:
                equationFirst = scanEquation();
                equationSecond = scanEquation();
                addEquation(equationFirst, equationSecond);
                multiplyEquation(equationFirst, equationSecond);
                break;
            case 8:
                printf("Goodbye\n");
                return 0;
        }
    } while (1);
}


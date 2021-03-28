/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:47
*@Version
*/
#include "StaticLinkedList.h"
static int cursorAlloc() {
    int p;
    p = space[0].cursor;
    space[0].cursor = space[p].cursor;
    return p;
}
static void cursorFree(int p) {
    space[p].cursor = space[0].cursor;
    space[0].cursor = p;
}
void initList() {
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space[i].cursor = i + 1;
    }
    space[MAXSIZE - 1].cursor = 0;
}
void insertTailNode(int data) {
    int s = cursorAlloc();
    space[s].data = data;
    int current = MAXSIZE - 1;
    while (space[current].cursor) {
        current = space[current].cursor;
    }
    space[current].cursor = s;
    space[s].cursor = 0;
}
void createList() {
    int data;
    printf("����������:(��-1��������)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertTailNode(data);
    }
}
void insertNode() {
    int data;
    int position;
    printf("������Ҫ�����λ�ü�����:(a,b)\n");
    scanf("%d,%d", &position, &data);
    int preInsertNode = MAXSIZE - 1;
    for (int i = 0; i < position-1; i++) {
        preInsertNode = space[preInsertNode].cursor;
    }
    int s = cursorAlloc();
    space[s].data = data;
    space[s].cursor = space[preInsertNode].cursor;
    space[preInsertNode].cursor = s;
    printf("������Ϊ:\n");
    printList();
}
void delNode() {
    int data;
    printf("������Ҫɾ��������:\n");
    scanf("%d", &data);
    int preDeleteNode = MAXSIZE - 1;
    while (space[preDeleteNode].cursor) {
        if (space[space[preDeleteNode].cursor].data == data) {
            break;
        }
        preDeleteNode = space[preDeleteNode].cursor;
    }
    if (space[preDeleteNode].cursor == 0) {
        printf("���ݲ�����!\n");
        return;
    } else {
        int freeNode = space[preDeleteNode].cursor;
        space[preDeleteNode].cursor = space[freeNode].cursor;
        cursorFree(freeNode);
        puts("ɾ�����Ϊ:");
        printList();
    }
}
void modifyNode() {
    int data;
    int position;
    printf("������Ҫ�޸ĵ�λ�ü����ǵ�����:(a,b)\n");
    scanf("%d,%d", &position, &data);
    int current = MAXSIZE - 1;
    for (int i = 0; i < position; i++) {
        current = space[current].cursor;
    }
    space[current].data = data;
    printf("�޸ĺ�Ľ��Ϊ:\n");
    printList();
}
void findData() {
    int position;
    printf("������Ҫ���ҵ�λ��:\n");
    scanf("%d", &position);
    int current = MAXSIZE - 1;
    for (int i = 0; i < position; i++) {
        current = space[current].cursor;
    }
    printf("��λ�õ�����Ϊ: %d\n", space[current].data);
}
void findPosition() {
    int data;
    int position = 0;
    printf("������Ҫ���ҵ�����:\n");
    scanf("%d", &data);
    int current = MAXSIZE - 1;
    while (current) {
        if (space[current].data == data) {
            break;
        }
        position++;
        current = space[current].cursor;
    }
    if (current == 0) {
        printf("���ݲ�����!\n");
        return;
    }
    printf("�����ݵ�λ��Ϊ: %d\n", position);
}
void printList() {
    int current = MAXSIZE - 1;
    while (space[current].cursor) {
        current = space[current].cursor;
        printf("%d ", space[current].data);
    }
    printf("\n");
}
void project() {
    int op;
    do {
        puts("1)��ӡ��");
        puts("2)��ӽڵ�");
        puts("3)ɾ���ڵ�");
        puts("4)�޸Ľڵ�");
        puts("5)����ָ��λ�õ�����");
        puts("6)����ָ�����ݵ�λ��");
        puts("7)�˳�");
        printf("���������ѡ��:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("���Ϊ:\n");
                printList();
                break;
            case 2:
                insertNode();
                break;
            case 3:
                delNode();
                break;
            case 4:
                modifyNode();
                break;
            case 5:
                findData();
                break;
            case 6:
                findPosition();
                break;
            case 7:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while (1);
}


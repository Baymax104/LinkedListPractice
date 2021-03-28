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
    printf("请输入数据:(按-1结束输入)\n");
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
    printf("请输入要插入的位置及数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    int preInsertNode = MAXSIZE - 1;
    for (int i = 0; i < position-1; i++) {
        preInsertNode = space[preInsertNode].cursor;
    }
    int s = cursorAlloc();
    space[s].data = data;
    space[s].cursor = space[preInsertNode].cursor;
    space[preInsertNode].cursor = s;
    printf("插入结果为:\n");
    printList();
}
void delNode() {
    int data;
    printf("请输入要删除的数据:\n");
    scanf("%d", &data);
    int preDeleteNode = MAXSIZE - 1;
    while (space[preDeleteNode].cursor) {
        if (space[space[preDeleteNode].cursor].data == data) {
            break;
        }
        preDeleteNode = space[preDeleteNode].cursor;
    }
    if (space[preDeleteNode].cursor == 0) {
        printf("数据不存在!\n");
        return;
    } else {
        int freeNode = space[preDeleteNode].cursor;
        space[preDeleteNode].cursor = space[freeNode].cursor;
        cursorFree(freeNode);
        puts("删除结果为:");
        printList();
    }
}
void modifyNode() {
    int data;
    int position;
    printf("请输入要修改的位置及覆盖的数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    int current = MAXSIZE - 1;
    for (int i = 0; i < position; i++) {
        current = space[current].cursor;
    }
    space[current].data = data;
    printf("修改后的结果为:\n");
    printList();
}
void findData() {
    int position;
    printf("请输入要查找的位置:\n");
    scanf("%d", &position);
    int current = MAXSIZE - 1;
    for (int i = 0; i < position; i++) {
        current = space[current].cursor;
    }
    printf("该位置的数据为: %d\n", space[current].data);
}
void findPosition() {
    int data;
    int position = 0;
    printf("请输入要查找的数据:\n");
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
        printf("数据不存在!\n");
        return;
    }
    printf("该数据的位置为: %d\n", position);
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
        puts("1)打印表");
        puts("2)添加节点");
        puts("3)删除节点");
        puts("4)修改节点");
        puts("5)查找指定位置的数据");
        puts("6)查找指定数据的位置");
        puts("7)退出");
        printf("请输入你的选择:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("结果为:\n");
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


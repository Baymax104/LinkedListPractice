/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:26
*@Version
*/
#include "DoubleLinkedList.h"
void initHeadD(DNode **head) {
    (*head) = (DNode *)malloc(sizeof (DNode));
    (*head)->pre = NULL;
    (*head)->next = NULL;
    (*head)->data = 0;
}
void insertTailNodeD(DNode *head, int data) {
    DNode *current = head;
    while (current->next) {
        current = current->next;
    }
    DNode *s = (DNode *)malloc(sizeof (DNode));
    s->data = data;
    current->next = s;
    s->next = NULL;
    s->pre = current;
}
void createListD(DNode *head) {
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertTailNodeD(head, data);
    }
}
void insertNodeD(DNode *head) {
    int position;
    int data;
    printf("请输入插入的位置及数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    DNode *current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    DNode *s = (DNode *)malloc(sizeof (DNode));
    s->data = data;
    s->next = current->next;
    s->pre = current;
    current->next->pre = s;
    current->next = s;
    printf("插入结果为:\n");
    printListD(head);
}
void delNodeD(DNode *head) {
    int data;
    printf("请输入要删除的数据:\n");
    scanf("%d", &data);
    DNode *preDeleteNode = head;
    while (preDeleteNode->next) {
        if (preDeleteNode->next->data == data) {
            break;
        }
        preDeleteNode = preDeleteNode->next;
    }
    if (preDeleteNode->next == NULL) {
        printf("数据不存在!\n");
        return;
    } else {
        DNode *freeNode = preDeleteNode->next;
        preDeleteNode->next = freeNode->next;
        freeNode->next->pre = preDeleteNode;
        free(freeNode);
        freeNode = NULL;
        puts("删除结果为:");
        printListD(head);
    }
}
void modifyNodeD(DNode *head) {
    int data;
    int position;
    printf("请输入要修改的位置及覆盖的数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    DNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = data;
    printf("修改后的结果为:\n");
    printListD(head);
}
void findDataD(DNode *head) {
    int position;
    printf("请输入要查找的位置:\n");
    scanf("%d", &position);
    DNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    printf("该位置的数据为: %d\n", current->data);
}
void findPositionD(DNode *head) {
    int data;
    int position = 1;
    printf("请输入要查找的数据:\n");
    scanf("%d", &data);
    DNode *current = head->next;
    while (current) {
        if (current->data == data) {
            break;
        }
        position++;
        current = current->next;
    }
    if (current == NULL) {
        puts("数据不存在!\n");
        return;
    }
    printf("该数据的位置为: %d\n", position);
}
void emptyListD(DNode *head) {
    DNode *current = head;
    while (current) {
        head = current->next;
        free(current);
        current = head;
    }
    if (head == NULL) {
        puts("删除完成!\n");
    } else {
        printf("删除失败!\n");
    }
}
void printListD(DNode *head) {
    while (head->next) {
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}
void projectDouble(DNode *head) {
    int op;
    do {
        puts("1)打印双向表");
        puts("2)添加节点");
        puts("3)删除节点");
        puts("4)修改节点");
        puts("5)查找指定位置的数据");
        puts("6)查找指定数据的位置");
        puts("7)删除表");
        puts("8)退出");
        printf("请输入你的选择:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("结果为:\n");
                printListD(head);
                break;
            case 2:
                insertNodeD(head);
                break;
            case 3:
                delNodeD(head);
                break;
            case 4:
                modifyNodeD(head);
                break;
            case 5:
                findDataD(head);
                break;
            case 6:
                findPositionD(head);
                break;
            case 7:
                emptyListD(head);
                break;
            case 8:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while (1);
}



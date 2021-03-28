//
// Created by 小振 on 2021/3/2.
//
#include "SingleLinkedList.h"
void initHeadS(SNode **head) {
    (*head) = (SNode *)malloc(sizeof (SNode));
    (*head)->next = NULL;
}
void insertTailNodeS(SNode *head, int data) {
    SNode *current = head;
    while (current->next) {
        current = current->next;
    }
    SNode *s = (SNode *)malloc(sizeof (SNode));
    s->data = data;
    current->next = s;
    s->next = NULL;
}
void createListS(SNode *head) {
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertTailNodeS(head, data);
    }
}
void insertNodeS(SNode *head) {
    int position;
    int data;
    printf("请输入要插入的位置和数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    SNode *current = head;
    for (int i = 0; i<position-1; i++) {
        current = current->next;
    }
    SNode *s = (SNode *)malloc(sizeof (SNode));
    s->data = data;
    s->next = current->next;
    current->next = s;
    printf("插入结果为:\n");
    printListS(head);
}
void delNodeS(SNode *head) {
    int data;
    printf("请输入要删除的数据:\n");
    scanf("%d", &data);
    SNode *preDeleteNode = head;
    while (preDeleteNode->next) {
        if (preDeleteNode->next->data == data){
            break;
        }
        preDeleteNode = preDeleteNode->next;
    }
    if (preDeleteNode->next == NULL) {
        printf("数据不存在!\n");
        return;
    } else {
        SNode *freeNode = preDeleteNode->next;
        preDeleteNode->next = freeNode->next;
        free(freeNode);
        freeNode = NULL;
        puts("删除结果为:");
        printListS(head);
    }
}
void modifyNodeS(SNode *head) {
    int position;
    int data;
    SNode *current = head;
    printf("请输入要修改的位置及覆盖的数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = data;
    printf("修改后的结果为:\n");
    printListS(head);
}
void findDataS(SNode *head) {
    int position;
    printf("请输入查找的位置:\n");
    scanf("%d", &position);
    SNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    printf("该位置的数据为: %d\n", current->data);
}
void findPositionS(SNode *head) {
    int position = 1;
    int data;
    SNode *current = head->next;
    printf("请输入查找的数据:\n");
    scanf("%d", &data);
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
void emptyListS(SNode *head) {
    SNode *current = head;
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
void printListS(SNode *head) {
    while (head->next) {
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}
void projectSingle(SNode *head) {
    int op;
    do {
        puts("1)打印单链表");
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
                printListS(head);
                break;
            case 2:
                insertNodeS(head);
                break;
            case 3:
                delNodeS(head);
                break;
            case 4:
                modifyNodeS(head);
                break;
            case 5:
                findDataS(head);
                break;
            case 6:
                findPositionS(head);
                break;
            case 7:
                emptyListS(head);
                break;
            case 8:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while (1);
}


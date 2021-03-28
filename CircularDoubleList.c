/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:44
*@Version
*/
#include "CircularDoubleList.h"
void initHeadCD(CDNode **head) {
    (*head) = (CDNode *)malloc(sizeof (CDNode));
    (*head)->next = NULL;
    (*head)->pre = NULL;
    (*head)->data = 0;
}
void insertTailNodeCD(CDNode *head, int data) {
    CDNode *current = head->pre;
    CDNode *s = (CDNode *)malloc(sizeof (CDNode));
    s->data = data;
    if (current == NULL) {
        s->pre = head;
        head->next = s;
        s->next = head;
        head->pre = s;
    } else {
        s->next = head;
        s->pre = current;
        current->next = s;
        head->pre = s;
    }
}
void createListCD(CDNode *head) {
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertTailNodeCD(head, data);
    }
}
void insertNodeCD(CDNode *head) {
    int data;
    int position;
    printf("请输入要插入的位置及数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    CDNode *current = head;
    for (int i = 0; i < position-1; i++) {
        current = current->next;
    }
    CDNode *s = (CDNode *)malloc(sizeof (CDNode));
    s->data = data;
    s->next = current->next;
    s->pre = current;
    current->next->pre = s;
    current->next = s;
    printf("插入结果为:\n");
    printListCD(head);
}
void delNodeCD(CDNode *head) {
    int data;
    printf("请输入要删除的数据:\n");
    scanf("%d", &data);
    CDNode *deleteNode = head->next;
    while (deleteNode != head) {
        if (deleteNode->data == data) {
            break;
        }
        deleteNode = deleteNode->next;
    }
    if (deleteNode == head) {
        printf("数据不存在!\n");
        return;
    } else {
        deleteNode->next->pre = deleteNode->pre;
        deleteNode->pre->next = deleteNode->next;
        free(deleteNode);
        deleteNode =NULL;
        puts("删除结果为:");
        printListCD(head);
    }
}
void modifyNodeCD(CDNode *head) {
    int data;
    int position;
    printf("请输入要修改的位置及覆盖的数据:(a,b)\n");
    scanf("%d,%d", &position, &data);
    CDNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = data;
    printf("修改后的结果为:\n");
    printListCD(head);
}
void findDataCD(CDNode *head) {
    int position;
    printf("请输入要查找的位置:\n");
    scanf("%d", &position);
    CDNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    printf("该位置的数据为: %d\n", current->data);
}
void findPositionCD(CDNode *head) {
    int data;
    int position = 1;
    printf("请输入要查找的数据:\n");
    scanf("%d", &data);
    CDNode *current = head->next;
    while (current != head) {
        if (current->data == data) {
            break;
        }
        position++;
        current = current->next;
    }
    if (current == head) {
        puts("数据不存在!\n");
        return;
    }
    printf("该数据的位置为: %d\n", position);
}
void printListCD(CDNode *head) {
    CDNode *current = head->next;
    while (current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void projectCD(CDNode *head) {
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
                printListCD(head);
                break;
            case 2:
                insertNodeCD(head);
                break;
            case 3:
                delNodeCD(head);
                break;
            case 4:
                modifyNodeCD(head);
                break;
            case 5:
                findDataCD(head);
                break;
            case 6:
                findPositionCD(head);
                break;
            case 7:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while (1);
}


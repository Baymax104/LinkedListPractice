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
    printf("����������:(��-1��������)\n");
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
    printf("������Ҫ�����λ�ü�����:(a,b)\n");
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
    printf("������Ϊ:\n");
    printListCD(head);
}
void delNodeCD(CDNode *head) {
    int data;
    printf("������Ҫɾ��������:\n");
    scanf("%d", &data);
    CDNode *deleteNode = head->next;
    while (deleteNode != head) {
        if (deleteNode->data == data) {
            break;
        }
        deleteNode = deleteNode->next;
    }
    if (deleteNode == head) {
        printf("���ݲ�����!\n");
        return;
    } else {
        deleteNode->next->pre = deleteNode->pre;
        deleteNode->pre->next = deleteNode->next;
        free(deleteNode);
        deleteNode =NULL;
        puts("ɾ�����Ϊ:");
        printListCD(head);
    }
}
void modifyNodeCD(CDNode *head) {
    int data;
    int position;
    printf("������Ҫ�޸ĵ�λ�ü����ǵ�����:(a,b)\n");
    scanf("%d,%d", &position, &data);
    CDNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = data;
    printf("�޸ĺ�Ľ��Ϊ:\n");
    printListCD(head);
}
void findDataCD(CDNode *head) {
    int position;
    printf("������Ҫ���ҵ�λ��:\n");
    scanf("%d", &position);
    CDNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    printf("��λ�õ�����Ϊ: %d\n", current->data);
}
void findPositionCD(CDNode *head) {
    int data;
    int position = 1;
    printf("������Ҫ���ҵ�����:\n");
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
        puts("���ݲ�����!\n");
        return;
    }
    printf("�����ݵ�λ��Ϊ: %d\n", position);
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


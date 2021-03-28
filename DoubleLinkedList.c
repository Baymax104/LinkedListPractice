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
    printf("����������:(��-1��������)\n");
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
    printf("����������λ�ü�����:(a,b)\n");
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
    printf("������Ϊ:\n");
    printListD(head);
}
void delNodeD(DNode *head) {
    int data;
    printf("������Ҫɾ��������:\n");
    scanf("%d", &data);
    DNode *preDeleteNode = head;
    while (preDeleteNode->next) {
        if (preDeleteNode->next->data == data) {
            break;
        }
        preDeleteNode = preDeleteNode->next;
    }
    if (preDeleteNode->next == NULL) {
        printf("���ݲ�����!\n");
        return;
    } else {
        DNode *freeNode = preDeleteNode->next;
        preDeleteNode->next = freeNode->next;
        freeNode->next->pre = preDeleteNode;
        free(freeNode);
        freeNode = NULL;
        puts("ɾ�����Ϊ:");
        printListD(head);
    }
}
void modifyNodeD(DNode *head) {
    int data;
    int position;
    printf("������Ҫ�޸ĵ�λ�ü����ǵ�����:(a,b)\n");
    scanf("%d,%d", &position, &data);
    DNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = data;
    printf("�޸ĺ�Ľ��Ϊ:\n");
    printListD(head);
}
void findDataD(DNode *head) {
    int position;
    printf("������Ҫ���ҵ�λ��:\n");
    scanf("%d", &position);
    DNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    printf("��λ�õ�����Ϊ: %d\n", current->data);
}
void findPositionD(DNode *head) {
    int data;
    int position = 1;
    printf("������Ҫ���ҵ�����:\n");
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
        puts("���ݲ�����!\n");
        return;
    }
    printf("�����ݵ�λ��Ϊ: %d\n", position);
}
void emptyListD(DNode *head) {
    DNode *current = head;
    while (current) {
        head = current->next;
        free(current);
        current = head;
    }
    if (head == NULL) {
        puts("ɾ�����!\n");
    } else {
        printf("ɾ��ʧ��!\n");
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
        puts("1)��ӡ˫���");
        puts("2)��ӽڵ�");
        puts("3)ɾ���ڵ�");
        puts("4)�޸Ľڵ�");
        puts("5)����ָ��λ�õ�����");
        puts("6)����ָ�����ݵ�λ��");
        puts("7)ɾ����");
        puts("8)�˳�");
        printf("���������ѡ��:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("���Ϊ:\n");
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



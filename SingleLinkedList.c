//
// Created by С�� on 2021/3/2.
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
    printf("����������:(��-1��������)\n");
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
    printf("������Ҫ�����λ�ú�����:(a,b)\n");
    scanf("%d,%d", &position, &data);
    SNode *current = head;
    for (int i = 0; i<position-1; i++) {
        current = current->next;
    }
    SNode *s = (SNode *)malloc(sizeof (SNode));
    s->data = data;
    s->next = current->next;
    current->next = s;
    printf("������Ϊ:\n");
    printListS(head);
}
void delNodeS(SNode *head) {
    int data;
    printf("������Ҫɾ��������:\n");
    scanf("%d", &data);
    SNode *preDeleteNode = head;
    while (preDeleteNode->next) {
        if (preDeleteNode->next->data == data){
            break;
        }
        preDeleteNode = preDeleteNode->next;
    }
    if (preDeleteNode->next == NULL) {
        printf("���ݲ�����!\n");
        return;
    } else {
        SNode *freeNode = preDeleteNode->next;
        preDeleteNode->next = freeNode->next;
        free(freeNode);
        freeNode = NULL;
        puts("ɾ�����Ϊ:");
        printListS(head);
    }
}
void modifyNodeS(SNode *head) {
    int position;
    int data;
    SNode *current = head;
    printf("������Ҫ�޸ĵ�λ�ü����ǵ�����:(a,b)\n");
    scanf("%d,%d", &position, &data);
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = data;
    printf("�޸ĺ�Ľ��Ϊ:\n");
    printListS(head);
}
void findDataS(SNode *head) {
    int position;
    printf("��������ҵ�λ��:\n");
    scanf("%d", &position);
    SNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    printf("��λ�õ�����Ϊ: %d\n", current->data);
}
void findPositionS(SNode *head) {
    int position = 1;
    int data;
    SNode *current = head->next;
    printf("��������ҵ�����:\n");
    scanf("%d", &data);
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
void emptyListS(SNode *head) {
    SNode *current = head;
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
void reverse(SNode *head, int n) {
    SNode *p = head->next;
    int numberOfNode = 0;
    while (p) {
        numberOfNode++;
        p = p->next;
    }
    if (n > numberOfNode) {
        puts("���������ڵ����!");
        return;
    }
    int count = 1;
    SNode *new = head->next; // ��ת�������ͷ���ָ��
    SNode *old = new->next; // δ��ת�������ͷ���ָ��
    SNode *temp;
    while (count < n) {
        temp = old->next;
        old->next = new;
        new = old;
        old = temp;
        count++;
    }
    head->next->next = old;
    head->next = new;
    printListS(head);
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
    int n;
    do {
        puts("1)��ӡ������");
        puts("2)��ӽڵ�");
        puts("3)ɾ���ڵ�");
        puts("4)�޸Ľڵ�");
        puts("5)����ָ��λ�õ�����");
        puts("6)����ָ�����ݵ�λ��");
        puts("7)��ת����");
        puts("8)ɾ����");
        puts("9)�˳�");
        printf("���������ѡ��:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("���Ϊ:\n");
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
                printf("��������ת����:\n");
                scanf("%d", &n);
                reverse(head, n);
                break;
            case 8:
                emptyListS(head);
                break;
            case 9:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while (1);
}


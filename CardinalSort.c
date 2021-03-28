/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:59
*@Version
*/
#include "CardinalSort.h"
void cardinalSort(int arr[]) {
    // �õ������е����ֵ��ȡ��λ��
    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    int count = 0;// ���ֵλ��
    while (max != 0) {
        max /= 10;
        count++;
    }
    // ��������
    int bucket[10][10];
    int everyBucketNumber[10] = {0};// ��¼ÿ��Ͱ�ж��ٸ�����
    int base = 1;// ȡ������ÿһλ������
    // ÿ��ѭ���������ֵ�һλ��ÿ�δ�����Ҫ����Ͱ��ȡ��
    for (int i = 0; i < count; i++) {
        // ��������ȡ���ַ���Ͱ��
        for (int j = 0; j < 10; j++) {
            int digit = arr[j] / base % 10;
            bucket[digit][everyBucketNumber[digit]] = arr[j];
            everyBucketNumber[digit]++;
        }
        // ��Ͱ��ȡ������
        int arrIndex = 0;// ��¼ԭ������±�
        // ����ÿ��Ͱ
        for (int j = 0; j < 10; j++) {
            // ���Ͱ�������֣��������Ͱ
            if (everyBucketNumber[j] != 0) {
                for (int k = 0; k < everyBucketNumber[j]; k++) {
                    arr[arrIndex] = bucket[j][k];
                    arrIndex++;
                }
            }
            everyBucketNumber[j] = 0;
        }
        base *= 10;
    }
}


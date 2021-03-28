/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:59
*@Version
*/
#include "CardinalSort.h"
void cardinalSort(int arr[]) {
    // 得到数组中的最大值，取得位数
    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    int count = 0;// 最大值位数
    while (max != 0) {
        max /= 10;
        count++;
    }
    // 基数排序
    int bucket[10][10];
    int everyBucketNumber[10] = {0};// 记录每个桶有多少个数字
    int base = 1;// 取得数字每一位的数字
    // 每次循环处理数字的一位，每次处理需要放入桶再取出
    for (int i = 0; i < count; i++) {
        // 从数组中取数字放入桶中
        for (int j = 0; j < 10; j++) {
            int digit = arr[j] / base % 10;
            bucket[digit][everyBucketNumber[digit]] = arr[j];
            everyBucketNumber[digit]++;
        }
        // 从桶中取出数字
        int arrIndex = 0;// 记录原数组的下标
        // 遍历每个桶
        for (int j = 0; j < 10; j++) {
            // 如果桶中有数字，则遍历该桶
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


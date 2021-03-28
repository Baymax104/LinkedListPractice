/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 11:56
*@Version
*/
#include "BucketSort.h"
void bucketSort(int arr[]) {
    int count[100] = {0};
    for (int i = 0; i < 5; i++) {
        count[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i < 100; i++) {
        if (count[i] != 0) {
            arr[j] = i;
            j++;
        }
    }
}


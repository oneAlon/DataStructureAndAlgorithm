//
//  YAMergeSort.c
//  Sort
//
//  Created by OneAlon on 2018/12/21.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "YAMergeSort.h"

void mergetSort(int *array, int start, int end);
void mergeArray(int * array, int start, int mid, int end);

// 将数组传入函数使用的时候, 只是传递的指针
int *mergeSort(int *array, size_t arr_size) {
    mergetSort(array, 0, ((int)arr_size - 1));
    return array;
}

void mergetSort(int *array, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end)/2;
    mergetSort(array, start, mid);
    mergetSort(array, (mid + 1), end);
    mergeArray(array, start, mid, end);
}

void mergeArray(int *array, int start, int mid, int end) {
    int tempArray[100];
    int i = start; // 第一个区间的索引
    int j = mid + 1; // 第二个区间的索引
    int k = 0; // 临时区间索引
    
    while (i <= mid && j <= end) {
        if (array[i] <= array[j]) {
            tempArray[k++] = array[i++];
        }else{
            tempArray[k++] = array[j++];
        }
    }

    // 第二个区间全部放入临时数组
    while (i <= mid) {
        tempArray[k++] = array[i++];
    }

    // 第一个区间已经全部放入临时数组
    while (j <= end) {
        tempArray[k++] = array[j++];
    }

    for (int i = 0; i < k; i++) {
        array[start + i] = tempArray[i];
    }
}

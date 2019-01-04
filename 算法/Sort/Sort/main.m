//
//  main.m
//  Sort
//
//  Created by OneAlon on 2018/12/21.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - help

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void printArray(int *array, size_t arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

#pragma mark - 冒泡排序

void bubbleSort() {
    int array[] = {55, 23, 93, 23, 4, 56, 1, 34, 130, 11, 69};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    printf("冒泡排序前:\n");
    printArray(array, arr_size);
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array, j, j + 1);
            }
        }
    }
    printf("冒泡排序后:\n");
    printArray(array, arr_size);
}

#pragma mark - 归并排序

void mergetSort(int *array, int start, int end);
void mergeArray(int * array, int start, int mid, int end);

// 将数组传入函数使用的时候, 只是传递的指针
void mergeSort() {
    int array[] = {55, 23, 93, 23, 4, 56, 1, 34, 130, 11, 69};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    printf("归并排序排序前:\n");
    printArray(array, arr_size);
    mergetSort(array, 0, ((int)arr_size - 1));
    printf("归并排序排序后:\n");
    printArray(array, arr_size);
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

#pragma mark - main

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // 冒泡排序
        bubbleSort();
        mergeSort();
    }
    return 0;
}

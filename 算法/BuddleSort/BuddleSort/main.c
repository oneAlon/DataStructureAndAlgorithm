//
//  main.c
//  BuddleSort
//
//  Created by xygj on 2019/1/4.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include <stdio.h>

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

/*
 思想: 比较两个相邻的关键字, 如果反序就交换, 直到没有反序的记录为止
 */

void bubbleSort() {
    int array[] = {9, 2, 5, 8, 3, 7, 4, 1, 6, 2};
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

#pragma mark - main

int main(int argc, const char * argv[]) {
    bubbleSort();
    return 0;
}


//
//  main.c
//  03-插入排序
//
//  Created by xygj on 2019/1/11.
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

#pragma mark - 插入排序

/*
 从第一个元素开始，该元素可以认为已经被排序；
 取出下一个元素，在已经排序的元素序列中从后向前扫描；
 如果该元素（已排序）大于新元素，将该元素移到下一位置；
 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
 将新元素插入到该位置后；
 重复步骤2~5。
 */

void sort() {
    int array[] = {9, 2, 5, 8, 3, 7, 4, 1, 6, 2};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    printf("插入排序前:\n");
    printArray(array, arr_size);
    
    for (int i = 1; i < arr_size; i++) {
        int j = i - 1;
        int temp = array[i];
        while (j >= 0 && array[j] > temp) {
            // 将插入数据之前前面的数据向后移动
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    
    printf("插入排序后:\n");
    printArray(array, arr_size);
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    sort();
    return 0;
}

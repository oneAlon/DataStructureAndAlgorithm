//
//  main.c
//  02-选择排序
//
//  Created by xygj on 2019/1/11.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include <stdio.h>

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

#pragma mark - 选择排序

/*
 思想: 从待排序的数组中选择一个最小的元素(一般选择最开始的元素)
 复杂度: O(n平方)
 */

void selectionSort() {
    int array[] = {9, 2, 5, 8, 3, 7, 4, 1, 6, 2};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    printf("选择排序前:\n");
    printArray(array, arr_size);
    
    // i执行一次, 获取到一个最大值
    for (int i = 0; i < arr_size; i++) {
        for (int j = i + 1; j < arr_size; j++) {
            if (array[i] > array[j]) {
                swap(array, i, j);
            }
        }
    }
    
    printf("选择排序后:\n");
    printArray(array, arr_size);
}

int main(int argc, const char * argv[]) {
    selectionSort();
    printf("Hello, World!\n");
    return 0;
}

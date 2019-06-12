//
//  main.c
//  01-顺序查找
//
//  Created by xygj on 2019/1/24.
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

#pragma mark - 顺序查找

/*
 顺序查找, 适用于存储结构为顺序存储和链式存储的线性表.
 无序查找
 时间复杂度为O(n)
 */
int suquenceSort(int a) {
    int array[] = {9, 2, 5, 8, 3, 7, 4, 1, 6, 2};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    for (int i = 0; i < arr_size; i++) {
        if (array[i] == a) {
            return 1;
        }
    }
    return 0;
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    int result = suquenceSort(2);
    if (result == 1) {
        printf("在数组中查找到元素\n");
    }else {
        printf("在数组中未查找到元素\n");
    }
    return 0;
}

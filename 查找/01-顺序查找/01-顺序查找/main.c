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
 思想: 比较两个相邻的关键字, 如果反序就交换, 直到没有反序的记录为止
 复杂度: O(n平方)
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

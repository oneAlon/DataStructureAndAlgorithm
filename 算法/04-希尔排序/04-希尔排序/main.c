//
//  main.c
//  04-希尔排序
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

void sort() {
    int array[] = {9, 5, 8, 3, 7, 4, 1, 6, 2};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    // 设置间隔, 相隔某个增量的记录成一个子序列, 实现跳跃式的移动, 提高效率
    int increment = (int)arr_size;
    
    printf("排序前:\n");
    printArray(array, arr_size);
    
    while (increment > 1) {
        // 设置增量, 每次减少增量, 知道增量为1
        increment = increment / 3 + 1;
        for (int i = increment; i < arr_size; i++) {
            for (int j = i - increment; j>=0 && array[i] < array[j]; j -= increment) {
                swap(array, i, j);
            }
            
//            int j = i - increment;
//            while (j > 0) {
//                if (array[i] < array[j]) {
//                    swap(array, i, j);
//                }
//                j = j - increment;
//            }
        }
    }
    
    printf("排序后:\n");
    printArray(array, arr_size);
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    sort();
    return 0;
}

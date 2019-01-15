//
//  main.m
//  05-归并排序
//
//  Created by xygj on 2019/1/15.
//  Copyright © 2019 OneAlon. All rights reserved.
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

/*
 把长度为n的输入序列分成两个长度为n/2的子序列；
 对这两个子序列分别采用归并排序；
 将两个排序好的子序列合并成一个最终的排序序列。
 */

void sort() {
    int array[] = {9, 5, 8, 3, 7, 4, 1, 6, 2, 3};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    // 设置间隔, 相隔某个增量的记录成一个子序列, 实现跳跃式的移动, 提高效率
    int increment = (int)arr_size;
    
    printf("排序前:\n");
    printArray(array, arr_size);
    
    while (increment > 1) {
        // 设置增量, 每次减少增量, 知道增量为1
        increment = increment / 3 + 1;
        for (int i = increment; i < arr_size; i++) {
            int temp = array[i];
            int j = i - increment;
            while (j >= 0 && array[j] > temp) {
                array[j + increment] = array[j];
                j -= increment;
            }
            array[j + increment] = temp;
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

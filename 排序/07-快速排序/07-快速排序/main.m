//
//  main.m
//  07-快速排序
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

void quickSort(int *array, int left, int right) {
    if (left >= right) return;
    int rightIndex = right;
    // 选取基准
    int temp = array[left];
    while (left < right) {
        while (left < right && array[right] >= temp) {
            right--;
        }
        array[left] = array[right];
        while (left < right && array[left] <= temp) {
            left++;
        }
        array[right] = array[left];
    }
    // 基准元素归为
    array[left] = temp;
    
    // 递归
    quickSort(array, 0, left - 1);
    quickSort(array, left + 1, rightIndex);
}

/**
 快速排序
 对冒泡排序的一种改进, 通过一趟排序将要进行排序的数据分割成两个独立的部分, 一部分数据比另一部分所有的数据都要小
 然后再按照这个方法将剩下的数据进行排序, 整个过程使用递归进行.
 
 实现:
 一般选择数组的第一个数据作为基准元素.
 定义两个指针left right
 int temp = array[left]
 
 */
void sort() {
    int array[] = {9, 5, 8, 3, 7, 4, 1, 6, 2, 5};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    printf("排序前:\n");
    printArray(array, arr_size);

    quickSort(array, 0, (int)arr_size - 1);
    
    printf("排序后:\n");
    printArray(array, arr_size);
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    sort();
    return 0;
}

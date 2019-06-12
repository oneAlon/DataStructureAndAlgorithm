//
//  main.m
//  06-堆排序
//
//  Created by xygj on 2019/1/15.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#import <Foundation/Foundation.h>

int arrLength = 9;

/*
 堆排序 相对简单选择排序的改进
 */
#pragma mark - help

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void printArray(int *array) {
    for (int i = 0; i < 9; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

#pragma mark - 插入排序

/**
 构造大顶堆

 @param array 需要构造的数组
 @param i 数组长度
 */
// 初始化大顶堆时 是从最后一个有子节点开始往上调整最大堆。而堆顶元素(最大数)与堆最后一个数交换后，需再次调整成大顶堆，此时是从上往下调整的。
void maxHeapAdjust(int *array, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < arrLength && array[left] > array[max]) {
        max = left;
    }
    
    if (right < arrLength && array[right] > array[max]) {
        max = right;
    }
    
    if (max != i) {
        swap(array, i, max);
        maxHeapAdjust(array, max);
    }
}

void sort() {
    int array[] = {9, 2, 5, 8, 3, 7, 4, 1, 6};
    
    printf("插入排序前:\n");
    printArray(array);
    
    // 将数组构建成大顶堆
    for (int i = arrLength / 2; i >= 0; i--) {
        maxHeapAdjust(array, i);
    }
    
    for (int i = arrLength - 1; i >= 0; i--) {
        // 将堆顶元素和未排序的数组交换.
        swap(array, 0, i);
        arrLength--;
        maxHeapAdjust(array, 0);
    }
    
    
    printf("插入排序后:\n");
    printArray(array);
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    sort();
    return 0;
}

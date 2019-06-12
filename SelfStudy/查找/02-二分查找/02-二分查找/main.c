//
//  main.c
//  02-二分查找
//
//  Created by xygj on 2019/1/24.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include <stdio.h>

#pragma mark - 顺序查找

/*
 二分查找, 必须是有序, 如果是无序要先进行排序操作
 有序序查找
 时间复杂度为O(log2(n))
 */

int binarySort(int a) {
    int array[] = {1, 2, 2, 3, 4, 6, 7, 8, 9, 20};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    int left = 0, right = (int)arr_size - 1;
    int mid = (left + right) / 2;
    
    while (left <= right) {
        mid = (left + right) / 2;
        if (a == array[mid]) {
            return 1;
        }else if (a < array[mid]) {
            right = mid - 1;
        }else if (a > array[mid]) {
            left = mid + 1;
        }
    }
    return 0;
}

// 递归
int binarySortRecursive(int array[], int a, int left, int right) {
    
    int mid = (left + right) / 2;
    
    if (a == array[mid]) {
        return 1;
    }else if (a < array[mid]) {
        right = mid - 1;
        return binarySortRecursive(array, a, left, right);
    }else if (a > array[mid]) {
        left = mid + 1;
        return binarySortRecursive(array, a, left, right);
    }
    return 0;
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    int result = binarySort(20);
    if (result == 1) {
        printf("在数组中查找到元素\n");
    }else {
        printf("在数组中未查找到元素\n");
    }
    
    
    int array[] = {1, 2, 2, 3, 4, 6, 7, 8, 9, 20};
    int result2 = binarySortRecursive(array, 8, 0, 9);
    if (result2 == 1) {
        printf("在数组中查找到元素\n");
    }else {
        printf("在数组中未查找到元素\n");
    }
    
    return 0;
}

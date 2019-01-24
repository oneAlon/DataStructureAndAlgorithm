//
//  main.c
//  03-差值查找
//
//  Created by xygj on 2019/1/24.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include <stdio.h>

#pragma mark - 顺序查找

/*
 差值查找是二分查找的优化
 mid = (left + right)/2 = lfet + (right - left)/2;
 
 差值查找优化, 需要查找的值为key(二分查找可以理解为key刚好在中间)
 mid = left + (right - left) * (key - array[left])/(array[right] - array[left]);
 */

int binarySort(int a) {
    int array[] = {1, 2, 2, 3, 4, 6, 7, 8, 9, 20};
    size_t arr_size = sizeof(array) / sizeof(array[0]);
    
    int left = 0, right = (int)arr_size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) * (a - array[left])/(array[right] - array[left]);
        if (a == array[mid]) {
            return mid;
        }else if (a < array[mid]) {
            right = mid - 1;
        }else if (a > array[mid]) {
            left = mid + 1;
        }
    }
    return -1;
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    int result = binarySort(1);
    if (result >= 0) {
        printf("在数组中查找到元素, 位置为%d\n", result + 1);
    }else {
        printf("在数组中未查找到元素\n");
    }
    return 0;
}


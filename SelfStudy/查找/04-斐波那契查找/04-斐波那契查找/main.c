//
//  main.c
//  04-斐波那契查找
//
//  Created by xygj on 2019/1/24.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include <stdio.h>

/*
 斐波那契查找也是二分查找的优化,
 二分查找:mid = (left + right)/2 = lfet + (right - left)/2;
 
 斐波那契查找是利用黄金比例的概念在舒蕾中查找结点. 属于有序查找.
 
 差值查找优化, 需要查找的值为key(二分查找可以理解为key刚好在中间)
 mid = left + (right - left) * (key - array[left])/(array[right] - array[left]);
 */


int fibonacciSort(int key) {
    int F[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    
    int array[] = {1, 2, 2, 3, 4, 6, 7, 8, 9, 20};
    int arr_size = (int)(sizeof(array) / sizeof(array[0]));
    
    int left = 1;
    int right = arr_size;
    
    int k = 0;
    // 在斐波那契数列中查找arr_size的索引
    while (arr_size > F[k] - 1) {
        k++;
    }
    
    // 补全数组
    for (int i = right + 1; i < F[k] - 1; i++) {
        array[i] = array[right];
    }
    
    int mid;
    
    while (left <= right) {
        mid = left + F[k - 1] - 1;
        if (key == array[mid]) {
            return mid;
        } else if (key < array[mid]) {
            right = mid - 1;
            k -= 1;
        }else if (key > array[mid]) {
            left = mid + 1;
            k -= 2;
        }else {
            return arr_size;
        }
    }

    return -1;
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    int result = fibonacciSort(20);
    if (result >= 0) {
        printf("在数组中查找到元素, 位置为%d\n", result + 1);
    }else {
        printf("在数组中未查找到元素\n");
    }
    return 0;
}

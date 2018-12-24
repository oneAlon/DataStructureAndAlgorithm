//
//  main.m
//  Sort
//
//  Created by OneAlon on 2018/12/21.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "YAMergeSort.h"


#define ARRAYLENGTH(array) sizeof(array) / sizeof(array[0])

void printArray(int array[], size_t arr_size);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int array[] = {55, 23, 93, 23, 4, 56, 1, 34, 130, 11, 69};
        
        // 冒泡排序

        // 归并排序
        printArray(mergeSort(array, ARRAYLENGTH(array)), ARRAYLENGTH(array));
    }
    return 0;
}

void printArray(int *array, size_t arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d\n", array[i]);
    }
}

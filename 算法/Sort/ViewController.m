//
//  ViewController.m
//  DataStructureAndAlgorithm
//
//  Created by OneAlon on 2018/12/7.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#import "ViewController.h"

/*
 数组
 字典
 字符串
 链表
 栈和队列
 二叉树
 排序
 搜索
 */

/*
 冒泡排序       n平方     稳定
 插入排序       n平方     稳定
 选择排序       n平方     不稳定
 堆排序         nlogn    不稳定
 归并排序       nlogn    稳定
 快速排序       nlogn    不稳定
 桶排序         n         稳定
 
 好的算法性能是nlogn, 坏的算法性能是n平方
 */

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSArray *array = @[@55, @23, @93, @23, @4, @56, @1, @34, @11, @69];
    
    NSArray *buddleSortArray = [self bubbleSort:array];
    NSLog(@"冒泡排序:%@", buddleSortArray);
    
    NSArray *selectSortArray = [self selectSort:array];
    NSLog(@"选择排序:%@", selectSortArray);
    
    NSArray *insertSortArray = [self insertSort:array];
    NSLog(@"插入排序:%@", insertSortArray);
    
    NSArray *quickSortArray = [self quickSort:array];
    NSLog(@"快速排序:%@", quickSortArray);
    
    NSArray *mergeSortArray = [self mergeSort:array];
    NSLog(@"归并排序:%@", mergeSortArray);
    
}

/*
 冒泡排序
 冒泡算法是重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成
 */
- (NSArray *)bubbleSort:(NSArray *)array {
    NSMutableArray *mutArray = [array mutableCopy];
    int count = (int)mutArray.count;
    // 总复杂度: n的平方
    for (int i = 0; i < count; i++) { // 时间复杂度n
        for (int j = 0; j < count - i - 1; j++) {// 时间复杂度n-1
            if ([mutArray[j] intValue] > [mutArray[j + 1] intValue]) {
                NSNumber *temp = mutArray[j];
                mutArray[j] = mutArray[j + 1];
                mutArray[j + 1] = temp;
            }
        }
    }
    
    return [mutArray copy];
}

/**
 选择排序
 选择排序的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
 */
- (NSArray *)selectSort:(NSArray *)array {
    NSMutableArray *mutArray = [array mutableCopy];
    int count = (int)mutArray.count;
    // 总复杂度: n的平方
    for (int i = 0; i < count; i++) {// 复杂度n
        for (int j = i + 1; j < count; j++) {// 复杂度n-1
            if ([mutArray[i] intValue] > [mutArray[j] intValue]) {
                NSNumber *temp = mutArray[i];
                mutArray[i] = mutArray[j];
                mutArray[j] = temp;
            }
        }
    }
    
    return [mutArray copy];
}


/**
 插入排序
    每一步将一个待排序的记录，插入到前面已经排好序的有序序列中去，直到插完所有元素为止。
 */
- (NSArray *)insertSort:(NSArray *)array {
    NSMutableArray *mutArray = [array mutableCopy];
    int count = (int)mutArray.count;
    // 总复杂度: n的平方
    for (int i = 0, j = 0; i < count; i++, j = 0) {// 复杂度n
        int j = i; // 循环一次, 表示已排序的数组中增加一位
        // 和已排序的数组中的值进行排序比较.
        while (j > 0 && [mutArray[j - 1] intValue] > [mutArray[j] intValue]) {// 复杂度n
            NSNumber *temp = mutArray[j - 1];
            mutArray[j - 1] = mutArray[j];
            mutArray[j] = temp;
            j--;
        }
        
//        while (j <= i) {
//            if ([mutArray[j] intValue] > [mutArray[i] intValue]) {
//                NSNumber *temp = mutArray[j];
//                mutArray[j] = mutArray[i];
//                mutArray[i] = temp;
//            }
//            j++;
//        }
    }
    
    return [mutArray copy];
}

#pragma mark - 快速排序

/**
 快速排序
    对冒泡排序的一种改进, 通过一趟排序将要进行排序的数据分割成两个独立的部分, 一部分数据比另一部分所有的数据都要小
    然后再按照这个方法将剩下的数据进行排序, 整个过程使用递归进行.
 
 实现:
    一般选择数组的第一个数据作为基准元素.
    定义两个指针left right
    int temp = array[left]
 
 */
- (NSArray *)quickSort:(NSArray *)array {
    return [self quicklySort:[array mutableCopy] left:0 right:((int)array.count - 1)];
}

- (NSArray *)quicklySort:(NSMutableArray *)array left:(int)left right:(int)right {
    
    if (left >= right) {
        return array;
    }
    
    int rightIndex = right;
    
    // 记录基准元素, 选取第一个为基准元素
    int temp = [array[left] intValue];
    
    while (left < right) {
        while (left < right && [array[right] intValue] >= temp) {
            // 比基准元素大, 继续查找
            right--;
        }
        // 比基准元素小, 赋值
        array[left] = array[right];
        
        while (left < right && [array[left] intValue] <= temp) {
            left++;
        }
        array[right] = array[left];
    }
    
    // 基准元素归位
    array[left] = [NSNumber numberWithInt:temp];
    
    // 递归
    [self quicklySort:array left:0 right:(left - 1)];
    [self quicklySort:array left:(left + 1) right:rightIndex];
    
    return [array copy];
}





@end

//
//  main.m
//  DataStructure
//
//  Created by xygj on 2018/12/21.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ListSequentialStorage.h"
#import "ListLinkStorage.h"
#import "StackSequentialStorage.h"
#import "StackLinkStorage.h"
#import "MyString.h"
#import "TreeLinkStorage.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // 线性表顺序存储
//        listSequentialStorageTest();
        
        // 线性表链式存储
//        ListLinkStorageTest();
        
        // 栈顺序存储
//        stackSequentialStorageTest();
        
        // 栈的链式存储
//        stackLinkStorageTest();
        
        // 字符串测试
//        myStrTest();
        
        // 二叉树链式存储
        treeLinkStorageTest();
    }
    return 0;
}

//
//  ListChainStorage.c
//  DataStructure
//
//  Created by xygj on 2018/12/25.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "ListChainStorage.h"

// 定义线性表中的元素(这里假定元素为int类型)
typedef int Element;

// 定义节点数据结构
typedef struct {
    Element data;// 节点存储的数据
    struct Node *next;// 指向下一个节点
}Node;


#pragma mark - test

void listChainStorageTest() {
    
}

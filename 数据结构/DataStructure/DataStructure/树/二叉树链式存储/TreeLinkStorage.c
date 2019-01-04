//
//  TreeLinkStorage.c
//  DataStructure
//
//  Created by xygj on 2019/1/3.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include "TreeLinkStorage.h"

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等

// 定义元素类型
typedef char Element;
Element Nil = ' ';

// 定义节点类型
typedef struct Tag_Node {
    Element data;
    struct Tag_Node *lfet, *right;// 指向左右子节点
}Node;

// 定义二叉树, 指向节点
typedef Node *BiTree;

// 构造空二叉树
Status initBiTree(BiTree *T) {
    *T = NULL;
    return OK;
}

// 构建二叉树
Status createBiTree(BiTree *T) {
    printf("请输入节点内容, #表示空节点\n");
    Element e;
    scanf("%c", &e);
//    = getchar();
    
    // 如果输入
    if (e == '#' || e == '\n') {
        *T = NULL;
        return ERROR;
    }
    
    // 分配内存
    *T = (BiTree)malloc(sizeof(Node));
    if (!*T) {
        return ERROR;
    }
    
    // 设置数据
    (*T)->data = e;
    // 构建左子树
    createBiTree(&((*T)->lfet));
    // 构建右字数
    createBiTree(&((*T)->right));
    
    return OK;
}

int treeDepth(BiTree T) {
    int i, j;
    if (!T) {
        return 0;
    }
    if (T->lfet) {
        i = treeDepth(T->lfet);
    }else{
        i = 0;
    }
    if (T->right) {
        j = treeDepth(T->right);
    }else{
        j = 0;
    }
    return i > j ? i + 1 : j + 1;
}


#pragma mark - Test

void treeLinkStorageTest() {
    
    BiTree tree;
    
    // 构建空二叉树
    initBiTree(&tree);
    
    // 构建树
    createBiTree(&tree);
    
    // 深度
    printf("二叉树的深度为%d\n", treeDepth(tree));
    
}

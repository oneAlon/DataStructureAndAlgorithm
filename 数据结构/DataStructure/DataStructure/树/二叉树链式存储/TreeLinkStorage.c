//
//  TreeLinkStorage.c
//  DataStructure
//
//  Created by xygj on 2019/1/3.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include "TreeLinkStorage.h"
#include <stdlib.h>
#include <time.h>

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等

// 定义元素类型
typedef int Element;
Element Nil = ' ';

// 定义结点类型
typedef struct Tag_Node {
    Element data;
    struct Tag_Node *lfet, *right;// 指向左右子结点
}Node;

// 定义二叉树, 指向结点
typedef Node *BiTree;

// 构造空二叉树
Status initBiTree(BiTree *T) {
    *T = (BiTree)malloc(sizeof(Node));
    if (T) {
        (*T)->data = -1;
        (*T)->lfet = NULL;
        (*T)->right = NULL;
        return OK;
    }else {
        return ERROR;
    }
}

// 构建节点
BiTree constructNode(Element e) {
    BiTree pnode = (BiTree)malloc(sizeof(Node));
    pnode->data = e;
    pnode->lfet = NULL;
    pnode->right = NULL;
    printf("%d  ", e);
    return pnode;
}

// 添加结点
Status addNodeToTree(BiTree *root, BiTree newNode) {
    if ((*root) == NULL) {
        return ERROR;
    }
    // 判断根结点
    if ((*root)->data == -1) {
        *root = newNode;
        return OK;
    }
    BiTree temp = *root;
    while (temp != NULL) {
        if (temp->data > newNode->data) {
            if (temp->lfet == NULL) {
                temp->lfet = newNode;
                return OK;
            }else{
                temp = temp->lfet;
            }
        }else{
            if (temp->right == NULL) {
                temp->right = newNode;
                return OK;
            }else{
                temp = temp->right;
            }
        }
    }
    return OK;
}

// 树的深度
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

// 递归遍历(递归会出现函数频繁的入栈和出栈, 很可能出现栈溢出, 而且效率比较低)
void inorderRecursive(BiTree tree) {
    if (tree == NULL) {
        return;
    }
    BiTree temp = tree;
    inorderRecursive(temp->lfet);
    printf("%d\n", temp->data);
    inorderRecursive(temp->right);
}

// 非递归遍历(自己维护栈)
void inorderNoRecursive(BiTree tree) {
}

// 查找结点

// 删除节点
void deleteNode(BiTree *tree, Element e) {
    
}


#pragma mark - Test

void treeLinkStorageTest() {
    
    int testArray[7] = {100, 50, 200, 40, 80, 90, 60};
    
    BiTree tree;
    
    // 构建空二叉树
    initBiTree(&tree);
    
    // 构造二叉排序树
    for (int i = 0; i <7 ; i++) {
        Element e = testArray[i];
        BiTree node = constructNode(e);
        addNodeToTree(&tree, node);
    }
    printf("\n");
    printf("二叉排序树构建完成\n");
    printf("树的深度%d\n", treeDepth(tree));
    
    printf("中序递归遍历begin----\n");
    inorderRecursive(tree);
    printf("中序递归遍历end----\n");
    
}

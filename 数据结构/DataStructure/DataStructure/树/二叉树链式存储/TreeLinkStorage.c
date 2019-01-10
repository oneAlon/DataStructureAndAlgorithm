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

// 定义结点类型
typedef struct Tag_Node {
    Element data;
    struct Tag_Node *left, *right;// 指向左右子结点
}Node;

// 定义二叉树, 指向结点
typedef Node *BiTree;

// 构造空二叉树
Status initBiTree(BiTree *T) {
    *T = (BiTree)malloc(sizeof(Node));
    if (T) {
        (*T)->data = -1;
        (*T)->left = NULL;
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
    pnode->left = NULL;
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
            if (temp->left == NULL) {
                temp->left = newNode;
                return OK;
            }else{
                temp = temp->left;
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
    if (T->left) {
        i = treeDepth(T->left);
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

#pragma mark - 遍历

// 递归遍历(递归会出现函数频繁的入栈和出栈, 很可能出现栈溢出, 而且效率比较低)
void inorderRecursive(BiTree tree) {
    if (tree == NULL) {
        return;
    }
    BiTree temp = tree;
    inorderRecursive(temp->left);
    printf("%d\n", temp->data);
    inorderRecursive(temp->right);
}

// 前序, 非递归遍历(自己维护栈)
//void inorderNoRecursive(BiTree tree) {
//    if (tree == NULL) {
//        return;
//    }
//    // 将根结点push进栈
//    push(tree);
//    BiTree node;
//    while (1/*判断栈里边是否有数据*/) {
//        // 从栈中获取结点
//        node = pop();
//        if (node != NULL) {
//            printf("%d", node->data);
//            push(node->right);
//            push(node->left);
//        }
//    }
//}

// 中序, 非递归遍历(自己维护栈)
void inorderNoRecursive(BiTree tree) {
    if (tree == NULL) {
        return;
    }
    // 将根结点push进栈
    push(tree);
    BiTree node;
    while (1/*判断栈里边是否有数据*/) {
        // 从栈中获取结点
        node = pop();
        if (node != NULL) {
            printf("%d", node->data);
            push(node->right);
            push(node->left);
        }
    }
}

#pragma mark - 查找

// 查找最大值
void searchMax(BiTree tree, Element *e) {
    if (tree == NULL) {
        return;
    }
    
    if (tree->right == NULL) {
        *e = tree->data;
        return;
    }else {
        searchMax(tree->right, e);
    }
}

// 查找最小值
void searchMin(BiTree tree, Element *e) {
    if (tree == NULL) {
        return;
    }
    
    if (tree->left == NULL) {
        *e = tree->data;
        return;
    }else {
        searchMin(tree->left, e);
    }
}

// 查找某一个元素, 递归实现
BiTree searchTree(BiTree tree, Element e) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->data > e) {
        return searchTree(tree->left, e);
    }else if (tree->data < e) {
        return searchTree(tree->right, e);
    }else {
        return tree;
    }
}

// 查找某一个元素, 非递归实现
BiTree searchTreNoRecursive(BiTree tree, Element e) {
    if (!tree) {
        return NULL;
    }
    BiTree temp = tree;
    while (temp) {
        if (temp->data == e) {
            return temp;
        }else {
            temp = temp->data > e ? temp->left : temp->right;
        }
    }
    return NULL;
}

#pragma mark - 插入

void insertNodeToTree(BiTree *tree, Element e) {
    // 如果为空树, 直接设置根节点
    while ((*tree) == NULL) {
        (*tree)->data = e;
        return;
    }
    // 创建节点
    BiTree node = constructNode(e);
    
    // 查找要插入的位置
    BiTree parentNode = *tree;
    while (parentNode) {
        parentNode = (*tree)->data > e ? (*tree)->left : (*tree)->right;
    }
    
}


#pragma mark - 删除

// 删除节点
void deleteNode(BiTree *tree, Element e) {
    
    // 查找需要删除的节点
    BiTree node = searchTree(*tree, e);
    
    // 未找到
    if (node == NULL) {
        printf("结点%d未找到\n", e);
        return;
    }
    
    
    
    // 删除节点
    
    // 删除叶子
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
    
    printf("查找最大值begin----\n");
    Element eMax;
    searchMax(tree, &eMax);
    printf("查找最大值end---%d----\n", eMax);
    
    printf("查找最小值begin----\n");
    Element eMin;
    searchMin(tree, &eMin);
    printf("查找最小值end---%d----\n", eMin);
    
    Element eSearch = 200;
    BiTree searchNodeP = searchTree(tree, eSearch);
    printf("在树中查找%d, 查找到的数据为%d\n", eSearch, searchNodeP->data);
    BiTree searchNodePoniterNoRecursive = searchTreNoRecursive(tree, eSearch);
    printf("在树中非递归查找%d, 查找到的数据为%d\n", eSearch, searchNodePoniterNoRecursive->data);
    
}

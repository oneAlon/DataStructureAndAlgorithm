//
//  ListLinkStorage.c
//  DataStructure
//
//  Created by xygj on 2018/12/25.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "ListLinkStorage.h"

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等

#pragma mark - 类型定义

// 定义线性表中的元素(这里假定元素为int类型)
typedef int Element;

// 定义节点数据结构
typedef struct Tag_Node {
    Element data;// 节点存储的数据
    struct Tag_Node *next;// 指向下一个节点
}Node;

// 定义链表, 指向结构体的指针
typedef Node *LinkList;

#pragma mark - 链表创建

Status initLinkList(LinkList *linkList) {
    // 创建头结点, 并是linkList指向此头结点
    *linkList = malloc(sizeof(Node));
    
    if (!(*linkList)) {
        return ERROR;
    }
    
    (*linkList)->next = NULL;
    return OK;
}

#pragma mark - 链表的读取

int linkListLength(LinkList linkList) {
    int length = 0;
    LinkList p = linkList->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

#pragma mark - 链表的插入和删除

Status listInsert(LinkList *linkList, int i, Element e) {
    
    LinkList p, s;
    int j = 1;
    p = *linkList;
    
    // 查找第i个节点
    while (p && j < i) {
        p = p->next;
        j++;
    }
    
    // 如果未查找到
    if (!p || j > i) {
        return ERROR;
    }
    
    // 创建节点
    s = malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}

Status listDelete(LinkList *linkList, int i, Element *e) {
    LinkList p, s;
    int j = 1;
    p = *linkList;
    
    // 查找第i个元素
    while (p && j < i) {
        p = p->next;
        j++;
    }
    
    if (!p || j > i) {
        return ERROR;
    }
    
    // 找到第i个元素
    s = p->next;
    p->next = s->next;
    *e = p->data;
    
    return OK;
}


#pragma mark - test

void ListLinkStorageTest() {
    
    // 链表
    LinkList linkList;
    Element e;
    
    // 初始化链表
    initLinkList(&linkList);
    printf("初始化链表\n");
    
    // 获取初始化以后的长度
    int length = linkListLength(linkList);
    printf("初始化以后表的长度:%d\n", length);
    
    // 插入
    for (int i = 0; i < 6; i++) {
        int insertStatus = listInsert(&linkList, 1, i + 2);
        if (insertStatus == 1) {
            printf("插入数据%d到链表中\n", i + 2);
        }
    }
    
    printf("插入以后的长度%d\n", linkListLength(linkList));
    
    // 删除
    listDelete(&linkList, 2, &e);
    printf("从链表中删除元素%d\n", e);
    
//    printf("删除以后")
    
}

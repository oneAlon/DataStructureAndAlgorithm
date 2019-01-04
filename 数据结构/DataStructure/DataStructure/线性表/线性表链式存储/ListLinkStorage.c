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
    
    (*linkList)->data = 666;// 初始化头结点数据, 可以用来存储表的长度等信息.
    (*linkList)->next = NULL;
    return OK;
}

#pragma mark - 链表的读取

// 链表长度
int linkListLength(LinkList linkList) {
    int length = 0;
    LinkList p = linkList->next;// 第一个节点
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 链表是否为空
Status linkListEmpty(LinkList linkList) {
    LinkList p = linkList->next;// 第一个节点
    if (p) {
        return FALSE;
    }
    return TRUE;
}

// 清空链表
Status clearLinkList(LinkList *linkList) {
    
    LinkList p, q;
    p = (*linkList)->next;// 指向第一个节点
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    
    (*linkList)->next = NULL;// 头指针指向NULL
    
    return OK;
}

// 获取元素
Status GetElem(LinkList linkList,int i,Element *e) {
    LinkList p;
    int j = 1;
    p = linkList->next;// p指向第一个节点
    
    while (p && j < i) {
        p = p->next;
        j++;
    }
    
    if (!p || j > i) {
        return ERROR;
    }
    
    *e = p->data;
    
    return OK;
}

// 获取元素在链表中的位置
int LocateElem(LinkList linkList,Element e) {
    return 0;
}

#pragma mark - 链表的插入和删除

Status listInsert(LinkList *linkList, int i, Element e) {
    
    LinkList p, s;
    int j = 1;
    p = *linkList;// 头结点
    
    // 查找第i-1个节点
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
    p = *linkList;// 头结点
    
    // 查找第i-1个元素
    while (p->next && j < i) {
        p = p->next;
        j++;
    }
    
    // 如果未找到第i个元素
    if (!(p->next) || j > i) {
        return ERROR;
    }
    
    // 找到第i个元素
    s = p->next;
    p->next = s->next;
    *e = s->data;
    
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
    
    printf("初始化以后表是否为空; 1(空) 0(非空), %d\n", linkListEmpty(linkList));
    
    // 插入
    for (int i = 0; i < 6; i++) {
        int insertStatus = listInsert(&linkList, 1, i + 2);
        if (insertStatus == 1) {
            printf("插入数据%d到链表中\n", i + 2);
        }
    }
    
    printf("插入数据以后表是否为空; 1(空) 0(非空), %d\n", linkListEmpty(linkList));
    
    printf("插入以后的长度%d\n", linkListLength(linkList));
    
    // 删除
    listDelete(&linkList, 2, &e);
    printf("从链表中删除元素%d\n", e);
    
    printf("删除以后的长度%d\n", linkListLength(linkList));
    
    GetElem(linkList, 3, &e);
    printf("获取表中的第3个元素为%d\n", e);
    
    clearLinkList(&linkList);
    printf("清空以后的的长度%d\n", linkListLength(linkList));
    
}

/*
 单链表: 采用链式存储结构, 用一组任意的存储单元存放线性表的元素
 存读数据时间复杂度为O(n)
 插入删除的复杂度为O(1)
 
 单链表不需要分配存储空间, 元素个数不受限制.
 
 链表适用于插入删除修改比较频繁的场景
 线性表的顺序存储适用于读取比较频繁的场景.
 
 */


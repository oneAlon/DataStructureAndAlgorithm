//
//  StackLinkStorage.c
//  DataStructure
//
//  Created by xygj on 2018/12/27.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "StackLinkStorage.h"

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等

typedef int Element;

// 定义节点
typedef struct Tag_Node {
    Element data;
    struct Tag_Node *next;// 指向下一个节点
}Node;

// 定义链栈
typedef struct Tag_LinkStack {
    Node *top;// top指针, 指向节点
    int count;// 个数
}LinkStack;

// 初始化
Status initStackLink(LinkStack *s) {
    // 分配空间, 指向头结点
    s->top = (Node *)malloc(sizeof(Node));
    if (!s->top) {
        return ERROR;
    }
    s->top = NULL;
    s->count = 0;
    return OK;
}

// 销毁, 清空
Status clearStackLink(LinkStack *s) {
    Node *p, *q;
    p = s->top;// 获取栈顶节点;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    return OK;
}


// 是否为空
Status stackLinkEmpty(LinkStack s) {
    if (s.count == 0) {
        return TRUE;
    }else{
        return FALSE;
    }
}

// 长度
int stackLinkLength(LinkStack s) {
    return s.count;
}

// 返回栈顶元素
Status getStackLinkTop(LinkStack s, Element *e) {
    if (s.count == 0) {
        return ERROR;
    }
    
    *e = s.top->data;
    
    return OK;
}

// push
Status stackLinkPush(LinkStack *s, Element e) {

    // 创建节点
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    
    // 将节点添加到栈顶
    p->next = s->top;
    s->top = p;
    
    s->count++;
    
    return OK;
}

// pop
Status stackLinkPop(LinkStack *s, Element *e) {
    // 空栈
    if (s->count == 0) {
        return ERROR;
    }
    
    // 取出top节点
    Node *p;
    *e = s->top->data;
    p = s->top;
    
    // 设置top指针指向下一个节点
    s->top = p->next;
    
    // 释放内存
    free(p);
    
    s->count--;
    
    return OK;
}

// 打印
void printStackLink(LinkStack s) {
    int length = s.count;
    for (int i = 0; i < length; i++) {
        printf("%d ", s.top->data);
        s.top = s.top->next;
    }
    printf("\n");
}

void stackLinkStorageTest() {
    LinkStack s;
    Element e;
    
    // 初始化
    initStackLink(&s);
    printf("初始化栈\n");
    
    // 获取初始化以后的长度
    int length = stackLinkLength(s);
    printf("初始化以后表的长度:%d\n", length);
    
    printf("初始化以后栈是否为空; 1(空) 0(非空), %d\n", stackLinkEmpty(s));
    
    // push
    for (int i = 0; i < 6; i++) {
        int insertStatus = stackLinkPush(&s, i + 2);
        if (insertStatus == 1) {
            printf("插入数据%d到链表中\n", i + 2);
        }
    }
    
    printf("push数据以后表是否为空; 1(空) 0(非空), %d\n", stackLinkEmpty(s));
    
    printf("push以后的长度%d\n", stackLinkLength(s));
    
    printf("打印栈中的数据\n");
    printStackLink(s);
    
    // 删除
    stackLinkPop(&s, &e);
    printf("从栈中pop出元素%d\n", e);
    
    printf("打印栈中的数据\n");
    printStackLink(s);
    
    printf("pop以后的长度%d\n", stackLinkLength(s));
    
    getStackLinkTop(s, &e);
    printf("获取栈顶元素为%d\n", e);
    
    clearStackLink(&s);
    printf("clear以后的的长度%d\n", stackLinkLength(s));
}


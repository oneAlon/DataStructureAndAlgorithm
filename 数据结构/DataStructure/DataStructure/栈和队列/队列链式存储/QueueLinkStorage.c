//
//  QueueLinkStorage.c
//  DataStructure
//
//  Created by xygj on 2018/12/28.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "QueueLinkStorage.h"

/*
 队列的链式存储
 其实就是线性表的单链表, 只不过只能尾进头出. 简称链队列
 */

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

// 定义连栈
typedef struct Tag_LinkQueue {
    Node *front;// top指针, 指向对头指针
    Node *rear;// 指向队尾指针
}LinkQueue;

// 初始化
Status initLinkQueue(LinkQueue *queue) {
    // 头结点
    Node *headNode = malloc(sizeof(Node));
    headNode->next = NULL;
    if (!headNode) {
        return ERROR;
    }
    
    // 队头队尾指针指向 头结点
    queue->front = headNode;
    queue->rear = headNode;
    
    return OK;
}

// 入队列
Status inLinkQueue(LinkQueue *queue, Element e) {
    // 创建节点
    Node *node = malloc(sizeof(Node));
    if (!node) {
        return ERROR;
    }
    node->data = e;
    node->next = NULL;
    
    queue->rear->next = node;
    
    queue->rear = node;
    
    return OK;
}

// 出队列
Status outLinkQueue(LinkQueue *queue, Element *e) {
    // 空队列
    if (queue->front == queue->rear) {
        return ERROR;
    }
    Node *n = queue->front->next;
    *e = n->data;
    
    // 头结点指向下一个节点
    queue->front->next = n->next;
    
    if (queue->rear == n) {
        // 删除的最后一个节点
        queue->front = queue->rear;
    }
    
    // 释放节点内存
//    free(n);
    
    return OK;
}

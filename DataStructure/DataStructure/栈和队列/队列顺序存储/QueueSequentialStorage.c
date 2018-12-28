//
//  QueueSequentialStorage.c
//  DataStructure
//
//  Created by xygj on 2018/12/28.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "QueueSequentialStorage.h"

/*
 1. 排队买票
 2. 叫号买票
 */

#define MAXSIZE 100

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等

typedef int Element;

typedef struct {
    Element data[MAXSIZE];
    int front;
    int rear;
}Queue;

// 初始化
Status initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    return OK;
}

// 入队列
Status inQueue(Queue *queue, Element e) {
    // 队列满
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return ERROR;
    }
    // 插入内容
    queue->data[queue->rear] = e;
    // 后移rear
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return OK;
}

// 出队列
Status outQueue(Queue *queue, Element *e) {
    // 栈空
    if (queue->front == queue->rear) {
        return ERROR;
    }
    *e = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return OK;
}

/*
 队列是一种特殊的线性表
 线性表的顺序存储存在数组移除的问题, 而且部分线性表的时间复杂度较高 相对效率就比较低.
 
 
 */



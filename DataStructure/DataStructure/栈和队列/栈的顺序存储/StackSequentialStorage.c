//
//  StackSequentialStorage.c
//  DataStructure
//
//  Created by xygj on 2018/12/26.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "StackSequentialStorage.h"

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
    int top;
}SqStack;

// 初始化
Status initStack(SqStack *s) {
    s->top = -1;
    return OK;
}

// 销毁, 清空
Status clearStack(SqStack *s) {
    s->top = -1;
    return OK;
}


// 是否为空
Status stackEmpty(SqStack s) {
    if (s.top == -1) {
        return TRUE;
    }else{
        return FALSE;
    }
}

// 长度
int stackLength(SqStack s) {
    return s.top + 1;
}

// 返回栈顶元素
Status getTop(SqStack s, Element *e) {
    if (s.top == -1) {
        return ERROR;
    }
    
    *e = s.data[s.top];
    
    return OK;
}

// push
Status push(SqStack *s, Element e) {
    // 栈满
    if (s->top >= MAXSIZE - 1) {
        return ERROR;
    }
    
    s->top++;// 栈顶指针加1
    s->data[s->top] = e;
    
    return OK;
}

// pop
Status pop(SqStack *s, Element *e) {
    // 空栈
    if (s->top == -1) {
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    
    return OK;
}

// 打印
void printStack(SqStack s) {
    int length = s.top + 1;
    for (int i = 0; i < length; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

void stackSequentialStorageTest() {
    SqStack s;
    Element e;
    
    // 初始化
    initStack(&s);
    printf("初始化栈\n");
    
    // 获取初始化以后的长度
    int length = stackLength(s);
    printf("初始化以后表的长度:%d\n", length);
    
    printf("初始化以后栈是否为空; 1(空) 0(非空), %d\n", stackEmpty(s));
    
    // push
    for (int i = 0; i < 6; i++) {
        int insertStatus = push(&s, i + 2);
        if (insertStatus == 1) {
            printf("插入数据%d到链表中\n", i + 2);
        }
    }

    printf("push数据以后表是否为空; 1(空) 0(非空), %d\n", stackEmpty(s));

    printf("push以后的长度%d\n", stackLength(s));
    
    printf("打印栈中的数据\n");
    printStack(s);

    // 删除
    pop(&s, &e);
    printf("从栈中pop出元素%d\n", e);
    
    printf("打印栈中的数据\n");
    printStack(s);

    printf("pop以后的长度%d\n", stackLength(s));

    getTop(s, &e);
    printf("获取栈顶元素为%d\n", e);

    clearStack(&s);
    printf("pop以后的的长度%d\n", stackLength(s));
}

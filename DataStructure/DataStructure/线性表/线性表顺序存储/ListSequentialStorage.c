//
//  ListSequentialStorage.c
//  DataStructure
//
//  Created by xygj on 2018/12/24.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "ListSequentialStorage.h"

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等

// 存储空间, 定义长度
#define MAXSIZE 30

// 定义线性表中的元素(这里假定元素为int类型)
typedef int Element;

// 定义线性表数据类型
typedef struct {
    Element data[MAXSIZE];
    int length;
}List;

// 创建线性表
Status initList(List *l) {
    l->length = 0;
    return OK;
}

// 线性表长度
int listLength(List l) {
    return l.length;
}

// 线性表判空
Status listEmpty(List l) {
    if (l.length > 0) {
        return TRUE;
    }else {
        return FALSE;
    }
}

// 清空线性表
Status clearList(List *l) {
    l->length = 0;
    return TRUE;
}

// 获取线性表元素
Status getElement(List l, int i, Element *e) {
    if (l.length == 0 || i > l.length || i < 1) {
        return ERROR;
    }
    *e = l.data[i - 1];
    return OK;
}

// 获取元素的位置
Status locateElement(List l, Element e) {
    if (l.length == 0) {
        return 0;
    }
    int i;
    for (i = 0; i < l.length; i++) {
        if (e == l.data[i]) {
            break;
        }
    }
    if (i >= l.length) {
        return 0;
    }
    return (i + 1);
}

// 插入
Status insertElement(List *l, int i, Element e) {
    // 线性表未满
    // 插入范围正常
    if (l->length >= MAXSIZE){
        return ERROR;
    }
    if (i < 1 || i > MAXSIZE || i > (l->length + 1)) {
        return ERROR;
    }
    
    // 插入的位置在中间(需要将元素向后转移)
    if (i <= l->length) {
        for (int k = l->length; k >= i; k--) {
            l->data[k] = l->data[k - 1];
        }
    }
    
    // 将元素插入到对应位置
    l->data[i - 1] = e;
    l->length++;
    
    return OK;
}

// 删除
Status deleteElement(List *l, int i, Element *e) {
    // 线性表不为空
    if (l->length <= 0) {
        return ERROR;
    }
    // 删除范围正常
    if (i < 1 || i > l->length) {
        return ERROR;
    }
    
    *e = l->data[i - 1];
    
    // 如果删除的不是最后一个
    if (i < l->length) {
        int k;
        for (k = i - 1; k < l->length - 1; k++) {
            l->data[k] = l->data[k + 1];
        }
    }
    l->length--;
    
    return OK;
}

// 打印线性表内容
void printListData(List l) {
    for(int i = 0; i < l.length; i++)
        printf("%d ", l.data[i]);
    printf("\n");
}

#pragma mark - 测试代码

void listSequentialStorageTest(void) {
    
    Element e;
    List l;
    
    // 初始化
    initList(&l);
    printf("初始化线性表\n");
    
    // 获取初始化以后的长度
    int length = listLength(l);
    printf("初始化以后线性表的长度:%d\n", length);
    
    // 插入元素
    for (int i = 0; i < 6; i++) {
        insertElement(&l, 1, i + 2);
    }
    
    // 插入以后的数据
    printf("插入以后的数据:\n");
    printListData(l);
    
    // 删除元素
    deleteElement(&l, 2, &e);
    printf("删除元素%d, 删除以后线性表data内容:", e);
    printListData(l);
    
    // 获取某一元素
    getElement(l, 3, &e);
    printf("获取线性表中的元素%d\n", e);
    
    // 获取元素位置
    int index = locateElement(l, e);
    printf("元素%d在线性表中的位置%d\n", e, index);
    
    // 是否为空
    Status isEmpty = listEmpty(l);
    printf("是否为空, 0(空), 1(非空), %d\n", isEmpty);
    
    // 清空
    clearList(&l);
    
    // 是否为空
    Status isEmpty2 = listEmpty(l);
    printf("是否为空, 0(空), 1(非空), %d\n", isEmpty2);
}

/*
 线性表的顺序存储
    平均时间复杂度为O(n)
    存读数据的复杂度为O(1)
    插入删除的复杂度为O(n)
 
    比较适合元素个数不太变化, 更多是存读数据的应用.
 
 优点:
    需要要关心表中元素之间的关系
    可以快速的存取表中的元素
 
 缺点:
    插入和删除需要移动大量的元素
    当线性表的长度过大时, 无法确定存储空间的容量(本次示例分配容量为30)
    存储空间造成碎片, 浪费
 */


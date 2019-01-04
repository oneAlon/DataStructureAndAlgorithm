//
//  MyString.c
//  DataStructure
//
//  Created by xygj on 2018/12/28.
//  Copyright © 2018 OneAlon. All rights reserved.
//

#include "MyString.h"

// 状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* 存储空间初始分配量 */

typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等

typedef int Element;

typedef char MyString[MAXSIZE + 1];

// 初始化字符串, 生成和chars相等的字符串str
Status initString(MyString str, char *chars) {
    int charsLength = strlen(chars);
    if (charsLength > MAXSIZE) {
        return ERROR;
    }
    
    str[0] = charsLength;
    for (int i = 1; i <= charsLength; i++) {
        // chars指向第一个
        str[i] = *(chars + i - 1);
    }
    return OK;
}

void myStrTest() {
    MyString str;
    initString(&str, "haha");
}

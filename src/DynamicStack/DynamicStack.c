/*
 * @Author: xixi_
 * @Date: 2024-10-20 22:02:55
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-11 10:50:56
 * @FilePath: /FHMF/src/Modules/xixi/src/DynamicStack/DynamicStack.c
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
#include "DynamicStack.h"

void XIXI_DynamicStackInit(ThisDynamicStack *ThisStack)
{
    ThisStack->ThisCapacity = DYNAMIC_STACK_DEFAULT_CAPACITY;                           /* 设置默认容量 */
    ThisStack->ThisTop = -1;                                                            /* 栈顶指针置为-1 */
    ThisStack->ThisCharArr = (char **)malloc(ThisStack->ThisCapacity * sizeof(char *)); /* 分配内存 */
    if (ThisStack->ThisCharArr == NULL)
    {
        fprintf(stderr, "Memory allocation failed during stack initialization.\n");
        exit(EXIT_FAILURE);
    }
}

int XIXI_DynamicStackIsEmpty(ThisDynamicStack *ThisStack)
{
    return ThisStack->ThisTop == -1;
}

int XIXI_DynamicStackResize(ThisDynamicStack *ThisStack)
{
    ThisStack->ThisCapacity *= 2;                                                                           /* 容量翻倍 */
    char **ThisTmpVal = (char **)realloc(ThisStack->ThisCharArr, ThisStack->ThisCapacity * sizeof(char *)); /* 重分配内存 */
    if (ThisTmpVal == NULL)
    {
        fprintf(stderr, "Memory allocation failed during stack resizing.\n");
        return 0;
    }
    ThisStack->ThisCharArr = ThisTmpVal;
    return 1;
}

int XIXI_DynamicStackPush(ThisDynamicStack *ThisStack, const char *ThisVal)
{
    if (ThisStack->ThisTop == ThisStack->ThisCapacity - 1)
    {
        if (XIXI_DynamicStackResize(ThisStack) == 0)
        {
            return 0;
        }
    }
    if (!ThisVal)
    {
        return 0;
    }
    char *ThisTmpVal = strdup(ThisVal);
    if (ThisTmpVal == NULL)
    {
        return 0; /* 内存分配失败,推入失败 */
    }
    ThisStack->ThisCharArr[++(ThisStack->ThisTop)] = ThisTmpVal;
    return 1;
}

int XIXI_DynamicStackAppendVal(ThisDynamicStack *ThisStack, const char *ThisVal)
{
    if (XIXI_DynamicStackIsEmpty(ThisStack))
    {
        XIXI_DynamicStackPush(ThisStack, ThisVal); /* 直接推入 */
        return 1;
    }
    char *TopStr = XIXI_DynamicStackPeek(ThisStack); /* 获取栈顶当前字符串并扩展内存 */
    if (!ThisVal || !TopStr)
    {
        return 0;
    }
    size_t newLength = strlen(TopStr) + strlen(ThisVal) + 1; /* 新字符串的长度 */
    char *NewChar = (char *)realloc(TopStr, newLength);      /* 重分配大小 */
    if (NewChar == NULL)
    {
        return 0; /* 内存分配失败 */
    }
    strcat(NewChar, ThisVal);                             /* 连接字符串 */
    ThisStack->ThisCharArr[ThisStack->ThisTop] = NewChar; /* 更新栈顶指针 */

    return 1;
}

char *XIXI_DynamicStackPop(ThisDynamicStack *ThisStack)
{
    if (XIXI_DynamicStackIsEmpty(ThisStack))
    {
        return NULL;
    }
    return ThisStack->ThisCharArr[(ThisStack->ThisTop)--]; /* 返回栈顶元素并更新栈顶指针 */
}

char *XIXI_DynamicStackPeek(ThisDynamicStack *ThisStack)
{
    if (XIXI_DynamicStackIsEmpty(ThisStack))
    {
        return NULL;
    }
    return ThisStack->ThisCharArr[ThisStack->ThisTop]; /* 返回栈顶元素,不更新栈顶指针 */
}

void XIXI_DynamicStackFree(ThisDynamicStack *ThisStack)
{
    if (ThisStack == NULL)
    {
        return;
    }
    for (int i = 0; i <= ThisStack->ThisTop; i++)
    {
        if (ThisStack->ThisCharArr[i] != NULL)
        {
            free(ThisStack->ThisCharArr[i]); /* 释放每个字符串 */
        }
    }
    free(ThisStack->ThisCharArr);  /* 释放指针数组 */
    ThisStack->ThisCharArr = NULL; /* 避免悬挂指针 */
}

void XIXI_DynamicStackPrint(ThisDynamicStack *ThisStack)
{
    if (XIXI_DynamicStackIsEmpty(ThisStack))
    {
        printf("Error: Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= ThisStack->ThisTop; i++)
    {
        printf("%s\n", ThisStack->ThisCharArr[i]);
    }
}

/*
 * @Author: xixi_
 * @Date: 2024-10-20 18:40:49
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-11 10:52:59
 * @FilePath: /FHMF/src/Modules/xixi/src/Stack/Stack.c
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */

#include "Stack.h"

void XIXI_StackInit(ThisStack *ThisStack)
{
    ThisStack->ThisTop = -1; /* 栈顶指针置为-1 */
}

int XIXI_StackIsEmpty(ThisStack *ThisStack)
{
    return ThisStack->ThisTop == -1; /* 判断栈顶是否等于-1即可 */
}

int XIXI_StackPush(ThisStack *ThisStack, const char *ThisVal)
{
    if (ThisStack->ThisTop == STACK_MAX_SIZE - 1)
    {
        return 0; /* 栈满,推入失败 */
    }
    if (!ThisVal)
    {
        return 0; /* 空字符,推入失败 */
    }
    char *ThisTmpVal = strdup(ThisVal);
    if (ThisTmpVal == NULL)
    {
        return 0; /* 内存分配失败,推入失败 */
    }
    ThisStack->ThisCharArr[++(ThisStack->ThisTop)] = ThisTmpVal;

    return 1;
}

int XIXI_StackAppendVal(ThisStack *ThisStack, const char *ThisVal)
{
    if (XIXI_StackIsEmpty(ThisStack))
    {
        XIXI_StackPush(ThisStack, ThisVal); /* 如果栈为空，直接推入 */
        return 1;
    }
    char *TopStr = XIXI_StackPeek(ThisStack); /* 获取栈顶当前字符串并扩展内存 */
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

char *XIXI_StackPop(ThisStack *ThisStack)
{
    if (XIXI_StackIsEmpty(ThisStack))
    {
        return NULL; /* 栈空,不能出栈 */
    }
    return ThisStack->ThisCharArr[(ThisStack->ThisTop)--]; /* 返回栈顶元素并更新栈顶指针 */
}

char *XIXI_StackPeek(ThisStack *ThisStack)
{
    if (XIXI_StackIsEmpty(ThisStack))
    {
        return NULL; /* 栈空,无法查看 */
    }
    return ThisStack->ThisCharArr[ThisStack->ThisTop]; /* 返回栈顶元素,不更新栈顶指针 */
}

void XIXI_StackPrint(ThisStack *ThisStack)
{
    if (XIXI_StackIsEmpty(ThisStack))
    {
        printf("Error: Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= ThisStack->ThisTop; i++)
    {
        printf("%s\n", ThisStack->ThisCharArr[i]);
    }
}

void XIXI_StackFree(ThisStack *ThisStack)
{
    for (int i = 0; i <= ThisStack->ThisTop; i++)
    {
        free(ThisStack->ThisCharArr[i]);  /* 释放每一个串的内存 */
        ThisStack->ThisCharArr[i] = NULL; /* 避免悬挂指针 */
    }
}

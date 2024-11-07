/*
 * @Author: xixi_
 * @Date: 2024-10-20 18:40:55
 * @LastEditors: xixi_
 * @LastEditTime: 2024-10-26 22:21:07
 * @FilePath: /FHMF/src/Modules/xixi/src/Stack/Stack.h
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */

#ifndef XIXI_STACK_H
#define XIXI_STACK_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define STACK_MAX_SIZE 100 /* 栈的最大容量 */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /* 栈的特点:迟到早退 */
    /* 基本结构 */
    typedef struct
    {
        char *ThisCharArr[STACK_MAX_SIZE]; /* 数据 */
        int ThisTop;                       /* 栈顶 */
    } ThisStack;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @brief 初始化栈
     *
     * @param ThisStack 栈结构体
     * @return 无
     * @note 暂无备注
     */
    void XIXI_StackInit(ThisStack *ThisStack);

    /**
     * @brief 判定栈是否为空
     *
     * @param ThisStack 栈结构体
     * @return 如果栈为空返回 `1`，否则返回 `0`
     * @note 暂无备注
     */
    int XIXI_StackIsEmpty(ThisStack *ThisStack);

    /**
     * @brief 将字符推入栈
     *
     * @param ThisStack 栈结构体
     * @param ThisVal 要推入的字符
     * @return  `1` 表示推入成功，返回 `0` 表示推入失败
     * @note 请注意:栈的容量是有限的
     */
    int XIXI_StackPush(ThisStack *ThisStack, const char *ThisVal);

    /**
     * @brief 将字符弹出栈
     *
     * @param ThisStack 栈结构体
     * @return 指向被弹出字符的指针
     * @note 暂无备注
     */
    char *XIXI_StackPop(ThisStack *ThisStack);

    /**
     * @brief 查看栈顶的元素
     *
     * @param ThisStack 栈结构体
     * @return 栈顶字符
     * @note 栈顶元素不会被弹出
     */
    char *XIXI_StackPeek(ThisStack *ThisStack);

    /**
     * @brief 打印栈中的元素
     *
     * @param ThisStack 栈结构体
     * @return 无
     * @note 推荐调试使用
     */
    void XIXI_StackPrint(ThisStack *ThisStack);

    /**
     * @brief 释放栈
     *
     * @param ThisStack 栈结构体
     * @return 无
     * @note 在初始化并使用栈之后，必须调用此函数释放内存!!!
     */
    void XIXI_StackFree(ThisStack *ThisStack);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // XIXI_STACK_H

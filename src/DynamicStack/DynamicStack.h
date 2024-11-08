/*
 * @Author: xixi_
 * @Date: 2024-10-20 22:02:47
 * @LastEditors: xixi_
 * @LastEditTime: 2024-10-26 22:20:47
 * @FilePath: /FHMF/src/Modules/xixi/src/DynamicStack/DynamicStack.h
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
#ifndef XIXI_DYNAMIC_STACK_H
#define XIXI_DYNAMIC_STACK_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define DYNAMIC_STACK_DEFAULT_CAPACITY 2 /* 默认容量 */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /* 定义动态栈结构体 */
    typedef struct
    {
        char **ThisCharArr; /* 存储字符串的数组 */
        int ThisTop;        /* 栈顶指针 */
        int ThisCapacity;   /* 当前栈的容量 */
    } ThisDynamicStack;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * @brief 初始化动态栈
     *
     * @param ThisStack 栈结构体
     * @return 无
     * @note 暂无备注
     */
    void XIXI_DynamicStackInit(ThisDynamicStack *ThisStack);

    /**
     * @brief 判定栈是否为空
     *
     * @param ThisStack 栈结构体
     * @return 如果栈为空返回 `1`，否则返回 `0`
     * @note 暂无备注
     */
    int XIXI_DynamicStackIsEmpty(ThisDynamicStack *ThisStack);

    /**
     * @brief 动态栈大小重分配
     *
     * @param ThisStack 栈结构体
     * @return `1` 表示重分配成功, `0` 表示失败
     * @note 暂无备注
     */
    int XIXI_DynamicStackResize(ThisDynamicStack *ThisStack);

    /**
     * @brief 将字符推入栈
     *
     * @param ThisStack 栈结构体
     * @param ThisVal 要推入的字符
     * @return `1` 表示推入成功, `0` 表示推入失败
     * @note 该动态栈支持自动扩容，请放心推入。
     */
    int XIXI_DynamicStackPush(ThisDynamicStack *ThisStack, const char *ThisVal);

    /**
     * @brief 将字符弹出栈
     *
     * @param ThisStack 栈结构体
     * @return 指向被弹出字符的指针
     * @note 返回的指针需要使用者自行管理内存。
     */
    char *XIXI_DynamicStackPop(ThisDynamicStack *ThisStack);

    /**
     * @brief 查看栈顶的元素
     *
     * @param ThisStack 栈结构体
     * @return 栈顶字符
     * @note 栈顶元素不会被弹出
     */
    char *XIXI_DynamicStackPeek(ThisDynamicStack *ThisStack);

    /**
     * @brief 释放栈
     *
     * @param ThisStack 栈结构体
     * @return 无
     * @note 在初始化并使用栈之后，必须调用此函数释放内存!!!
     */
    void XIXI_DynamicStackFree(ThisDynamicStack *ThisStack);

    /**
     * @brief 打印栈中的元素
     *
     * @param ThisStack 栈结构体
     * @return 无
     * @note 推荐调试使用
     */
    void XIXI_DynamicStackPrint(ThisDynamicStack *ThisStack);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // XIXI_DYNAMIC_STACK_H

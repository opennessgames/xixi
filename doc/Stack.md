<!--
 * @Author: xixi_
 * @Date: 2024-10-21 20:02:00
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-06 20:00:51
 * @FilePath: /FHMF/src/Modules/xixi/doc/stack.md
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved. 
-->
# 栈

## 概述

本库提供了一个简单的栈实现，支持基本的栈操作，包括初始化、推入、弹出和查看栈顶元素。栈的最大容量定义为 `STACK_MAX_SIZE`，其默认值为 100。

## 快速开始
```c
#include <xixi/Stack.h>
```

## 数据结构

### `ThisStack`

```c
typedef struct
{
    char *ThisCharArr[STACK_MAX_SIZE]; /* 数据 */
    int ThisTop;                       /* 栈顶 */
} ThisStack;
```

- **ThisCharArr**: 存储栈中元素的字符数组。
- **ThisTop**: 当前栈顶元素的索引，初始化时为 `-1` 表示栈为空。

## API

### 1. `void XIXI_StackInit`

- **描述**: 初始化栈。
- **参数**: 
  - `ThisStack`: 指向栈结构体的指针。
- **返回值**: 无返回值。
- **备注**: 暂无备注。

### 2. `int XIXI_StackIsEmpty`

- **描述**: 判定栈是否为空。
- **参数**: 
  - `ThisStack`: 指向栈结构体的指针。
- **返回值**: 
  - 返回 `1` 表示栈为空，返回 `0` 表示栈不为空。
- **备注**: 暂无备注。

### 3. `int XIXI_StackPush`

- **描述**: 将字符推入栈。
- **参数**: 
  - `ThisStack`: 指向栈结构体的指针。
  - `ThisVal`: 要推入的字符。
- **返回值**: 
  - 返回 `1` 表示推入成功，返回 `0` 表示推入失败。
- **备注**: 请注意栈的容量是有限的。

### 4. `char *XIXI_StackPop`

- **描述**: 将字符弹出栈。
- **参数**: 
  - `ThisStack`: 指向栈结构体的指针。
- **返回值**: 返回指向被弹出字符的指针。
- **备注**: 暂无备注。

### 5. `char *XIXI_StackPeek`

- **描述**: 查看栈顶的元素。
- **参数**: 
  - `ThisStack`: 指向栈结构体的指针。
- **返回值**: 返回栈顶字符的指针。
- **备注**: 栈顶元素不会被弹出。

### 6. `void XIXI_StackPrint`

- **描述**: 打印栈中的元素。
- **参数**: 
  - `ThisStack`: 指向栈结构体的指针。
- **返回值**: 无返回值。
- **备注**: 推荐用于调试。

### 7. `void XIXI_StackFree`

- **描述**: 释放栈。
- **参数**: 
  - `ThisStack`: 指向栈结构体的指针。
- **返回值**: 无返回值。
- **备注**: 在初始化并使用栈之后，必须调用此函数释放内存!!!

## 常量定义

### `#define STACK_MAX_SIZE 100`

- **描述**: 定义栈的最大容量为 100。
## 实例
```c
int main()
{
    ThisStack s; /* 创建一个栈 */
    XIXI_StackInit(&s); /* 初始化 */
    XIXI_StackPush(&s, "jkda"); /* 向栈推入jkda */
    XIXI_StackPrint(&s); /* 打印整个栈 */
    XIXI_StackFree(&s); /* 释放栈 */
    return 0;
}
```

## 结束语

本文档描述了基本的栈数据结构及其操作函数。使用时，请确保遵循函数的输入输出要求，以避免潜在的错误。
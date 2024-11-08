/*
 * @Author: xixi_
 * @Date: 2024-10-21 01:44:04
 * @LastEditors: xixi_
 * @LastEditTime: 2024-10-21 16:55:27
 * @FilePath: /FHMF/src/Modules/xixi/URL/URL.c
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */

#include "URL.h"

char *XIXI_URLEncode(const char *ThisStr)
{
    char *ThisEncoded = malloc(strlen(ThisStr) * 3 + 1); /* 为编码后的字符串分配内存 */
    if (ThisEncoded == NULL)
    {
        return NULL;
    }
    char *p = ThisEncoded;

    while (*ThisStr)
    {
        if (isalnum((unsigned char)*ThisStr) || *ThisStr == '-' || *ThisStr == '_' || *ThisStr == '.' || *ThisStr == '~')
        {
            *p++ = *ThisStr; /* 保留字符 */
        }
        else
        {
            p += sprintf(p, "%%%02X", (unsigned char)*ThisStr); /* 转换为百分号编码 */
        }
        ThisStr++;
    }
    *p = '\0'; /* 终止字符串 */
    return ThisEncoded;
}

char *XIXI_URLDecode(const char *ThisStr)
{
    char *ThisDecoded = malloc(strlen(ThisStr) + 1); /* 为解码后的字符串分配内存 */
    if (ThisDecoded == NULL)
    {
        return NULL;
    }
    char *p = ThisDecoded;

    while (*ThisStr)
    {
        if (*ThisStr == '%')
        {
            /* 读取百分号后面的两个十六进制数字 */
            int value;
            if (sscanf(ThisStr + 1, "%2x", &value) != 1)
            {
                free(ThisDecoded); /* 无效编码 */
                return NULL;
            }
            *p++ = (char)value; /* 将其转换为字符 */
            ThisStr += 3;       /* 跳过百分号和两个十六进制数字 */
        }
        else if (*ThisStr == '+')
        {
            *p++ = ' '; /* 将加号转换为空格 */
            ThisStr++;
        }
        else
        {
            *p++ = *ThisStr; /* 直接复制字符 */
            ThisStr++;
        }
    }
    *p = '\0'; /* 终止字符串 */
    return ThisDecoded;
}

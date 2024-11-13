/*
 * @Author: xixi_
 * @Date: 2024-10-23 20:13:10
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-13 16:28:40
 * @FilePath: /FHMF/src/Modules/xixi/src/CRC32/CRC32.h
 * Copyright (c) 2020-2024 by xixi_ , All Rights Reserved.
 */
#ifndef _XIXI_CRC32_H_
#define _XIXI_CRC32_H_
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define CRC32_POLYNOMIAL 0xEDB88320 // CRC32 polynomial used for calculation
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * @brief 生成CRC32查找表
     *
     * @param ThisCrc32Table 指向空的CRC32表的指针
     * @return 无
     * @note 建议使用256长度，例如 ThisCrc32Table[256]
     */
    void XIXI_CRC32GenerateTable(uint32_t *ThisCrc32Table);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * @brief 计算文件的CRC32值，并返回格式化后的字符串
     *
     * @param ThisFilePath 文件的路径
     * @param ThisCrc32Table 指向已经生成的CRC32查找表的指针
     * @return 格式化后的CRC32字符串，返回的字符串需要调用者手动释放内存
     * @note 如果无法打开文件或分配内存失败，将返回NULL;禁止使用`printf("%s\n",XIXI_CRC32File(ThisFilePath, ThisCrc32Table));`
     */
    char *XIXI_CRC32File(const char *ThisFilePath, uint32_t *ThisCrc32Table);

    /**
     * @brief 计算大文件的CRC32值，并返回格式化后的字符串（分块读取）
     *
     * @param ThisFilePath 文件的路径
     * @param ThisCrc32Table 指向已经生成的CRC32查找表的指针
     * @param ThisBufferSize 缓冲区大小，用于分块读取文件
     * @return 格式化后的CRC32字符串，返回的字符串需要调用者手动释放内存
     * @note 如果无法打开文件或分配内存失败，将返回NULL;禁止使用`printf("%s\n",XIXI_CRC32BigFile(ThisFilePath, ThisCrc32Table,ThisBufferSize));`
     */
    char *XIXI_CRC32BigFile(const char *ThisFilePath, uint32_t *ThisCrc32Table, int ThisBufferSize);

    /**
     * @brief 计算字符串的CRC32值，并返回格式化后的字符串
     *
     * @param ThisChar 指向要计算CRC32的字符串
     * @param ThisCrc32Table 指向已经生成的CRC32查找表的指针
     * @return 格式化后的CRC32字符串，返回的字符串需要调用者手动释放内存
     * @note 禁止使用 `printf("%s\n",XIXI_CRC32Char(ThisChar, ThisCrc32Table));`
     */
    char *XIXI_CRC32Char(const char *ThisChar, uint32_t *ThisCrc32Table);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // _XIXI_CRC32_H_

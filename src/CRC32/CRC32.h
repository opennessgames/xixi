/*
 * @Author: xixi_
 * @Date: 2024-10-23 20:13:10
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-05 19:58:22
 * @FilePath: /FHMF/src/Modules/xixi/src/CRC32/CRC32.h
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
#ifndef XIXI_CRC32_H
#define XIXI_CRC32_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
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
     * @brief 计算文件的CRC值
     *
     * @param ThisFilePath 文件的路径
     * @param ThisCrc32Table CRC32查找表
     * @return 文件的CRC32值
     * @note 请释放返回的结果，禁止使用 `printf("%s\n",XIXI_CalcFileCrc32(ThisFilePath, ThisCrc32Table));`
     */
    char *XIXI_CRC32File(const char *ThisFilePath, uint32_t *ThisCrc32Table);

    /**
     * @brief 计算字符串的CRC值
     *
     * @param ThisChar 输入的字符串
     * @param ThisCrc32Table CRC32查找表
     * @return 字符串的CRC32值
     * @note 请释放返回的结果，禁止使用 `printf("%s\n",XIXI_CalcCharCrc32(ThisChar, ThisCrc32Table));`
     */
    char *XIXI_CRC32Char(const char *ThisChar, uint32_t *ThisCrc32Table);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // XIXI_CRC32_H
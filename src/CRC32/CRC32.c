/*
 * @Author: xixi_
 * @Date: 2024-10-23 20:13:17
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-12 22:41:59
 * @FilePath: /FHMF/src/Modules/xixi/src/CRC32/CRC32.c
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
#include "CRC32.h"
/* CRC32表生成 */
void XIXI_CRC32GenerateTable(uint32_t *ThisCrc32Table)
{
    uint32_t c;
    for (int i = 0; i < 256; i++)
    {
        c = i;
        for (int j = 8; j > 0; j--)
        {
            c = c & 1 ? (c >> 1) ^ CRC32_POLYNOMIAL : c >> 1;
        }
        ThisCrc32Table[i] = c;
    }
}

/* CRC32 计算函数（核心计算逻辑） */
uint32_t XIXI_CRC32Compute(const void *ThisData, size_t ThisLength, uint32_t *ThisCrc32Table)
{
    if (ThisData == NULL || ThisCrc32Table == NULL)
    {
        return 0; /* 错误：输入无效 */
    }

    uint32_t crc = 0xFFFFFFFF;
    const unsigned char *bytes = (const unsigned char *)ThisData;

    for (size_t i = 0; i < ThisLength; i++)
    {
        crc = (crc >> 8) ^ ThisCrc32Table[(crc ^ bytes[i]) & 0xFF];
    }

    return crc ^ 0xFFFFFFFF; /* 返回 CRC32 结果 */
}

/* 将 CRC32 结果格式化为字符串 */
char *XIXI_CRC32ToString(uint32_t ThisCrc)
{
    char *crc_str = (char *)malloc(9); /* 8 hex digits + 1 null terminator */
    if (crc_str == NULL)
    {
        perror("Memory allocation failed");
        return NULL; /* Return NULL if memory allocation fails */
    }

    snprintf(crc_str, 9, "%08X", ThisCrc);
    return crc_str;
}

/* 计算内存中的数据的 CRC32（计算和格式化为字符串） */
char *XIXI_CRC32Calc(const void *ThisData, size_t ThisLength, uint32_t *ThisCrc32Table)
{
    uint32_t crc = XIXI_CRC32Compute(ThisData, ThisLength, ThisCrc32Table);
    return XIXI_CRC32ToString(crc); /* 返回格式化后的 CRC32 字符串 */
}

/* 计算文件的 CRC32（读取文件内容并计算 CRC32） */
char *XIXI_CRC32File(const char *ThisFilePath, uint32_t *ThisCrc32Table)
{
    if (ThisFilePath == NULL || ThisCrc32Table == NULL)
    {
        return NULL;
    }

    FILE *file = fopen(ThisFilePath, "rb");
    if (file == NULL)
    {
        perror("Unable to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = (unsigned char *)malloc(fileSize);
    if (buffer == NULL)
    {
        fclose(file);
        perror("Memory allocation failed");
        return NULL;
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);

    char *crcResult = XIXI_CRC32Calc(buffer, fileSize, ThisCrc32Table);
    free(buffer);
    return crcResult;
}

/* 计算大文件的 CRC32（分块读取文件内容并计算 CRC32） */
char *XIXI_CRC32BigFile(const char *ThisFilePath, uint32_t *ThisCrc32Table, int ThisBufferSize)
{
    if (ThisFilePath == NULL || ThisCrc32Table == NULL)
    {
        return NULL;
    }

    FILE *file = fopen(ThisFilePath, "rb");
    if (file == NULL)
    {
        perror("Unable to open file");
        return NULL;
    }

    uint32_t crc = 0xFFFFFFFF;
    unsigned char buffer[ThisBufferSize];

    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        for (size_t i = 0; i < bytesRead; i++)
        {
            uint32_t tableIndex = (crc ^ buffer[i]) & 0xFF;
            crc = (crc >> 8) ^ ThisCrc32Table[tableIndex];
        }
    }

    fclose(file);

    /* 反转 CRC32 值并返回格式化的 CRC32 字符串 */
    return XIXI_CRC32ToString(crc ^ 0xFFFFFFFF);
}

/* 计算字符串的 CRC32（直接对字符串计算 CRC32） */
char *XIXI_CRC32Char(const char *ThisChar, uint32_t *ThisCrc32Table)
{
    if (ThisChar == NULL || ThisCrc32Table == NULL)
    {
        return NULL;
    }
    return XIXI_CRC32Calc(ThisChar, strlen(ThisChar), ThisCrc32Table);
}

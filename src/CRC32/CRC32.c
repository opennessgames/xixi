/*
 * @Author: xixi_
 * @Date: 2024-10-23 20:13:17
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-05 19:57:28
 * @FilePath: /FHMF/src/Modules/xixi/src/CRC32/CRC32.c
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
#include "CRC32.h"

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

char *XIXI_CRC32Calc(const void *ThisData, size_t ThisLength, uint32_t *ThisCrc32Table)
{
    if (ThisData == NULL || ThisCrc32Table == NULL)
    {
        return NULL; // Check for valid input
    }

    uint32_t crc = 0xFFFFFFFF;
    const unsigned char *bytes = (const unsigned char *)ThisData;

    for (size_t i = 0; i < ThisLength; i++)
    {
        crc = (crc >> 8) ^ ThisCrc32Table[(crc ^ bytes[i]) & 0xFF];
    }

    char *crc_str = (char *)malloc(9); // 8 hex digits + 1 null terminator
    if (crc_str == NULL)
    {
        perror("Memory allocation failed");
        return NULL; // Return NULL if memory allocation fails
    }

    snprintf(crc_str, 9, "%08X", crc ^ 0xFFFFFFFF);
    return crc_str; // Return the CRC value as a string
}

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

char *XIXI_CRC32Char(const char *ThisChar, uint32_t *ThisCrc32Table)
{
    if (ThisChar == NULL || ThisCrc32Table == NULL)
    {
        return NULL;
    }
    return XIXI_CRC32Calc(ThisChar, strlen(ThisChar), ThisCrc32Table);
}

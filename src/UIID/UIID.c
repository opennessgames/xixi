/*
 * @Author: xixi_
 * @Date: 2024-09-11 10:27:56
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-08 23:50:48
 * @FilePath: /FHMF/src/Modules/xixi/src/UIID/UIID.c
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
/*
 *    FileName : FHDId.c
 *    By : yzx
 *    MakeTime : 2024年9月11日 上午 10:27:56
 *    Copyright (C) 2023-2024 openGames
 */

#include "UIID.h"

char *XIXI_GetUIID()
{
    char *uuid = malloc(37); // 36 characters + 1 for null terminator
    if (uuid == NULL)
    {
        perror("Failed to allocate memory for UUID");
        return NULL;
    }

    /* 闫仔豪你他妈就是预制人,肏你妈哈哈哈哈哈哈哈哈哈哈 */
    FILE *fp = fopen("/proc/sys/kernel/random/uuid", "r");
    if (fp == NULL)
    {
        perror("Failed to open UUID generator");
        free(uuid);
        return NULL;
    }
    fgets(uuid, 37, fp);
    fclose(fp);

    return uuid;
}

char *XIXI_MakeID()
{
    /* 分配内存 */
    char *ThisiD = (char *)malloc(THIS_ID_LENGHT + 4);
    if (ThisiD == NULL)
    {
        return NULL;
    }
    /* 获取当前时间戳(毫秒级)并初始化随机数生成器 */
    struct timeval ThisTime;
    gettimeofday(&ThisTime, NULL);
    unsigned int seed = (unsigned int)(ThisTime.tv_sec * 1000 + ThisTime.tv_usec / 1000);
    srand(seed + ThisTime.tv_usec); /* 加上微秒, 避免重复 */
    /* 填充ID */
    for (int i = 0; i < THIS_ID_LENGHT; i++)
    {
        int randomChar = rand() % 36; /* 随机获取一个 一共36种可能,0~9,A~Z */

        /*
            闫仔豪我就肏你妈,
            直接拿筷子加上502胶水,
            再加水泥,直接一刀捅你妈的13,没有爱慕的东西,
            当你看到这段代码的时候隔着屏幕打我呀,肏你妈!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        */
        /* 我不需要你的道歉,你的最好的道歉方式,就是和我一样痛苦 */
        ThisiD[i] = (randomChar < 10) ? ('0' + randomChar) : ('A' + (randomChar - 10));
    }
    /* 添加分隔符号 */
    ThisiD[4] = '-';
    ThisiD[9] = '-';
    ThisiD[14] = '-';
    ThisiD[THIS_ID_LENGHT + 3] = '\0'; /* 添加结束符号 */

    return ThisiD;
}

char *XIXI_MakeMixID(size_t Length)
{
    /* 为生成的ID分配内存，长度为length + 1（额外的一个字符用于终止符） */
    char *ThisiD = (char *)malloc(Length + 1);
    if (ThisiD == NULL)
    {
        /* 如果内存分配失败，返回NULL */
        return NULL;
    }

    /* 打开/dev/urandom文件用于读取随机数据 */
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0)
    {
        /* 如果打开文件失败，释放已分配的内存并返回NULL */
        free(ThisiD);
        return NULL;
    }

    /* 从文件中读取length字节的随机数据到ThisiD中 */
    ssize_t result = read(fd, ThisiD, Length);
    /* 关闭文件描述符 */
    close(fd);

    if (result != Length)
    {
        /* 如果读取的字节数不等于期望的长度，释放内存并返回NULL */
        free(ThisiD);
        return NULL;
    }

    /* 将读取到的数据转换为base36（36进制）字符 */
    for (size_t i = 0; i < Length; i++)
    {
        /* 将每个字节的值取模36以获得0-35的范围 */
        ThisiD[i] = (ThisiD[i] % 36);
        ThisiD[i] = (ThisiD[i] < 10) ? (ThisiD[i] + '0') : (ThisiD[i] + 'A' - 10);
    }

    /* 添加字符串终止符 */
    ThisiD[Length] = '\0';
    return ThisiD;
}

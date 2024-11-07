/*
 * @Author: xixi_
 * @Date: 2024-09-11 10:27:56
 * @LastEditors: xixi_
 * @LastEditTime: 2024-10-26 21:59:25
 * @FilePath: /FHMF/src/Modules/xixi/src/UIID/UIID.h
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
/*
 *    FileName : FHDId.h
 *    By : yzx
 *    MakeTime : 2024年9月11日 上午 10:27:56
 *    Copyright (C) 2023-2024 openGames
 */

#ifndef XIXI_UIID_H
#define XIXI_UIID_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define THIS_ID_LENGHT 19 /* ID长度 */
    /*
    XIXI_MakeID 使用 srand 和 rand 函数生成伪随机数，基于当前时间戳进行种子初始化。这种方法的随机性受限于 rand 函数的质量，并且可以受到时间戳的影响，可能导致在短时间内生成重复的ID。
    XIXI_MakeMixID 则从 /dev/urandom 读取随机字节，这是一种更高质量的随机数生成方法，不容易受到时间戳的影响，因此具有更强的随机性。它直接从系统的伪随机数生成器中获取数据，通常被认为更安全。
    总体上，XIXI_MakeMixID 提供了更好的随机性和更强的安全性。
    */

    /**
     * @brief 生成一个随机的37位ID，使用Linux内核的随机数生成器。
     *
     * @return 指向动态分配的字符串的指针，该字符串包含生成的37位ID。
     *
     * @note 调用者需负责释放返回的内存。请勿使用 `printf("%s", XIXI_GetUIID());` 直接打印返回值。
     */
    char *XIXI_GetUIID(void);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @brief 根据时间戳生成ID
     *
     * @param NULL 无参数
     * @return 一个16位平均分配且带横杠的ID
     *
     * \note （需要调用者负责释放内存） 不能 `printf("%s",XIXI_MakeID());`
     */
    extern char *XIXI_MakeID(void);

    /**
     * @brief 生成指定长度的随机ID
     *
     * @param length 生成的ID的长度（不包括终止符）
     * @return 一个由随机字符组成的ID，字符范围为0-9和A-Z（需要调用者负责释放内存）。如果内存分配或随机数据生成失败，则返回NULL。
     */
    extern char *XIXI_MakeMixID(size_t Length);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // XIXI_UIID_H
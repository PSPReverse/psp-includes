/** @file
 * PSP interface headers - Boot ROM service page structure.
 */

/*
 * Copyright (C) 2020 Alexander Eichner <alexander.eichner@campus.tu-berlin.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __include_boot_rom_svc_page_h
#define __include_boot_rom_svc_page_h

#include <common/cdefs.h>


/**
 * The boot ROM service page structure as known, residing at 0x3f000.
 * Set up by the on chip bootloader.
 */
#pragma pack(1)
typedef union PSPROMSVCPG
{
    /** Byte view. */
    uint8_t                     ab[_4K];
    /** Structured view. */
    struct
    {
        /** 0x00-0x40f: The flash directory structure (@todo Complete). */
        uint8_t                 abFfsDir[64 * 16 + 16];
        /** 0x410-0x64f: AMD public key. */
        uint8_t                 abAmdPubKey[576];
        /** 0x650-0xa13: Unknown. */
        uint8_t                 abUnknown0[964];
        /** 0xa14: Boot mode (everything < 2 means signature checks disabled). */
        uint32_t                u32BootMode;
        /** 0xa18 - 0xa4f: Unknown. */
        uint8_t                 abUnknown1[56];
        /** 0xa50: Physical die ID of the PSP. */
        uint8_t                 idPhysDie;
        /** 0xa51: Socket ID. */
        uint8_t                 idSocket;
        /** 0xa52: Package type. */
        uint8_t                 u8PkgType;
        /** 0xa53: System socket count. */
        uint8_t                 cSysSockets;
        /** 0xa54: Unknown. */
        uint8_t                 bUnk0;
        /** 0xa55: Number of dies per socket. */
        uint8_t                 cDiesPerSocket;
    } Fields;
} PSPROMSVCPG;
#pragma pack()
/** Pointer to a boot ROM service page. */
typedef PSPROMSVCPG *PPSPROMSVCPG;
/** Pointer to a const boot ROM service page. */
typedef const PSPROMSVCPG *PCPSPROMSVCPG;


#endif

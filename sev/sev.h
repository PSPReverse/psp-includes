/** @file
 * PSP SEV - interface header.
 */

/*
 * Copyright (C) 2019 Alexander Eichner <alexander.eichner@campus.tu-berlin.de>
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
#ifndef __include_sev_h
#define __include_sev_h

#if defined(IN_PSP)
# include <common/types.h>
#elif defined(IN_LINUX)
# include <linux/types.h>

typedef uint64_t X86PADDR;
#endif

/**
 * SEV Command buffer structure.
 */
typedef struct SEVCMDBUF
{
    /** The command identifier. */
    uint32_t                    idCmd;
    /** Low part of the X86 physical address of the command buffer. */
    uint32_t                    PhysX86CmdBufLow;
    /** High part of the X86 physical address of the command buffer. */
    uint32_t                    PhysX86CmdBufHigh;
} SEVCMDBUF;
/** Pointer to a SEV command buffer structure. */
typedef SEVCMDBUF *PSEVCMDBUF;

typedef struct SEVREQPLATFORMSTATUS
{
    uint8_t             u8VerMaj;
    uint8_t             u8VerMin;
    uint8_t             u8State;
    uint8_t             u8OwnerFlags;
    uint32_t            u32CfgFlags;
    uint32_t            u32GstCnt;
} SEVREQPLATFORMSTATUS;
typedef SEVREQPLATFORMSTATUS *PSEVREQPLATFORMSTATUS;

/**
 * Union of all requests.
 */
typedef union SEVREQ
{
    SEVREQPLATFORMSTATUS        PlatformSts;
} SEVREQ;

#endif

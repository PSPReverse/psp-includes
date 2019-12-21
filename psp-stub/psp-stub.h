/** @file
 * PSP stub - interface header.
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
#ifndef __include_psp_stub_h
#define __include_psp_stub_h

#if defined(IN_PSP)
# include <common/types.h>
#elif defined(IN_LINUX)
# include <linux/types.h>

typedef uint64_t X86PADDR;
#endif

#define PSP_STUB_LOAD_BIN   0xa0
#define PSP_STUB_EXEC_BIN   0xa1
#define PSP_STUB_SMN_READ   0xa2
#define PSP_STUB_SMN_WRITE  0xa3
#define PSP_STUB_PSP_READ   0xa4
#define PSP_STUB_PSP_WRITE  0xa5
#define PSP_STUB_CALL_SVC   0xa6
#define PSP_STUB_QUERY_INFO 0xa7

#define PSP_STUB_REQ_FIRST  PSP_STUB_LOAD_BIN
#define PSP_STUB_REQ_LAST   PSP_STUB_QUERY_INFO

typedef struct PSPSTUBREQHDR
{
    /** The CCD to execute the request on. */
    uint32_t                    idCcd;
    /** The status code on return. */
    int32_t                     i32Sts;
} PSPSTUBREQHDR;
/** Pointer to a command header. */
typedef PSPSTUBREQHDR *PPSPSTUBREQHDR;
/** Pointer to a const command header. */
typedef const PSPSTUBREQHDR *PCPSPSTUBREQHDR;

typedef struct PSPSTUBREQLOADBIN
{
    /** Request header. */
    PSPSTUBREQHDR               Hdr;
    /** The X86 physical address to load. */
    X86PADDR                    PhysX86AddrLoad;
    /** Size of the binary to load. */
    uint32_t                    cbBinary;
} PSPSTUBREQLOADBIN;
typedef PSPSTUBREQLOADBIN *PPSPSTUBREQLOADBIN;
typedef const PSPSTUBREQLOADBIN *PCPSPSTUBREQLOADBIN;

typedef struct PSPSTUBREQEXECBIN
{
    /** Request header. */
    PSPSTUBREQHDR               Hdr;
    /** Physical address passed to executed binary. */
    X86PADDR                    PhysX8AddrExec;
} PSPSTUBREQEXECBIN;
typedef PSPSTUBREQEXECBIN *PPSPSTUBREQEXECBIN;
typedef const PSPSTUBREQEXECBIN *PCPSPSTUBREQEXECBIN;

typedef struct PSPSTUBREQSMNRW
{
    /** Request header. */
    PSPSTUBREQHDR               Hdr;
    /** The CCD to target. */
    uint32_t                    idCcdTgt;
    /** Address of the register to read/write. */
    uint32_t                    u32Addr;
    /** The value to write or read value on success. */
    uint64_t                    u64Val;
    /** Size of the value to read/write. */
    uint32_t                    cbVal;
} PSPSTUBREQSMNRW;
typedef PSPSTUBREQSMNRW *PPSPSTUBREQSMNRW;
typedef const PSPSTUBREQSMNRW *PCPSPSTUBREQSMNRW;

typedef struct PSPSTUBREQPSPRW
{
    /** Request header. */
    PSPSTUBREQHDR               Hdr;
    /** PSP address to operate on. */
    uint32_t                    u32Addr;
    /** Size to copy. */
    uint32_t                    cbCopy;
    /** x86 address to operate on. */
    X86PADDR                    PhysX86Addr;
} PSPSTUBREQPSPRW;
typedef PSPSTUBREQPSPRW *PPSPSTUBREQPSPRW;
typedef const PSPSTUBREQPSPRW *PCPSPSTUBREQPSPRW;

typedef struct PSPSTUBREQCALLSVC
{
    /** Request header. */
    PSPSTUBREQHDR               Hdr;
    /** The syscall to execute. */
    uint32_t                    idxSyscall;
    /** R0 argument. */
    uint32_t                    u32R0;
    /** R1 argument. */
    uint32_t                    u32R1;
    /** R2 argument. */
    uint32_t                    u32R2;
    /** R3 argument. */
    uint32_t                    u32R3;
    /** Return value. */
    uint32_t                    u32R0Return;
} PSPSTUBREQCALLSVC;
typedef PSPSTUBREQCALLSVC *PPSPSTUBREQCALLSVC;
typedef const PSPSTUBREQCALLSVC *PCPSPSTUBREQCALLSVC;

typedef struct PSPSTUBREQQUERYINFO
{
    /** Request header. */
    PSPSTUBREQHDR               Hdr;
    /** PSP address of the scratch buffer. */
    uint32_t                    u32PspScratchAddr;
    /** Size of the scratch buffer in bytes. */
    uint32_t                    cbScratch;
} PSPSTUBREQQUERYINFO;
typedef PSPSTUBREQQUERYINFO *PPSPSTUBREQQUERYINFO;
typedef const PSPSTUBREQQUERYINFO *PCPSPSTUBREQQUERYINFO;


/**
 * Union of all requests.
 */
typedef union PSPSTUBREQ
{
    /** Header. */
    PSPSTUBREQHDR             Hdr;
    PSPSTUBREQLOADBIN         LoadBin;
    PSPSTUBREQEXECBIN         ExecBin;
    PSPSTUBREQSMNRW           SmnRw;
    PSPSTUBREQPSPRW           PspRw;
    PSPSTUBREQCALLSVC         SvcCall;
    PSPSTUBREQQUERYINFO       QueryInfo;
} PSPSTUBREQ;

#endif

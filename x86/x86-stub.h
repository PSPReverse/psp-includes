/** @file
 * PSP x86 interfaces - x86 stub mailbox interfaces.
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
#ifndef PSP_INCLUDED_x86_x86_stub_h
#define PSP_INCLUDED_x86_x86_stub_h

#include <common/cdefs.h>
#include <common/types.h>

/** The x86 stub mailbox area start. */
#define X86_STUB_MBX_START              0x9c00000

/**
 * Available requests.
 */
typedef enum X86STUBMBXREQ
{
    /** Invalid request. */
    X86STUBMBXREQ_INVALID = 0,
    /** Read from the given I/O port. */
    X86STUBMBXREQ_IOPORT_READ,
    /** Write to the given I/O port. */
    X86STUBMBXREQ_IOPORT_WRITE,
    /** 32bit hack. */
    X86STUBMBXREQ_32BIT_HACK = 0x7fffffff
} X86STUBMBXREQ;


/**
 * The x86 mailbox.
 */
typedef struct X86STUBMBX
{
    /** Magic to indicate availability of a new request or readiness to accept a new command. */
    volatile uint32_t           u32MagicReqResp;
    /** The request to perform. */
    X86STUBMBXREQ               enmReq;
    /** Request dependent data. */
    union
    {
        /** I/O port access. */
        struct
        {
            /** The I/O port to access (32bit for easier alignment). */
            uint32_t            u32IoPort;
            /** Access size (1, 2 or 4 bytes). */
            uint32_t            cbAccess;
            /** The data to write or the data being read upon completion. */
            uint32_t            u32Val;
        } IoPort;
    } u;
} X86STUBMBX;
/** Pointer to the x86 mailbox. */
typedef X86STUBMBX *PX86STUBMBX;
/** Pointer to a const x86 mailbox. */
typedef const X86STUBMBX *PCX86STUBMBX;


/** X86 stub is up and running ready to accept new requests. */
#define X86STUB_MBX_MAGIC_READY     0x19701027 /* Jonathan Stroud */
/** Write to indicate that a new request is available for the x86 stub to process. */
#define X86STUB_MBX_MAGIC_REQ       0x18021129 /* Wilhelm Hauff */

#endif /* !PSP_INCLUDED_x86_x86_stub_h */

/** @file
 * PSP common - Type definitions shared between projects.
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
#ifndef INCLUDED_common_types_h
#define INCLUDED_common_types_h

#ifdef IN_PSP
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

#define UINT32_MAX ((uint32_t)0xffffffff)

typedef char      int8_t;
typedef short     int16_t;
typedef int       int32_t;
typedef long long int64_t;

typedef uint32_t size_t;
typedef int32_t  ssize_t;

typedef uint32_t uintptr_t;

#define NULL ((void *)0)

typedef uint8_t bool;
#define true  1
#define false 0
#else
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
#endif

/** PSP status code. */
typedef int32_t  PSPSTS;
/** A SMN (System Management Network) address. */
typedef uint32_t SMNADDR;
/** A generic PSP memory address, avoid in new code whenever possible. */
typedef uint32_t PSPADDR;
/** A virtual PSP memory address. */
typedef uint32_t PSPVADDR;
/** A physical PSP memory address. */
typedef uint32_t PSPPADDR;
/** A x86 physical address. */
typedef uint64_t X86PADDR;
#define NIL_X86PADDR (~0ULL)

/** R0 pointer. */
typedef uint64_t R0PTR;


/**
 * PSP address space type.
 */
typedef enum PSPADDRSPACE
{
    /** Invalid address space. */
    PSPADDRSPACE_INVALID = 0,
    /** Generic PSP address. */
    PSPADDRSPACE_PSP,
    /** PSP SRAM. */
    PSPADDRSPACE_PSP_MEM,
    /** PSP MMIO. */
    PSPADDRSPACE_PSP_MMIO,
    /** SMN. */
    PSPADDRSPACE_SMN,
    /** Generic x86 address. */
    PSPADDRSPACE_X86,
    /** x86 standard memory. */
    PSPADDRSPACE_X86_MEM,
    /** x86 MMIO. */
    PSPADDRSPACE_X86_MMIO,
    /** 32bit hack. */
    PSPADDRSPACE_32BIT_HACK = 0x7fffffff
} PSPADDRSPACE;

#endif /* !INCLUDED_common_types_h*/

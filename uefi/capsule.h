/** @file
 * PSP UEFI interfaces - CapsuleHeader definitions.
 */

/*
 * Copyright (C) 2021 Alexander Eichner <alexander.eichner@campus.tu-berlin.de>
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
#ifndef INCLUDED_uefi_capsule_h
#define INCLUDED_uefi_capsule_h

#include <common/cdefs.h>

/**
 * UEFI capsule header definition.
 */
typedef struct UEFICAPSULEHEADER
{
    /** The GUID defining the capsule content. */
    uint8_t                     abCapsuleGuid[16]; /** @todo proper GUID type. */
    /** Size of the capsule header in bytes. */
    uint32_t                    cbCapsuleHdr;
    /** Flags defining capsule attributes. */
    uint32_t                    fAttributes;
    /** Size of the capsule image in bytes. */
    uint32_t                    cbCapsuleImage;
} UEFICAPSULEHEADER;
/** Pointer to an UEFI capsule header. */
typedef UEFICAPSULEHEADER *PUEFICAPSULEHEADER;
/** Pointer to a const UEFI capsule header. */
typedef const UEFICAPSULEHEADER *PCUEFICAPSULEHEADER;

/** UEFI2 capsule GUID */
#define EFI2_CAPSULE_GUID { 0x8b, 0xa6, 0x3c, 0x4a, 0x23, 0x77, 0xfb, 0x48, 0x80, 0x3d, 0x57, 0x8c, 0xc1, 0xfe, 0xc4, 0x4d } /** @todo Proper GUID type. */

#endif /* !INCLUDED_uefi_capsule_h */

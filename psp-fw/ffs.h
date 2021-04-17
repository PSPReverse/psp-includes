/** @file
 * PSP interface headers - "Flash FileSystem" related structures.
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
#ifndef PSP_INCLUDED_psp_fw_ffs_h
#define PSP_INCLUDED_psp_fw_ffs_h

#include <common/cdefs.h>
#include <common/types.h>


/** An absolute flash address. */
typedef uint32_t PSPFFSADDR;

/**
 * The firmware entry table (FET).
 */
typedef struct PSPFFSFET
{
    /** The magic identifying the FET. */
    uint32_t                        u32Magic;
    /** Embedded Controller ROM address. */
    PSPFFSADDR                      FfsAddrEcRom;
    /** GEC ROM address. */
    PSPFFSADDR                      FfsAddrGecRom;
    /** USB3 ROM address. */
    PSPFFSADDR                      FfsAddrUsb3Rom;
    /** 1st PSP directory address. */
    PSPFFSADDR                      FfsAddrPspDir;
    /** 2nd PSP or combo directory address. */
    PSPFFSADDR                      FfsAddrPspOrComboDir;
    /** BIOS directory address. */
    PSPFFSADDR                      FfsAddrBiosDir;
} PSPFFSFET;
/** Pointer to a firmware entry table. */
typedef PSPFFSFET *PPSPFFSFET;
/** Pointer to a const firmware entry table. */
typedef const PSPFFSFET *PCPSPFFSFET;


/** The FET magic. */
#define PSP_FFS_FET_MAGIC           0x55aa55aa


/**
 * Directory entry types.
 */
typedef enum PSPFFSDIRENTRYTYPE
{
    /** AMD public key. */
    PSPFFSDIRENTRYTYPE_AMD_PUBLIC_KEY         = 0x00,
    /** Off chip bootloader. */
    PSPFFSDIRENTRYTYPE_PSP_OFF_CHIP_BL        = 0x01,
    /** Entry point to 64bit PSP Soft Fuse Chain. */
    PSPFFSDIRENTRYTYPE_AMD_SOFT_FUSE_CHAIN_01 = 0x0b,
    /** Second level PSP directory. */
    PSPFFSDIRENTRYTYPE_PSP_DIR_L2             = 0x40,
    /** Second level BL directory. */
    PSPFFSDIRENTRYTYPE_BL_DIR_L2              = 0x70,
    /** Blow up enum to 32bit. */
    PSPFFSDIRENTRYTYPE_32BIT_HACK             = 0x7fffffff
} PSPFFSDIRENTRYTYPE;
/** Pointer to an directory entry type. */
typedef PSPFFSDIRENTRYTYPE *PPSPFFSDIRENTRYTYPE;


/**
 * PSP firmware directory entry.
 */
typedef struct PSPFFSDIRENTRY
{
    /** Entry type. */
    PSPFFSDIRENTRYTYPE              enmType;
    /** Size of the entry in bytes. */
    uint32_t                        cbEntry;
    /** Base address of the entry in flash. */
    PSPFFSADDR                      FfsAddrStart;
    /** Reserved. */
    uint32_t                        u32Rsvd0;
} PSPFFSDIRENTRY;
/** Pointer to a directory entry. */
typedef PSPFFSDIRENTRY *PPSPFFSDIRENTRY;
/** Pointer to a const directory entry. */
typedef const PSPFFSDIRENTRY *PCPSPFFSDIRENTRY;


/**
 * PSP firmware directory header.
 */
typedef struct PSPFFSDIRHDR
{
    /** Magic for the directory ('PSP$'). */
    uint32_t                        u32Magic;
    /** Fletcher checksum. */
    uint32_t                        u32ChkSumFletcher32;
    /** Number of directory entries following. */
    uint32_t                        cEntries;
    /** Reserved. */
    uint32_t                        u32Rsvd0;
} PSPFFSDIRHDR;
/** Pointer to a directory header. */
typedef PSPFFSDIRHDR *PPSPFFSDIRHDR;
/** Pointer to a const directory header. */
typedef const PSPFFSDIRHDR *PCPSPFFSDIRHDR;


/** PSP firmware directory magic. */
#define PSP_FFS_PSP_DIR_HDR_MAGIC         0x50535024 /* PSP$ */
/** PSP firmware combo directory magic. */
#define PSP_FFS_PSP_DIR_HDR_MAGIC_COMBO   0x50535032 /* PSP2 */
/** PSP firmware L2 directory magic. */
#define PSP_FFS_PSP_DIR_HDR_MAGIC_L2      0x324c5024 /* 2LP$ */

#define PSP_FFS_PSP_DIR_HDR_ENTRIES_MAX   4096

/**
 * PSP directory.
 */
typedef struct PSPFFSDIR
{
    /** The header. */
    PSPFFSDIRHDR                    Hdr;
    /** Array of entries - variable in size depending on the entry count. */
    PSPFFSDIRENTRY                  aEntries[1];
} PSPFFSDIR;
/** Pointer to a directory. */
typedef PSPFFSDIR *PPSPFFSDIR;
/** Pointer to a const directory. */
typedef const PSPFFSDIR *PCPSPFFSDIR;


/**
 * PSP combo directory entry.
 */
typedef struct PSPFFSCOMBODIRENTRY
{
    /** Selector ID. */
    uint32_t                        idSelector;
    /** The PSP ID. */
    uint32_t                        idPsp;
    /** The base address of the directory. */
    PSPFFSADDR                      FfsAddrPspDir;
    /** Unknown/Reserved. */
    uint32_t                        u32Rsvd0;
} PSPFFSCOMBODIRENTRY;
/** Pointer to a combo directory entry. */
typedef PSPFFSCOMBODIRENTRY *PPSPFFSCOMBODIRENTRY;
/** Pointer to a const combo directory entry. */
typedef const PSPFFSCOMBODIRENTRY *PCPSPFFSCOMBODIRENTRY;


/**
 * PSP combo directory.
 */
typedef struct PSPFFSCOMBODIR
{
    /** The header. */
    PSPFFSDIRHDR                    Hdr;
    /** Reserved. */
    uint32_t                        au32Rsvd0[4];
    /** Array of entries - variable in size depending on the entry count. */
    PSPFFSCOMBODIRENTRY             aEntries[1];
} PSPFFSCOMBODIR;
/** Pointer to a combo directory. */
typedef PSPFFSCOMBODIR *PPSPFFSCOMBODIR;
/** Pointer to a const combo directory. */
typedef const PSPFFSCOMBODIR *PCPSPFFSCOMBODIR;


#endif /* !PSP_INCLUDED_psp_fw_ffs_h */

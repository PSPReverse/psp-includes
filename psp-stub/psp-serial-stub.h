/** @file
 * PSP serial stub - protocol header.
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
#ifndef __include_psp_serial_stub_h
#define __include_psp_serial_stub_h

#if defined(IN_PSP) || defined(IN_PSP_EMULATOR)
# include <common/types.h>
# include <common/cdefs.h>
#else
# error "Invalid environment"
#endif

/* Everything is little endian here. */

/** PSP to external PDU start magic. */
#define PSP_SERIAL_PSP_2_EXT_PDU_START_MAGIC            ((uint32_t)0x50535024) /* $PSP */
/** PSP to external PDU end magic. */
#define PSP_SERIAL_PSP_2_EXT_PDU_END_MAGIC              ((uint32_t)0x5053507e) /* ~PSP */

/** External to PSP PDU start magic. */
#define PSP_SERIAL_EXT_2_PSP_PDU_START_MAGIC            ((uint32_t)0x24505350) /* PSP$ */
/** External to PSP PDU end magic. */
#define PSP_SERIAL_EXT_2_PSP_PDU_END_MAGIC              ((uint32_t)0x7e505350) /* PSP~ */


/** @name Status codes for request responses.
 * @{ */
/** Success status code. */
#define PSP_SERIAL_STS_INF_SUCCESS                      (0)
/** Invalid parameter. */
#define PSP_SERIAL_STS_ERR_INVALID_PARAMETER            (-1)
/** Buffer overflow. */
#define PSP_SERIAL_STS_ERR_BUFFER_OVERFLOW              (-2)
/** Request caused undefined instruction exception. */
#define PSP_SERIAL_STS_UNDEF_INSN_EXCEPTION             (-3)
/** Request caused data abort exception. */
#define PSP_SERIAL_STS_DATA_ABORT_EXCEPTION             (-4)
/** Request caused prefetch abort exception. */
#define PSP_SERIAL_STS_PREFETCH_ABORT_EXCEPTION         (-5)
/** @} */


/**
 * Request/Response/Notification IDs.
 */
typedef enum PSPSERIALPDURRNID
{
    /** Invalid 0 value. */
    PSPSERIALPDURRNID_INVALID = 0,
    /** First notification ID. */
    PSPSERIALPDURRNID_NOTIFICATION_FIRST,
    /** Beacon sent from the PSP stub to external indicating it waits for a connection.
     * Also an indicator that the system reset during some operation. */
    PSPSERIALPDURRNID_NOTIFICATION_BEACON = PSPSERIALPDURRNID_NOTIFICATION_FIRST,
    /** Interrupt notification. */
    PSPSERIALPDURRNID_NOTIFICATION_IRQ,
    /** Notification: Log message. */
    PSPSERIALPDURRNID_NOTIFICATION_LOG_MSG,
    /** Notification: Output buffer arbitrary data. */
    PSPSERIALPDURRNID_NOTIFICATION_OUT_BUF,
    /** Notification: Code module execution has finished. */
    PSPSERIALPDURRNID_NOTIFICATION_CODE_MOD_EXEC_FINISHED,
    /** Notification: First invalid notification ID. */
    PSPSERIALPDURRNID_NOTIFICATION_INVALID_FIRST,

    /** First request ID. */
    PSPSERIALPDURRNID_REQUEST_FIRST = 1000,
    /** Request: Connection attempt. */
    PSPSERIALPDURRNID_REQUEST_CONNECT = PSPSERIALPDURRNID_REQUEST_FIRST,
    /** Request: Read PSP SRAM. */
    PSPSERIALPDURRNID_REQUEST_PSP_MEM_READ,
    /** Request: Write PSP SRAM. */
    PSPSERIALPDURRNID_REQUEST_PSP_MEM_WRITE,
    /** Request: Read PSP MMIO. */
    PSPSERIALPDURRNID_REQUEST_PSP_MMIO_READ,
    /** Request: Write PSP MMIO. */
    PSPSERIALPDURRNID_REQUEST_PSP_MMIO_WRITE,
    /** Request: Read PSP SMN. */
    PSPSERIALPDURRNID_REQUEST_PSP_SMN_READ,
    /** Request: Write PSP SMN. */
    PSPSERIALPDURRNID_REQUEST_PSP_SMN_WRITE,
    /** Request: Read x86 memory. */
    PSPSERIALPDURRNID_REQUEST_PSP_X86_MEM_READ,
    /** Request: Write x86 memory. */
    PSPSERIALPDURRNID_REQUEST_PSP_X86_MEM_WRITE,
    /** Request: Read x86 MMIO. */
    PSPSERIALPDURRNID_REQUEST_PSP_X86_MMIO_READ,
    /** Request: Write x86 MMIO. */
    PSPSERIALPDURRNID_REQUEST_PSP_X86_MMIO_WRITE,
    /** Request: Generic data transfer request (more capable but has more overhead). */
    PSPSERIALPDURRNID_REQUEST_PSP_DATA_XFER,
    /** Request: Read a Co processor register. */
    PSPSERIALPDURRNID_REQUEST_COPROC_READ,
    /** Request: Write a Co processor register. */
    PSPSERIALPDURRNID_REQUEST_COPROC_WRITE,
    /** Request: Write input buffer. */
    PSPSERIALPDURRNID_REQUEST_INPUT_BUF_WRITE,
    /** Request: Load code module. */
    PSPSERIALPDURRNID_REQUEST_LOAD_CODE_MOD,
    /** Request: Execute code module. */
    PSPSERIALPDURRNID_REQUEST_EXEC_CODE_MOD,
    /** Request: Branch to address (this will likely kill the stub). */
    PSPSERIALPDURRNID_REQUEST_BRANCH_TO,
    /** Request: First invalid request ID. */
    PSPSERIALPDURRNID_REQUEST_INVALID_FIRST,

    /** First response ID. */
    PSPSERIALPDURRNID_RESPONSE_FIRST = 10000,
    /** Response: Connection attempt. */
    PSPSERIALPDURRNID_RESPONSE_CONNECT = PSPSERIALPDURRNID_RESPONSE_FIRST,
    /** Response: Read PSP SRAM. */
    PSPSERIALPDURRNID_RESPONSE_PSP_MEM_READ,
    /** Response: Write PSP SRAM. */
    PSPSERIALPDURRNID_RESPONSE_PSP_MEM_WRITE,
    /** Response: Read PSP MMIO. */
    PSPSERIALPDURRNID_RESPONSE_PSP_MMIO_READ,
    /** Response: Write PSP MMIO. */
    PSPSERIALPDURRNID_RESPONSE_PSP_MMIO_WRITE,
    /** Response: Read PSP SMN. */
    PSPSERIALPDURRNID_RESPONSE_PSP_SMN_READ,
    /** Response: Write PSP SMN. */
    PSPSERIALPDURRNID_RESPONSE_PSP_SMN_WRITE,
    /** Response: Read x86 memory. */
    PSPSERIALPDURRNID_RESPONSE_PSP_X86_MEM_READ,
    /** Response: Write x86 memory. */
    PSPSERIALPDURRNID_RESPONSE_PSP_X86_MEM_WRITE,
    /** Response: Read x86 MMIO. */
    PSPSERIALPDURRNID_RESPONSE_PSP_X86_MMIO_READ,
    /** Response: Write x86 MMIO. */
    PSPSERIALPDURRNID_RESPONSE_PSP_X86_MMIO_WRITE,
    /** Response: Generic data transfer request (more capable but has more overhead). */
    PSPSERIALPDURRNID_RESPONSE_PSP_DATA_XFER,
    /** Response: Read a Co processor register. */
    PSPSERIALPDURRNID_RESPONSE_COPROC_READ,
    /** Response: Write a Co processor register. */
    PSPSERIALPDURRNID_RESPONSE_COPROC_WRITE,
    /** Response: Write input buffer. */
    PSPSERIALPDURRNID_RESPONSE_INPUT_BUF_WRITE,
    /** Response: Load code module. */
    PSPSERIALPDURRNID_RESPONSE_LOAD_CODE_MOD,
    /** Response: Load code module. */
    PSPSERIALPDURRNID_RESPONSE_EXEC_CODE_MOD,
    /** Response: Branch to address (response is send before the actual branch). */
    PSPSERIALPDURRNID_RESPONSE_BRANCH_TO,
    /** Response: First invalid response ID. */
    PSPSERIALPDURRNID_RESPONSE_INVALID_FIRST,

    /** 32bit hack. */
    PSPSERIALPDURRNID_32BIT_HACK = 0x7fffffff
} PSPSERIALPDURRNID;
/** Pointer to the Request/Response/Notification ID. */
typedef PSPSERIALPDURRNID *PPSPSERIALPDURRNID;


/**
 * Code module type.
 */
typedef enum PSPSERIALCMTYPE
{
    /** Invalid type. */
    PSPSERIALCMTYPE_INVALID = 0,
    /** Flat binary loaded at a fixed address determined by the serial stub. */
    PSPSERIALCMTYPE_FLAT_BINARY,
    /** @todo ELF. */
    PSPSERIALCMTYPE_32BIT_HACK = 0x7fffffff
} PSPSERIALCMTYPE;


/**
 * PDU header common for both directions.
 */
typedef struct PSPSERIALPDUHDR
{
    /** Identifying magic. */
    uint32_t                            u32Magic;
    /** View dependent data. */
    union
    {
        /** Byte view (for checksumming). */
        uint8_t                         ab[28];
        /** Field view. */
        struct
        {
            /** Size of the PDU in bytes, excluding the header and footer,
             * pad to the next 8 byte alignment to know where the footer starts. */
            uint32_t                    cbPdu;
            /** PDU counter (monotonically incrementing for each direction). */
            uint32_t                    cPdus;
            /** Request/Response/Notification ID. */
            PSPSERIALPDURRNID           enmRrnId;
            /** The CCD the PDU is designated for. */
            uint32_t                    idCcd;
            /** Status code for a response. */
            PSPSTS                      rcReq;
            /** Millisecond timestamp when a response/notification was sent, ignored for requests. */
            uint32_t                    tsMillies;
            /** Padding to 32 bytes. */
            uint32_t                    u32Pad0;
        } Fields;
    } u;
} PSPSERIALPDUHDR;
/** Pointer to a PSP serial PDU header. */
typedef PSPSERIALPDUHDR *PPSPSERIALPDUHDR;
/** Pointer to a const PSP serial PDU header. */
typedef const PSPSERIALPDUHDR *PCPSPSERIALPDUHDR;

#ifdef __GNUC__
_Static_assert(sizeof(PSPSERIALPDUHDR) == 32, "PDU header has invalid size!");
#endif


/**
 * PDU footer common for both directions.
 */
typedef struct PSPSERIALPDUFOOTER
{
    /** Additive checksum (Every byte between the starting magic and beginning of the PDU footer added up + checksum has to equal 0). */
    uint32_t                            u32ChkSum;
    /** Closing magic. */
    uint32_t                            u32Magic;
} PSPSERIALPDUFOOTER;
/** Pointer to a PSP serial PDU footer. */
typedef PSPSERIALPDUFOOTER *PPSPSERIALPDUFOOTER;
/** Pointer to a const PSP serial PDU header. */
typedef const PSPSERIALPDUFOOTER *PCPSPSERIALPDUFOOTER;


/**
 * PSP serial stub beacon notification data.
 */
typedef struct PSPSERIALBEACONNOT
{
    /** Beacon sent counter. */
    uint32_t                            cBeaconsSent;
    /** Padding to 8 byte alignment. */
    uint32_t                            u32Pad0;
} PSPSERIALBEACONNOT;
/** Pointer to beacon notification data. */
typedef PSPSERIALBEACONNOT *PPSPSERIALBEACONNOT;
/** Pointer to a const beacon notification. */
typedef const PSPSERIALBEACONNOT *PCPSPSERIALBEACONNOT;


/**
 * PSP serial stub interrupt status change notification.
 */
typedef struct PSPSERIALIRQNOT
{
    /** Current interrupt status flags. */
    uint16_t                            fIrqCur;
    /** Previous interrupt status flags. */
    uint16_t                            fIrqPrev;
    /** Padding to 8 byte alignment. */
    uint32_t                            u32Pad0;
} PSPSERIALIRQNOT;
/** Pointer to beacon notification data. */
typedef PSPSERIALIRQNOT *PPSPSERIALIRQNOT;
/** Pointer to a const beacon notification. */
typedef const PSPSERIALIRQNOT *PCPSPSERIALIRQNOT;

/** IRQ is pending flag. */
#define PSP_SERIAL_NOTIFICATION_IRQ_PENDING_IRQ     BIT(0)
/** FIQ is pending flag. */
#define PSP_SERIAL_NOTIFICATION_IRQ_PENDING_FIQ     BIT(1)


/**
 * PSP serial stub output buffer notification data.
 */
typedef struct PSPSERIALOUTBUFNOT
{
    /** Output buffer identifer. */
    uint32_t                            idOutBuf;
    /** Padding to 8 byte alignment. */
    uint32_t                            u32Pad0;
} PSPSERIALOUTBUFNOT;
/** Pointer to beacon notification data. */
typedef PSPSERIALOUTBUFNOT *PPSPSERIALOUTBUFNOT;
/** Pointer to a const beacon notification. */
typedef const PSPSERIALOUTBUFNOT *PCPSPSERIALOUTBUFNOT;


/**
 * PSP serial stub code module execution done notification data.
 */
typedef struct PSPSERIALEXECCMFINISHEDNOT
{
    /** Arbitrary code module return value. */
    uint32_t                            u32CmRet;
    /** Padding to 8 byte alignment. */
    uint32_t                            u32Pad0;
} PSPSERIALEXECCMFINISHEDNOT;
/** Pointer to beacon notification data. */
typedef PSPSERIALEXECCMFINISHEDNOT *PPSPSERIALEXECCMFINISHEDNOT;
/** Pointer to a const beacon notification. */
typedef const PSPSERIALEXECCMFINISHEDNOT *PCPSPSERIALEXECCMFINISHEDNOT;


/**
 * PSP serial stub connect response data.
 */
typedef struct PSPSERIALCONNECTRESP
{
    /** Maximum PDU length supported. */
    uint32_t                            cbPduMax;
    /** Size of the scratch space area in bytes. */
    uint32_t                            cbScratch;
    /** Start address of the scratch space area. */
    PSPADDR                             PspAddrScratch;
    /** Number of sockets in the system. */
    uint32_t                            cSysSockets;
    /** Number of CCDs in the systems */
    uint32_t                            cCcdsPerSocket;
    /** Padding to 8 byte alignment. */
    uint32_t                            au32Pad0;
} PSPSERIALCONNECTRESP;
/** Pointer to connect response data. */
typedef PSPSERIALCONNECTRESP *PPSPSERIALCONNECTRESP;
/** Pointer to a const connect response. */
typedef const PSPSERIALCONNECTRESP *PCPSPSERIALCONNECTRESP;


/**
 * PSP memory transfer request (SRAM and MMIO).
 */
typedef struct PSPSERIALPSPMEMXFERREQ
{
    /** The PSP address the transfer starts. */
    PSPADDR                             PspAddrStart;
    /** Size of the transfer in bytes. */
    uint32_t                            cbXfer;
} PSPSERIALPSPMEMXFERREQ;
/** Pointer to a PSP memory transfer request. */
typedef PSPSERIALPSPMEMXFERREQ *PPSPSERIALPSPMEMXFERREQ;
/** Pointer to a const PSP memory transfer request. */
typedef const PSPSERIALPSPMEMXFERREQ *PCPSPSERIALPSPMEMXFERREQ;


/**
 * SMN memory transfer request.
 */
typedef struct PSPSERIALSMNMEMXFERREQ
{
    /** The PSP address the transfer starts. */
    SMNADDR                             SmnAddrStart;
    /** Size of the transfer in bytes. */
    uint32_t                            cbXfer;
} PSPSERIALSMNMEMXFERREQ;
/** Pointer to a PSP memory transfer request. */
typedef PSPSERIALSMNMEMXFERREQ *PPSPSERIALSMNMEMXFERREQ;
/** Pointer to a const PSP memory transfer request. */
typedef const PSPSERIALSMNMEMXFERREQ *PCPSPSERIALSMNMEMXFERREQ;


/**
 * x86 memory transfer request (DRAM and MMIO).
 */
typedef struct PSPSERIALX86MEMXFERREQ
{
    /** The x86 memory address the transfer starts. */
    X86PADDR                            PhysX86Start;
    /** Size of the transfer in bytes. */
    uint32_t                            cbXfer;
    /** Padding to 8 byte alignment. */
    uint32_t                            u32Pad0;
} PSPSERIALX86MEMXFERREQ;
/** Pointer to a PSP memory transfer request. */
typedef PSPSERIALX86MEMXFERREQ *PPSPSERIALX86MEMXFERREQ;
/** Pointer to a const PSP memory transfer request. */
typedef const PSPSERIALX86MEMXFERREQ *PCPSPSERIALX86MEMXFERREQ;


/**
 * PSP serial stub write input buffer request data.
 */
typedef struct PSPSERIALINBUFWRREQ
{
    /** Input buffer identifer. */
    uint32_t                            idInBuf;
    /** Padding to 8 byte alignment. */
    uint32_t                            u32Pad0;
} PSPSERIALINBUFWRREQ;
/** Pointer to write input buffer request data. */
typedef PSPSERIALINBUFWRREQ *PPSPSERIALINBUFWRREQ;
/** Pointer to a const write input buffer request. */
typedef const PSPSERIALINBUFWRREQ *PCPSPSERIALINBUFWRREQ;


/**
 * PSP serial stub load code module request data.
 */
typedef struct PSPSERIALLOADCODEMODREQ
{
    /** Code module type. */
    PSPSERIALCMTYPE                     enmCmType;
    /** Padding to 8 byte alignment. */
    uint32_t                            u32Pad0;
} PSPSERIALLOADCODEMODREQ;
/** Pointer to load code module request data. */
typedef PSPSERIALLOADCODEMODREQ *PPSPSERIALLOADCODEMODREQ;
/** Pointer to a const load code module request. */
typedef const PSPSERIALLOADCODEMODREQ *PCPSPSERIALLOADCODEMODREQ;


/**
 * PSP serial stub exec code module request data.
 */
typedef struct PSPSERIALEXECCODEMODREQ
{
    /** Arbitrary argument 0 value. */
    uint32_t                            u32Arg0;
    /** Arbitrary argument 1 value. */
    uint32_t                            u32Arg1;
    /** Arbitrary argument 2 value. */
    uint32_t                            u32Arg2;
    /** Arbitrary argument 3 value. */
    uint32_t                            u32Arg3;
} PSPSERIALEXECCODEMODREQ;
/** Pointer to load code module request data. */
typedef PSPSERIALEXECCODEMODREQ *PPSPSERIALEXECCODEMODREQ;
/** Pointer to a const load code module request. */
typedef const PSPSERIALEXECCODEMODREQ *PCPSPSERIALEXECCODEMODREQ;


/**
 * Generic data transfer request.
 */
typedef struct PSPSERIALDATAXFERREQ
{
    /** The PSP address space identifier. */
    PSPADDRSPACE                        enmAddrSpace;
    /** The access stride (1, 2 or 4 bytes). */
    uint32_t                            cbStride;
    /** Size of the transfer in bytes (must be multiple of access stride). */
    uint32_t                            cbXfer;
    /** Transfer flags. */
    uint32_t                            fFlags;
    /** The address space dependent start address of the transfer. */
    union
    {
        /** PSP address for both SRAM and MMIO transfers. */
        PSPADDR                         PspAddrStart;
        /** SMN address. */
        SMNADDR                         SmnAddrStart;
        /** x86 dependent data. */
        struct
        {
            /** X86 physical address. */
            X86PADDR                    PhysX86AddrStart;
            /** Caching flags used for the access. */
            uint32_t                    fCaching;
            /** Padding to 8 byte alignment. */
            uint32_t                    u32Pad0;
        } X86;
    } u;
} PSPSERIALDATAXFERREQ;
/** Pointer to a PSP memory transfer request. */
typedef PSPSERIALDATAXFERREQ *PPSPSERIALDATAXFERREQ;
/** Pointer to a const PSP memory transfer request. */
typedef const PSPSERIALDATAXFERREQ *PCPSPSERIALDATAXFERREQ;

#ifdef __GNUC__
_Static_assert(sizeof(PSPSERIALDATAXFERREQ) == 32, "Memory transfer descriptor has invalid size!");
#endif

/** Read from the target address. */
#define PSP_SERIAL_DATA_XFER_F_READ      BIT(0)
/** Write to the target address. */
#define PSP_SERIAL_DATA_XFER_F_WRITE     BIT(1)
/** This is a memset like operation and the PDU only contains a single datum with the stride size. */
#define PSP_SERIAL_DATA_XFER_F_MEMSET    BIT(2)
/** Increment PSP address after each access by the stride. */
#define PSP_SERIAL_DATA_XFER_F_INCR_ADDR BIT(3)


/**
 * Co-Processor read/write request information.
 */
typedef struct PSPSERIALCOPROCRWREQ
{
    /** The Co-processor to access. */
    uint8_t                             u8CoProc;
    /** The CRn value which will be encoded in the instruction. */
    uint8_t                             u8Crn;
    /** The CRm value which will be encoded in the instruction. */
    uint8_t                             u8Crm;
    /** The opc1 value which will be encoded in the instruction. */
    uint8_t                             u8Opc1;
    /** The opc2 value which will be encoded in the instruction. */
    uint8_t                             u8Opc2;
    /** Padding to 8 byte boundary. */
    uint8_t                             abPad[3];
} PSPSERIALCOPROCRWREQ;
/** Pointer to a Co-Processor read/write request. */
typedef PSPSERIALCOPROCRWREQ *PPSPSERIALCOPROCRWREQ;
/** Pointer to a const Co-Processor read/write request. */
typedef const PSPSERIALCOPROCRWREQ *PCPSPSERIALCOPROCRWREQ;

#ifdef __GNUC__
_Static_assert(sizeof(PSPSERIALCOPROCRWREQ) == 8, "Co-Processor RW request descriptor has invalid size!");
#endif


/**
 * Branch to request information.
 */
typedef struct PSPSERIALBRANCHTOREQ
{
    /** Flags determining the branch behavior. */
    uint32_t                            u32Flags;
    /** The address to branch to. */
    PSPADDR                             PspAddrDst;
    /** Value of the general purpose registers. */
    uint32_t                            au32Gprs[13];
    /** Padding. */
    uint32_t                            u32Pad0;
} PSPSERIALBRANCHTOREQ;
/** Pointer to a Co-Processor read/write request. */
typedef PSPSERIALBRANCHTOREQ *PPSPSERIALBRANCHTOREQ;
/** Pointer to a const Co-Processor read/write request. */
typedef const PSPSERIALBRANCHTOREQ *PCPSPSERIALBRANCHTOREQ;

#ifdef __GNUC__
_Static_assert(sizeof(PSPSERIALBRANCHTOREQ) == 16 * sizeof(uint32_t), "Branch to descriptor has invalid size!");
#endif

/** The code branched to uses the thumb instruction set, if clear it uses the default ARM ISA. */
#define PSP_SERIAL_BRANCH_TO_F_THUMB    BIT(0)

#endif /* !__include_psp_serial_stub_h */

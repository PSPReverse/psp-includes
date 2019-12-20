/**
 * Binary loader interface.
 */
#ifndef __include_psp_binloader_h
#define __include_psp_binloader_h

#if defined(IN_PSP)
# include <types.h>
#elif defined(IN_LINUX)
# include <linux/types.h>

typedef uint64_t X86PADDR;
#endif

#define BIN_LOADER_LOAD_BIN   0xa0
#define BIN_LOADER_EXEC_BIN   0xa1
#define BIN_LOADER_SMN_READ   0xa2
#define BIN_LOADER_SMN_WRITE  0xa3
#define BIN_LOADER_PSP_READ   0xa4
#define BIN_LOADER_PSP_WRITE  0xa5
#define BIN_LOADER_CALL_SVC   0xa6
#define BIN_LOADER_QUERY_INFO 0xa7

#define BIN_LOADER_REQ_FIRST  BIN_LOADER_LOAD_BIN
#define BIN_LOADER_REQ_LAST   BIN_LOADER_QUERY_INFO

typedef struct BINLOADERREQHDR
{
    /** The CCX to execute the request on. */
    uint32_t                    idCcx;
    /** The status code on return. */
    int32_t                     i32Sts;
} BINLOADERREQHDR;
/** Pointer to a command header. */
typedef BINLOADERREQHDR *PBINLOADERREQHDR;
/** Pointer to a const command header. */
typedef const BINLOADERREQHDR *PCBINLOADERREQHDR;

typedef struct BINLOADERREQLOADBIN
{
    /** Request header. */
    BINLOADERREQHDR             Hdr;
    /** The X86 physical address to load. */
    X86PADDR                    PhysX86AddrLoad;
    /** Size of the binary to load. */
    uint32_t                    cbBinary;
} BINLOADERREQLOADBIN;
typedef BINLOADERREQLOADBIN *PBINLOADERREQLOADBIN;
typedef const BINLOADERREQLOADBIN *PCBINLOADERREQLOADBIN;

typedef struct BINLOADERREQEXECBIN
{
    /** Request header. */
    BINLOADERREQHDR             Hdr;
    /** Physical address passed to executed binary. */
    X86PADDR                    PhysX8AddrExec;
} BINLOADERREQEXECBIN;
typedef BINLOADERREQEXECBIN *PBINLOADERREQEXECBIN;
typedef const BINLOADERREQEXECBIN *PCBINLOADERREQEXECBIN;

typedef struct BINLOADERREQSMNRW
{
    /** Request header. */
    BINLOADERREQHDR             Hdr;
    /** The CCX to target. */
    uint32_t                    idCcxTgt;
    /** Address of the register to read/write. */
    uint32_t                    u32Addr;
    /** The value to write or read value on success. */
    uint64_t                    u64Val;
    /** Size of the value to read/write. */
    uint32_t                    cbVal;
} BINLOADERREQSMNRW;
typedef BINLOADERREQSMNRW *PBINLOADERREQSMNRW;
typedef const BINLOADERREQSMNRW *PCBINLOADERREQSMNRW;

typedef struct BINLOADERREQPSPRW
{
    /** Request header. */
    BINLOADERREQHDR             Hdr;
    /** PSP address to operate on. */
    uint32_t                    u32Addr;
    /** Size to copy. */
    uint32_t                    cbCopy;
    /** x86 address to operate on. */
    X86PADDR                    PhysX86Addr;
} BINLOADERREQPSPRW;
typedef BINLOADERREQPSPRW *PBINLOADERREQPSPRW;
typedef const BINLOADERREQPSPRW *PCBINLOADERREQPSPRW;

typedef struct BINLOADERREQCALLSVC
{
    /** Request header. */
    BINLOADERREQHDR             Hdr;
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
} BINLOADERREQCALLSVC;
typedef BINLOADERREQCALLSVC *PBINLOADERREQCALLSVC;
typedef const BINLOADERREQCALLSVC *PCBINLOADERREQCALLSVC;

typedef struct BINLOADERREQQUERYINFO
{
    /** Request header. */
    BINLOADERREQHDR             Hdr;
    /** PSP address of the scratch buffer. */
    uint32_t                    u32PspScratchAddr;
    /** Size of the scratch buffer in bytes. */
    uint32_t                    cbScratch;
} BINLOADERREQQUERYINFO;
typedef BINLOADERREQQUERYINFO *PBINLOADERREQQUERYINFO;
typedef const BINLOADERREQQUERYINFO *PCBINLOADERREQQUERYINFO;


/**
 * Union of all requests.
 */
typedef union BINLOADERREQ
{
    /** Header. */
    BINLOADERREQHDR             Hdr;
    BINLOADERREQLOADBIN         LoadBin;
    BINLOADERREQEXECBIN         ExecBin;
    BINLOADERREQSMNRW           SmnRw;
    BINLOADERREQPSPRW           PspRw;
    BINLOADERREQCALLSVC         SvcCall;
    BINLOADERREQQUERYINFO       QueryInfo;
} BINLOADERREQ;

#endif

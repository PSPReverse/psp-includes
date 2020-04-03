#ifndef __include_svc_id_h
#define __include_svc_id_h

#define SVC_EXIT                      0x0
#define SVC_FFS_ENTRY_READ            0x2
#define SVC_SMN_MAP_ADDR_EX           0x3
#define SVC_SMN_MAP_ADDR              0x4
#define SVC_SMN_UNMAP_ADDR            0x5
#define SVC_DBG_PRINT                 0x6
#define SVC_X86_HOST_MEMORY_UNMAP     0x08
#define SVC_X86_HOST_MEMORY_COPY_FROM 0x09
#define SVC_GET_DBG_KEY               0x1f
#define SVC_X86_HOST_MEMORY_MAP       0x25
#define SVC_X86_HOST_COPY_TO_PSP      0x26
#define SVC_X86_HOST_COPY_FROM_PSP    0x27
#define SVC_SMU_MSG                   0x28
#define SVC_CALL_OTHER_PSP            0x31
#define SVC_CACHE_FLUSH               0x37
#define SVC_GET_STATE_BUFFER          0x3c

#define SVC_QUERY_TWO_64BIT_VALS      0x48

/** These are our own injected syscalls not defined in the stock firmware interface. */
#define SVC_INJECTED_MAP_X86_HOST_MEMORY_EX 0x60
#define SVC_INJECTED_DBG_MARKER_1           0x61
#define SVC_INJECTED_DBG_MARKER_2           0x62
#define SVC_INJECTED_DBG_MARKER_3           0x63
#define SVC_INJECTED_DBG_MARKER_4           0x64
#define SVC_INJECTED_DBG_MARKER_5           0x65
#define SVC_LOG_CHAR_BUF                    0x66

#define SVC_CALL_INVALID                    0xfe

#endif

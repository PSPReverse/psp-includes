#ifndef __include_types_h
#define __include_types_h

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

typedef uint64_t X86PADDR;

#define NULL ((void *)0)

#endif
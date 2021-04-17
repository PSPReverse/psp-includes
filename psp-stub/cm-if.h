/** @file
 * PSP serial stub - Code module interface.
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
#ifndef __include_cm_if_h
#define __include_cm_if_h

#if defined(IN_PSP)
# include <common/types.h>
#else
# error "Invalid environment"
#endif

/** Flat binary load address. */
#define CM_FLAT_BINARY_LOAD_ADDR 0x10000
/** Inifinite amount of waiting time. */
#define CM_WAIT_INDEFINITE       UINT32_MAX

/** Pointer to a const code module interface callback table. */
typedef const struct CMIF *PCCMIF;

/**
 * The interface callback table for the code module to use.
 */
typedef struct CMIF
{
    /**
     * Peeks how many bytes are available for reading from the given input buffer ID.
     *
     * @returns Number of bytes available for reading from the given input buffer ID.
     * @param   pCmIf               Pointer to this interface table.
     * @param   idInBuf             Input buffer ID.
     */
    size_t (*pfnInBufPeek) (PCCMIF pCmIf, uint32_t idInBuf);

    /**
     * Polls until there is something to read from the given input buffer.
     *
     * @returns Status code.
     * @param   pCmIf               Pointer to this interface table.
     * @param   idInBuf             Input buffer ID to poll.
     * @param   cMillies            How many milliseconds to poll, CM_WAIT_INDEFINITE to wait
     *                              until there is something.
     */
    int (*pfnInBufPoll) (PCCMIF pCmIf, uint32_t idInBuf, uint32_t cMillies);

    /**
     * Reads from the given input buffer.
     *
     * @returns Status code.
     * @param   pCmIf               Pointer to this interface table.
     * @param   idInBuf             Input buffer ID to read from.
     * @param   pvBuf               Where to store the read data.
     * @param   cbRead              How much to read.
     * @param   pcbRead             Where to store the amount of bytes read, optional.
     */
    int    (*pfnInBufRead) (PCCMIF pCmIf, uint32_t idInBuf, void *pvBuf, size_t cbRead, size_t *pcbRead);

    /**
     * Writes to the given output buffer.
     *
     * @returns Status code.
     * @param   pCmIf               Pointer to this interface table.
     * @param   idOutBuf            Output buffer ID to write to.
     * @param   pvBuf               The data to write.
     * @param   cbWrite             How much to write.
     * @param   pcbWritten          Where to store the amount of data actually written.
     */
    int    (*pfnOutBufWrite) (PCCMIF pCmIf, uint32_t idOutBuf, const void *pvBuf, size_t cbWrite, size_t *pcbWritten);

    /**
     * Waits for the given amount of milliseconds.
     *
     * @returns nothing.
     * @param   pCmIf               Pointer to this interface table.
     * @param   cMillies            Number of milliseconds to wait.
     */
    void   (*pfnDelayMs) (PCCMIF pCmIf, uint32_t cMillies);

    /**
     * Returns a millisecond precision timestamp since some arbitrary point in the past (usually startup time).
     *
     * @returns Millisecond timestamp.
     * @param   pCmIf               Pointer to this interface table.
     */
    uint32_t (*pfnTsGetMilli) (PCCMIF pCmIf);

} CMIF;
/** Pointer to a code module interface callback table. */
typedef CMIF *PCMIF;


/**
 * The entry point type.
 *
 * @returns 32bit return value.
 * @param   pCmIf                   Pointer to the code module interface to use for input/output.
 * @param   u32Arg0                 Argument 0.
 * @param   u32Arg1                 Argument 1.
 * @param   u32Arg2                 Argument 2.
 * @param   u32Arg3                 Argument 3.
 */
typedef uint32_t (FNCMENTRY) (PCCMIF pCmIf, uint32_t u32Arg0, uint32_t u32Arg1, uint32_t u32Arg2, uint32_t u32Arg3);
/** Pointer to a code module entry point. */
typedef FNCMENTRY *PFNCMENTRY;

#endif /* !__include_psp_cm_if_h */

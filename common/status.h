/** @file
 * PSP common - Status/Error code definitions.
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
#ifndef INCLUDED_common_status_h
#define INCLUDED_common_status_h

#include <common/types.h>
#include <common/cdefs.h>

/** Checks for a success status code. */
#define STS_SUCCESS(a_rc)                   (__builtin_expect(!!((a_rc) >= 0), 1))
/** Checks for a failure status code. */
#define STS_FAILURE(a_rc)                   (__builtin_expect(!!((a_rc) < 0), 0))

/** General success status code. */
#define STS_INF_SUCCESS                                     (0)
/** General error code, do not use (this is solely used to make conversion from old code easier which uses -1 directly). */
#define STS_ERR_GENERAL_ERROR                               (-1)
/** An invalid parameter was passed. */
#define STS_ERR_INVALID_PARAMETER                           (-2)
/** The operation/parameters would cause a buffer overflow. */
#define STS_ERR_BUFFER_OVERFLOW                             (-3)
/** Something wasn't found. */
#define STS_ERR_NOT_FOUND                                   (-4)
/** Out of memory situation occurred. */
#define STS_ERR_NO_MEMORY                                   (-5)
/** An operation would block and no blocking behavior was requested. */
#define STS_ERR_TRY_AGAIN                                   (-6)
/** An operation would block and no blocking behavior was requested. */
#define STS_INF_TRY_AGAIN                                   (6)


/*
 * The following gathers the status codes from several sub projects just to make it easier to
 * keep an overview about errors. Every new component will get its own block of 1000 error, warning
 * and informational status codes if none of the general status codes fits.
 */

/** @name Status codes specific for the PDU serial stub protocol.
 * @{ */
/** Request caused undefined instruction exception. */
#define STS_ERR_PSP_PDU_REQ_UNDEF_INSN_EXCEPTION            (-1000)
/** Request caused data abort exception. */
#define STS_ERR_PSP_PDU_REQ_DATA_ABORT_EXCEPTION            (-1001)
/** Request caused prefetch abort exception. */
#define STS_ERR_PSP_PDU_REQ_PREFETCH_ABORT_EXCEPTION        (-1002)
/** @} */


/** @name Status codes specific for libpspproxy.
 * @{ */
/** Some operation ran into a timeout. */
#define STS_ERR_PSP_PROXY_TIMEOUT                           (-2000)
/** A request caused a PSP reset. */
#define STS_ERR_PSP_PROXY_RESET                             (-2001)
/** Request completed with an error. */
#define STS_ERR_PSP_PROXY_REQ_COMPLETED_WITH_ERROR          (-2002)
/** Request returned unexpected PDU payload size. */
#define STS_ERR_PSP_PROXY_REQ_RESP_PAYLOAD_SZ_MISMATCH      (-2003)
/** No interrupt level change happened during the given timeout. */
#define STS_ERR_PSP_PROXY_WFI_NO_CHANGE                     (-2004)
/** @} */


/** @name Status codes specific for PSPEmu.
 * @{ */
/** The emulation core encountered a WFI instruction. */
#define STS_INF_PSP_EMU_CORE_INSN_WFI_REACHED               (3000)
/** @} */

#endif /* !INCLUDED_common_status_h */


/** @file
 * PSP hardware - Interrupt controller definitions.
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
#ifndef INCLUDED_includes_psp_irq_h
#define INCLUDED_includes_psp_irq_h

/*********************************************************************************************************************************
*   Header Files                                                                                                                 *
*********************************************************************************************************************************/

#include <common/cdefs.h>


/*********************************************************************************************************************************
*   Defined Constants And Macros                                                                                                 *
*********************************************************************************************************************************/

/** The IRQ controller MMIO base address. */
#define PSP_IRQ_MMIO_ADDR_BASE                      0x030103b0
/** The IRQ controller MMIO region size in bytes. */
#define PSP_IRQ_MMIO_SZ                             (6 * sizeof(uint32_t))

/** Group/Priority 0 interrupt acknowledge register. */
#define PSP_IRQ_REG_ACK_PRIO0_OFF                   (0x030103b0 - PSP_IRQ_MMIO_ADDR_BASE)
/** Group/Priority 1 interrupt acknowledge register. */
#define PSP_IRQ_REG_ACK_PRIO1_OFF                   (0x030103b4 - PSP_IRQ_MMIO_ADDR_BASE)
/** Group/Priority 2 interrupt acknowledge register. */
#define PSP_IRQ_REG_ACK_PRIO2_OFF                   (0x030103b8 - PSP_IRQ_MMIO_ADDR_BASE)
/** Group/Priority 3 interrupt acknowledge register. */
#define PSP_IRQ_REG_ACK_PRIO3_OFF                   (0x030103bc - PSP_IRQ_MMIO_ADDR_BASE)

/** Interrupt pending register offset. */
#define PSP_IRQ_REG_PEN_OFF                         (0x030103c0 - PSP_IRQ_MMIO_ADDR_BASE)
/** Value for interrupt pending. */
# define PSP_IRQ_REG_PEN_PENDING                    0x0
/** Value for interrupt not pending. */
# define PSP_IRQ_REG_PEN_NOT_PENDING                0x1

/** Interrupt ID offset. */
#define PSP_IRQ_REG_ID_OFF                          (0x030103c4 - PSP_IRQ_MMIO_ADDR_BASE)
/** Extracts the group/priority ID from the register value. */
# define PSP_IRQ_REG_ID_PRIO_GET(a_RegVal)          (((a_RegVal) >> 5) & 0x3)
/** Sets the group/priority ID. */
# define PSP_IRQ_REG_ID_PRIO_SET(a_Prio)            (((a_Prio) & 0x3) << 5)
/** Extracts the device ID from the register value. */
# define PSP_IRQ_REG_ID_DEV_GET(a_RegVal)           ((a_RegVal) & 0x1f)
/** Sets the group/priority ID. */
# define PSP_IRQ_REG_ID_DEV_SET(a_Dev)              ((a_Dev) & 0x1f)
/** Convenience macro to calculate the register value from the given group/priority and device ID. */
# define PSP_IRQ_REG_ID_MAKE(a_Prio, a_Dev)         (PSP_IRQ_REG_ID_PRIO_SET(a_Prio) | PSP_IRQ_REG_ID_DEV_SET(a_Dev))

#endif /* !INCLUDED_includes_psp_irq_h */


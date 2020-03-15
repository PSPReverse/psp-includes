/** @file
 * PSP x86 interfaces - UART definitions.
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
#ifndef __include_x86_uart_h
#define __include_x86_uart_h

#include <common/cdefs.h>


/** Received byte register offset. */
#define X86_UART_REG_RBR_OFF                    0
/** Transmitter Holding Register offset. */
#define X86_UART_REG_THR_OFF                    0

/** IER register offset. */
#define X86_UART_REG_IER_OFF                    1
/** Enable received data available interrupt. */
# define X86_UART_REG_IER_ERBFI                 BIT(0)
/** Enable transmitter holding register empty interrupt. */
# define X86_UART_REG_IER_ETBEI                 BIT(1)
/** Enable receiver line status interrupt. */
# define X86_UART_REG_IER_ELSI                  BIT(2)
/** Enable MODEM status interrupt. */
# define X86_UART_REG_IER_EDSSI                 BIT(3)

/** IIR register offset. */
#define X86_UART_REG_IIR_OFF                    2
/** Interrupt not pending flag (set if not pending). */
# define X86_UART_REG_IIR_NOT_PENDING           BIT(0)
/** Returns the interrupt ID for the given IIR value. */
# define X86_UART_REG_IIR_IID_GET(a_Iir)        (((a_Iir) >> 1) & 0x7)
/** MODEM status change. */
#  define X86_UART_REG_IIR_IID_MODEM_STS        0x0
/** Transmit holding register empty. */
#  define X86_UART_REG_IIR_IID_THRE             0x2
/** Receiver data available or character timeout indication (FIFOs enabled only). */
#  define X86_UART_REG_IIR_IID_RCD_CTI          0x4
/** LSR register change. */
#  define X86_UART_REG_IIR_IID_RLS              0x6
/** Flag indicating whether FIFOs are enabled. */
# define X86_UART_REG_IIR_FIFOS_EN              BIT(6)
/** Flag indicating whether FIFOs are enabled. */
# define X86_UART_REG_IIR_FIFOS_EN2             BIT(7)

/** FCR register offset. */
#define X86_UART_REG_FCR_OFF                    2
/** Flag whether FIFOs should be enabled. */
# define X86_UART_REG_FCR_FIFO_EN               BIT(0)
/** Flag to reset receiver FIFO. */
# define X86_UART_REG_FCR_RX_FIFO_RST           BIT(1)
/** Flag to reset transmitter FIFO. */
# define X86_UART_REG_FCR_TX_FIFO_RST           BIT(1)

/** LCR register offset. */
#define X86_UART_REG_LCR_OFF                    3
/** Sets the word length. */
# define X86_UART_REG_LCR_WLS_SET(a_Lcr, a_Wls) ((a_Lcr) |= (a_Wls) & 0x3)
/** 5 data bits. */
#  define X86_UART_REG_LCR_WLS_5                0x0
/** 6 data bits. */
#  define X86_UART_REG_LCR_WLS_6                0x1
/** 7 data bits. */
#  define X86_UART_REG_LCR_WLS_7                0x2
/** 8 data bits. */
#  define X86_UART_REG_LCR_WLS_8                0x3
/** Sets the number of stop bits used. */
# define X86_UART_REG_LCR_STB                   BIT(2)
/** Flag whether parity checking is enabled. */
# define X86_UART_REG_LCR_PEN                   BIT(3)
/** Flag whether even parity is selected. */
# define X86_UART_REG_LCR_EPS                   BIT(4)
/** Flag whether parity bit is sticky. */
# define X86_UART_REG_LCR_PAR_STICKY            BIT(5)
/** Flag to set a line break condition. */
# define X86_UART_REG_LCR_BREAK                 BIT(6)
/** Flag to enable divisor latch access. */
# define X86_UART_REG_LCR_DLAB                  BIT(7)

/** MCR register offset. */
#define X86_UART_REG_MCR_OFF                    4
/** Indicates the status of the Data Terminal Ready (DTR) output. */
# define X86_UART_REG_MCR_DTR                   BIT(0)
/** Indicates the status of the Request To Send (RTS) output. */
# define X86_UART_REG_MCR_RTS                   BIT(1)
/** Indicates the status of the OUT1 output. */
# define X86_UART_REG_MCR_OUT1                  BIT(2)
/** Indicates the status of the OUT2 output. */
# define X86_UART_REG_MCR_OUT2                  BIT(3)
/** Indicates whether loopback mode is enabled. */
# define X86_UART_REG_MCR_LOOP                  BIT(4)

/** LSR register offset. */
#define X86_UART_REG_LSR_OFF                    5
/** Data ready flag. */
# define X86_UART_REG_LSR_DR                    BIT(0)
/** Overrun error flag. */
# define X86_UART_REG_LSR_OE                    BIT(1)
/** Parity error flag. */
# define X86_UART_REG_LSR_PE                    BIT(2)
/** Framing error flag. */
# define X86_UART_REG_LSR_FE                    BIT(3)
/** Break interrupt flag. */
# define X86_UART_REG_LSR_BI                    BIT(4)
/** Transmitter holding register is empty. */
# define X86_UART_REG_LSR_THRE                  BIT(5)
/** The transmitter has finished transmitting the character. */
# define X86_UART_REG_LSR_TEMT                  BIT(6)
/** Error in receiver FIFO flag. */
# define X86_UART_REG_LSR_RX_FIFO_ERR           BIT(7)

/** MSR register offset. */
#define X86_UART_REG_MSR_OFF                    6
/** Delta clear to send flag. */
# define X86_UART_REG_MSR_DCTS                  BIT(0)
/** Delta data set ready flag. */
# define X86_UART_REG_MSR_DDSR                  BIT(1)
/** Trailing edge ring indicator flag. */
# define X86_UART_REG_MSR_TERI                  BIT(2)
/** Delta data carrier detect flag. */
# define X86_UART_REG_MSR_DDCD                  BIT(3)
/** Clear to send flag. */
# define X86_UART_REG_MSR_CTS                   BIT(4)
/** Data set ready flag. */
# define X86_UART_REG_MSR_DSR                   BIT(5)
/** Ring indicator flag. */
# define X86_UART_REG_MSR_RI                    BIT(6)
/** Data carrier detect flag. */
# define X86_UART_REG_MSR_DCD                   BIT(7)

/** SCR register offset. */
#define X86_UART_REG_SCR_OFF                    7

/** Divisor latch (LSB). */
#define X86_UART_REG_DL_LSB_OFF                 0

/** Divisor latch (MSB). */
#define X86_UART_REG_DL_MSB_OFF                 1

#endif /* !__include_x86_uart_h */

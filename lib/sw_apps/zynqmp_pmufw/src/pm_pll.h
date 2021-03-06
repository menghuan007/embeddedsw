/*
 * Copyright (C) 2014 - 2015 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * XILINX CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 */

/*********************************************************************
 * Contains:
 * - PLL slave implementation
 * - Functions for saving and restoring PLLs' context
 *
 * Note: PMU does not control states of PLLs. When none of FPD PLLs
 * is used and FPD is going to be powered down, PMU saves context of
 * PLLs in FPD and asserts their reset. After powering up FPD, PMU
 * restores the state of PLL based on saved context.
 *********************************************************************/

#ifndef PM_PLL_H_
#define PM_PLL_H_

#include "pm_slave.h"

/*********************************************************************
 * Structure definitions
 ********************************************************************/
/**
 * PmPllContext - Structure for saving context of PLL registers.
 *              Contains variable to store default content of:
 * @ctrl        Control register
 * @cfg         Configuration register
 * @frac        Fractional control register
 * @toCtrl      Control for a cross domain (a divisor)
 * @saved       Flag stating are variables of this structure containing values
 *              to be restored or not
 *
 * Note: context of the PLL is saved just before power-parent of PLL gets
 * powered down (FPD for example) and then the 'saved' flag is set to true.
 * In order to enter PM_PLL_STATE_USED state, PLL must have valid context,
 * meaning the 'saved' flag must be false. Upon initialization (as long as
 * power-parent does not get powered down), all data except 'saved' is
 * invalid/not-initialized (basically 'saved' flag also states do fields of
 * this structure have valid values or not).
 */
typedef struct PmPllContext {
	u32 ctrl;
	u32 cfg;
	u32 frac;
	u32 toCtrl;
	bool saved;
} PmPllContext;

/**
 * PmSlavePll - Structure used for Pll slave
 * @slv         Base slave structure
 * @context     Data to store context of the PLL - if after boot PLL has no
 *              context, it should not be initially locked by PMU, but by a
 *              master. To inform PMU that initially PLL has no context, this
 *              field should be initialized with the PM_PLL_CTRL_RESET_MASK
 *              set, statically or through PCW.
 * @addr        Base address of the PLL's control registers
 * @toCtrlAddr  Absolute address of cross-domain control register
 * @statusAddr  Address of the PLL's status register
 * @lockMask    Mask of the lock in status register
 */
typedef struct PmSlavePll {
	PmSlave slv;
	PmPllContext context;
	const u32 addr;
	const u32 toCtrlAddr;
	const u32 statusAddr;
	const u32 lockMask;
} PmSlavePll;

/*********************************************************************
 * Global data declarations
 ********************************************************************/
extern PmSlavePll pmSlaveApll_g;
extern PmSlavePll pmSlaveDpll_g;
extern PmSlavePll pmSlaveVpll_g;
extern PmSlavePll pmSlaveRpll_g;
extern PmSlavePll pmSlaveIOpll_g;

/*********************************************************************
 * Function declarations
 ********************************************************************/
void PmPllSuspendAll(const PmPower* const powerParent);

#endif

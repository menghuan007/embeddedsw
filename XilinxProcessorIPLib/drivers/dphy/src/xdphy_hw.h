/******************************************************************************
*
* Copyright (C) 2015 - 2016 Xilinx, Inc. All rights reserved.
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
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/
/*****************************************************************************/
/**
* @file xdphy_hw.h
* @addtogroup xdphy_v1_0
* @{
*
* Hardware definition file. It defines the register interface.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver Who Date     Changes
* --- --- -------- ------------------------------------------------------------
* 1.0 vsa 07/07/15 Initial release
* </pre>
*
*****************************************************************************/

#ifndef XDPHY_HW_H_
#define XDPHY_HW_H_		/**< Prevent circular inclusions
				  *  by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

#include "xil_types.h"
#include "xil_io.h"

/************************** Constant Definitions *****************************/

/* Register offset definitions. Register accesses are 32-bit.
 */
/** @name Device registers
 *  Register sets of MIPI DPHY
 *  @{
 */
#define XDPHY_CTRL_REG_OFFSET 		0x00000000  /**< Control Register */
#define XDPHY_HSEXIT_IDELAY_REG_OFFSET 	0x00000004  /**< HS_EXIT for Tx and
						      *  Delay for
						      *  Rx Register*/
#define XDPHY_INIT_REG_OFFSET 		0x00000008  /**< Initialization Timer
						      *  Register */
#define XDPHY_WAKEUP_REG_OFFSET 	0x0000000C  /**< Wakeup Timer for ULPS
						      *  exit Register */
#define XDPHY_HSTIMEOUT_REG_OFFSET 	0x00000010  /**< Watchdog timeout in HS
						      *  mode Register */
#define XDPHY_ESCTIMEOUT_REG_OFFSET 	0x00000014  /**< Goto Stop state on
						      *  timeout timer
						      *  Register */
#define XDPHY_CLSTATUS_REG_OFFSET   	0x00000018  /**< Clk lane PHY error
						      *  Status Register */
#define XDPHY_DL0STATUS_REG_OFFSET 	0x0000001C  /**< Data lane 0 PHY error
						      *  Status Register */
#define XDPHY_DL1STATUS_REG_OFFSET 	0x00000020  /**< Data lane 1 PHY error
						      *  Status Register */
#define XDPHY_DL2STATUS_REG_OFFSET 	0x00000024  /**< Data lane 2 PHY error
						      *  Status Register */
#define XDPHY_DL3STATUS_REG_OFFSET 	0x00000028  /**< Data lane 3 PHY error
						      *  Status Register */
/*@}*/

/** @name Bitmasks and offsets of XDPHY_CTRL_REG_OFFSET register
 *
 * This register is used for the enabling/disabling and resetting the DPHY
 * @{
 */
#define XDPHY_CTRL_REG_SOFTRESET_MASK 	0x00000001 /**< Soft Reset */
#define XDPHY_CTRL_REG_DPHYEN_MASK 	0x00000002 /**< Enable/Disable
						     *  controller */

#define XDPHY_CTRL_REG_SOFTRESET_OFFSET 0 /**< Bit offset for Soft Reset */
#define XDPHY_CTRL_REG_DPHYEN_OFFSET 1 /**< Bit offset for DPHY Enable */
/*@}*/

/** @name Bitmasks and offsets of XDPHY_HSEXIT_IDELAY_REG_OFFSET register
 *
 * This register in TX mode acts like HS_EXIT and RX mode acts like IDELAY.
 * In IDELAY mode, it is used to calibrate input delay
 * @{
 */
#define XDPHY_HSEXIT_IDELAY_REG_READY_MASK 0x00000200 /**< DLY_RDY of
						        *   BITSLICE_CONTROL */
#define XDPHY_HSEXIT_IDELAY_REG_TAP_MASK 0x000001FF /**< used in RX data lanes
						      *  to compensate clock routing
						      *  delay */
#define XDPHY_HSEXIT_IDELAY_REG_READY_OFFSET 8 /**< Bit offset for READY bit */
#define XDPHY_HSEXIT_IDELAY_REG_TAP_OFFSET 0 /**< Bit offset for TAP */
/*@}*/

/** @name Bitmasks and offsets of XDPHY_INIT_REG_OFFSET register
 *
 * This register is used for lane Initialization. Recommended to use 1ms or
 * longer in for TX mode and 200us-500us for RX mode
 * @{
 */
#define XDPHY_INIT_REG_VAL_MASK 0xFFFFFFFF /**< Init Timer value in ns */

#define XDPHY_INIT_REG_VAL_OFFSET 0 /**< Bit offset for Init Timer */
/*@}*/

/** @name Bitmask and offset of XDPHY_WAKEUP_REG_OFFSET register
 *
 * Wakeup time delay for ULPS exit.
 * @{
 */
#define XDPHY_WAKEUP_REG_VAL_MASK 	0xFFFFFFFF /**< Wakeup timer value */
#define XDPHY_WAKEUP_REG_VAL_OFFSET 	0 /**< Bit offset for Wakeup value */
/*@}*/

/** @name Bitmask and offset of XDPHY_HSTIMEOUT_REG_OFFSET register
 *
 * This register is used to program watchdog timer in high speed mode.
 * Default value is 65541. Valid range 1000-65541.
 *
 * @{
 */
#define XDPHY_HSTIMEOUT_REG_TIMEOUT_MASK 0xFFFFFFFF /**< HS_T/RX_TIMEOUT
								Received */

#define XDPHY_HSTIMEOUT_REG_TIMEOUT_OFFSET 0 /**< Bit offset for Timeout */
/*@}*/

/** @name Bitmask and offset of XDPHY_ESCTIMEOUT_REG_OFFSET register
 *
 * This register contains Rx Data Lanes timeout for watchdog timer in
 * escape mode.
 * @{
 */
#define XDPHY_ESCTIMEOUT_REG_VAL_MASK 0xFFFFFFFF /**< Escape Timout Value */
#define XDPHY_ESCTIMEOUT_REG_VAL_OFFSET 0 /**< Bit offset for Escape Timeout */
/*@}*/

/** @name Bitmask and offset of XDPHY_CLSTATUS_REG_OFFSET register
 *
 * This register contains the clock lane status and state machine control.
 * @{
 */
#define XDPHY_CLSTATUS_REG_ERRCTRL_MASK 0x00000020 /**< Clock lane control
						     *  error. Only for RX */
#define XDPHY_CLSTATUS_REG_STOPSTATE_MASK 0x00000010 /**< Clock lane stop
						       *  state */
#define XDPHY_CLSTATUS_REG_INITDONE_MASK 0x00000008 /**< Initialization done
						      *  bit */
#define XDPHY_CLSTATUS_REG_ULPS_MASK 0x00000004 /**< Set in ULPS mode */
#define XDPHY_CLSTATUS_REG_MODE_MASK 0x00000003 /**< Low, High, Esc mode */

#define XDPHY_CLSTATUS_ALLMASK 	 (XDPHY_CLSTATUS_REG_ERRCTRL_MASK |\
					XDPHY_CLSTATUS_REG_STOPSTATE_MASK |\
					XDPHY_CLSTATUS_REG_INITDONE_MASK |\
					XDPHY_CLSTATUS_REG_ULPS_MASK |\
					XDPHY_CLSTATUS_REG_MODE_MASK)

#define XDPHY_CLSTATUS_REG_ERRCTRL_OFFSET 5 /**< Bit offset for Control Error
					      *  on Clock*/
#define XDPHY_CLSTATUS_REG_STOPSTATE_OFFSET 4 /**< Bit offset for Stop State on
						*  Clock */
#define XDPHY_CLSTATUS_REG_INITDONE_OFFSET 3 /**< Bit offset for Initialization
					       *  Done */
#define XDPHY_CLSTATUS_REG_ULPS_OFFSET 2 /**< Bit offset for ULPS */
#define XDPHY_CLSTATUS_REG_MODE_OFFSET 0 /**< Bit offset for Mode bits */
/*@}*/

/** @name Bitmasks and offsets of XDPHY_DLxSTATUS_REG_OFFSET register
 *
 * This register contains the data lanes status
 * @{
 */
#define XDPHY_DLXSTATUS_REG_PACKETCOUNT_MASK 0xFFFF0000 /**< Packet Count */
#define XDPHY_DLXSTATUS_REG_STOP_MASK 0x00000040 /**< Stop State on data lane */
#define XDPHY_DLXSTATUS_REG_ESCABRT_MASK 0x00000020 /**< Set on Data Lane Esc
						      *  timeout occurs */
#define XDPHY_DLXSTATUS_REG_HSABRT_MASK 0x00000010 /**< Set on Data Lane
						     *  HS timeout */
#define XDPHY_DLXSTATUS_REG_INITDONE_MASK 0x00000008 /**< Set after
						       * initialization */
#define XDPHY_DLXSTATUS_REG_ULPS_MASK 0x00000004 /**< Set when DPHY in ULPS
						   *  mode */
#define XDPHY_DLXSTATUS_REG_MODE_MASK 0x00000003 /**< Control Mode (Esc, Low,
						   *  High) of Data Lane */

#define XDPHY_DLXSTATUS_ALLMASK	(XDPHY_DLXSTATUS_REG_MODE_MASK |\
					XDPHY_DLXSTATUS_REG_ULPS_MASK |\
					XDPHY_DLXSTATUS_REG_INITDONE_MASK |\
					XDPHY_DLXSTATUS_REG_HSABRT_MASK |\
					XDPHY_DLXSTATUS_REG_ESCABRT_MASK |\
					XDPHY_DLXSTATUS_REG_STOP_MASK)

#define XDPHY_DLXSTATUS_REG_PACKCOUNT_OFFSET 16 /**<Bit offset packet count*/
#define XDPHY_DLXSTATUS_REG_STOP_OFFSET 6 /**< Bit offset for Stop State */
#define XDPHY_DLXSTATUS_REG_ESCABRT_OFFSET 5 /**< Bit offset for Escape Abort */
#define XDPHY_DLXSTATUS_REG_HSABRT_OFFSET 4 /**< Bit offset for High Speed
							Abort */
#define XDPHY_DLXSTATUS_REG_INITDONE_OFFSET 3 /**< Bit offset for
							Initialization done */
#define XDPHY_DLXSTATUS_REG_ULPS_OFFSET 2 /**< Bit offset for ULPS */
#define XDPHY_DLXSTATUS_REG_MODE_OFFSET 0 /**< Bit offset for Modes */
/*@}*/

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/

/**
*
* This function reads a value from a DPHY register space.
* A 32 bit read is performed. If the component is implemented in a smaller
* width, only the least significant data is read from the register. The most
* significant data will be read as 0.
*
* @param	BaseAddress is the base address of the XCsiSs core instance.
* @param	RegOffset is the register offset of the register (defined at
*		the top of this file).
*
* @return	The 32-bit value of the register.
*
* @note		None.
*
******************************************************************************/
static inline u32 XDphy_ReadReg(u32 BaseAddress, u32 RegOffset)
{
	return (Xil_In32(BaseAddress + (u32)RegOffset));
}

/*****************************************************************************/
/**
*
* This function writes a value to a DPHY register space
* A 32 bit write is performed. If the component is implemented in a smaller
* width, only the least significant data is written.
*
* @param	BaseAddress is the base address of the XCsiSs core instance.
* @param	RegOffset is the register offset of the register (defined at
*		the top of this file) to be written.
* @param	Data is the 32-bit value to write into the register.
*
* @return	None.
*
* @note		None.
*
******************************************************************************/
static inline void XDphy_WriteReg(u32 BaseAddress, u32 RegOffset, u32 Data)
{
	Xil_Out32(BaseAddress + (u32)RegOffset, (u32)Data);
}

#ifdef __cplusplus
}
#endif

#endif /* end of protection macro */
/** @} */

/* Copyright (c) 2013-2016 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef DS_IO_H
#define DS_IO_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/core/log.h>

enum DSIORegisters {
	// DMA
	DS_REG_DMA0SAD_LO = 0x0B0,
	DS_REG_DMA0SAD_HI = 0x0B2,
	DS_REG_DMA0DAD_LO = 0x0B4,
	DS_REG_DMA0DAD_HI = 0x0B6,
	DS_REG_DMA0CNT_LO = 0x0B8,
	DS_REG_DMA0CNT_HI = 0x0BA,
	DS_REG_DMA1SAD_LO = 0x0BC,
	DS_REG_DMA1SAD_HI = 0x0BE,
	DS_REG_DMA1DAD_LO = 0x0C0,
	DS_REG_DMA1DAD_HI = 0x0C2,
	DS_REG_DMA1CNT_LO = 0x0C4,
	DS_REG_DMA1CNT_HI = 0x0C6,
	DS_REG_DMA2SAD_LO = 0x0C8,
	DS_REG_DMA2SAD_HI = 0x0CA,
	DS_REG_DMA2DAD_LO = 0x0CC,
	DS_REG_DMA2DAD_HI = 0x0CE,
	DS_REG_DMA2CNT_LO = 0x0D0,
	DS_REG_DMA2CNT_HI = 0x0D2,
	DS_REG_DMA3SAD_LO = 0x0D4,
	DS_REG_DMA3SAD_HI = 0x0D6,
	DS_REG_DMA3DAD_LO = 0x0D8,
	DS_REG_DMA3DAD_HI = 0x0DA,
	DS_REG_DMA3CNT_LO = 0x0DC,
	DS_REG_DMA3CNT_HI = 0x0DE,

	// Timers
	DS_REG_TM0CNT_LO = 0x100,
	DS_REG_TM0CNT_HI = 0x102,
	DS_REG_TM1CNT_LO = 0x104,
	DS_REG_TM1CNT_HI = 0x106,
	DS_REG_TM2CNT_LO = 0x108,
	DS_REG_TM2CNT_HI = 0x10A,
	DS_REG_TM3CNT_LO = 0x10C,
	DS_REG_TM3CNT_HI = 0x10E,

	// IPC
	DS_REG_IPCSYNC = 0x180,
	DS_REG_IPCFIFOCNT = 0x184,
	DS_REG_IPCFIFOSEND_LO = 0x188,
	DS_REG_IPCFIFOSEND_HI = 0x18A,
	DS_REG_IPCFIFORECV_LO = 0x100000,
	DS_REG_IPCFIFORECV_HI = 0x100002,

	// Interrupts
	DS_REG_IME = 0x208,
	DS_REG_IE_LO = 0x210,
	DS_REG_IE_HI = 0x212,
	DS_REG_IF_LO = 0x214,
	DS_REG_IF_HI = 0x216,
};

enum DS7IORegisters {
	// Video
	DS7_REG_DISPSTAT = 0x004,
	DS7_REG_VCOUNT = 0x006,

	// Keypad
	DS7_REG_KEYINPUT = 0x130,
	DS7_REG_KEYCNT = 0x132,
	DS7_REG_EXTKEYIN = 0x136,
	DS7_REG_RTC = 0x138,

	// Game card
	DS7_REG_AUXSPICNT = 0x1A0,
	DS7_REG_AUXSPIDATA = 0x1A2,
	DS7_REG_SLOT1CNT_LO = 0x1A4,
	DS7_REG_SLOT1CNT_HI = 0x1A6,
	DS7_REG_SLOT1CMD_0 = 0x1A8,
	DS7_REG_SLOT1CMD_1 = 0x1A9,
	DS7_REG_SLOT1CMD_2 = 0x1AA,
	DS7_REG_SLOT1CMD_3 = 0x1AB,
	DS7_REG_SLOT1CMD_4 = 0x1AC,
	DS7_REG_SLOT1CMD_5 = 0x1AD,
	DS7_REG_SLOT1CMD_6 = 0x1AE,
	DS7_REG_SLOT1CMD_7 = 0x1AF,
	DS7_REG_SLOT1DATA_0 = 0x100010,
	DS7_REG_SLOT1DATA_1 = 0x100011,
	DS7_REG_SLOT1DATA_2 = 0x100012,
	DS7_REG_SLOT1DATA_3 = 0x100013,

	// Etc
	DS7_REG_EXMEMSTAT = 0x204,

	// Memory control
	DS7_REG_VRAMSTAT = 0x240,
	DS7_REG_WRAMSTAT = 0x241,
	DS7_REG_POSTFLG = 0x300,
	DS7_REG_HALTCNT = 0x301,
	DS7_REG_POWCNT2 = 0x304,
	DS7_REG_BIOSPROT_LO = 0x308,
	DS7_REG_BIOSPROT_HI = 0x30A,

	DS7_REG_MAX = 0x51E,
};

enum DS9IORegisters {
	// Video
	DS9_REG_A_DISPCNT_LO = 0x000,
	DS9_REG_A_DISPCNT_HI = 0x002,
	DS9_REG_DISPSTAT = 0x004,
	DS9_REG_VCOUNT = 0x006,
	DS9_REG_A_BG0CNT = 0x008,
	DS9_REG_A_BG1CNT = 0x00A,
	DS9_REG_A_BG2CNT = 0x00C,
	DS9_REG_A_BG3CNT = 0x00E,
	DS9_REG_A_BG0HOFS = 0x010,
	DS9_REG_A_BG0VOFS = 0x012,
	DS9_REG_A_BG1HOFS = 0x014,
	DS9_REG_A_BG1VOFS = 0x016,
	DS9_REG_A_BG2HOFS = 0x018,
	DS9_REG_A_BG2VOFS = 0x01A,
	DS9_REG_A_BG3HOFS = 0x01C,
	DS9_REG_A_BG3VOFS = 0x01E,
	DS9_REG_A_BG2PA = 0x020,
	DS9_REG_A_BG2PB = 0x022,
	DS9_REG_A_BG2PC = 0x024,
	DS9_REG_A_BG2PD = 0x026,
	DS9_REG_A_BG2X_LO = 0x028,
	DS9_REG_A_BG2X_HI = 0x02A,
	DS9_REG_A_BG2Y_LO = 0x02C,
	DS9_REG_A_BG2Y_HI = 0x02E,
	DS9_REG_A_BG3PA = 0x030,
	DS9_REG_A_BG3PB = 0x032,
	DS9_REG_A_BG3PC = 0x034,
	DS9_REG_A_BG3PD = 0x036,
	DS9_REG_A_BG3X_LO = 0x038,
	DS9_REG_A_BG3X_HI = 0x03A,
	DS9_REG_A_BG3Y_LO = 0x03C,
	DS9_REG_A_BG3Y_HI = 0x03E,
	DS9_REG_A_WIN0H = 0x040,
	DS9_REG_A_WIN1H = 0x042,
	DS9_REG_A_WIN0V = 0x044,
	DS9_REG_A_WIN1V = 0x046,
	DS9_REG_A_WININ = 0x048,
	DS9_REG_A_WINOUT = 0x04A,
	DS9_REG_A_MOSAIC = 0x04C,
	DS9_REG_A_BLDCNT = 0x050,
	DS9_REG_A_BLDALPHA = 0x052,
	DS9_REG_A_BLDY = 0x054,
	DS9_REG_DISP3DCNT = 0x060,
	DS9_REG_DISPCAPCNT_LO = 0x064,
	DS9_REG_DISPCAPCNT_HI = 0x066,
	DS9_REG_DISP_MMEM_FIFO_LO = 0x068,
	DS9_REG_DISP_MMEM_FIFO_HI = 0x06A,
	DS9_REG_A_MASTER_BRIGHT = 0x06C,

	DS9_REG_B_DISPCNT_LO = 0x1000,
	DS9_REG_B_DISPCNT_HI = 0x1002,
	DS9_REG_B_BG0CNT = 0x1008,
	DS9_REG_B_BG1CNT = 0x100A,
	DS9_REG_B_BG2CNT = 0x100C,
	DS9_REG_B_BG3CNT = 0x100E,
	DS9_REG_B_BG0HOFS = 0x1010,
	DS9_REG_B_BG0VOFS = 0x1012,
	DS9_REG_B_BG1HOFS = 0x1014,
	DS9_REG_B_BG1VOFS = 0x1016,
	DS9_REG_B_BG2HOFS = 0x1018,
	DS9_REG_B_BG2VOFS = 0x101A,
	DS9_REG_B_BG3HOFS = 0x101C,
	DS9_REG_B_BG3VOFS = 0x101E,
	DS9_REG_B_BG2PA = 0x1020,
	DS9_REG_B_BG2PB = 0x1022,
	DS9_REG_B_BG2PC = 0x1024,
	DS9_REG_B_BG2PD = 0x1026,
	DS9_REG_B_BG2X_LO = 0x1028,
	DS9_REG_B_BG2X_HI = 0x102A,
	DS9_REG_B_BG2Y_LO = 0x102C,
	DS9_REG_B_BG2Y_HI = 0x102E,
	DS9_REG_B_BG3PA = 0x1030,
	DS9_REG_B_BG3PB = 0x1032,
	DS9_REG_B_BG3PC = 0x1034,
	DS9_REG_B_BG3PD = 0x1036,
	DS9_REG_B_BG3X_LO = 0x1038,
	DS9_REG_B_BG3X_HI = 0x103A,
	DS9_REG_B_BG3Y_LO = 0x103C,
	DS9_REG_B_BG3Y_HI = 0x103E,
	DS9_REG_B_WIN0H = 0x1040,
	DS9_REG_B_WIN1H = 0x1042,
	DS9_REG_B_WIN0V = 0x1044,
	DS9_REG_B_WIN1V = 0x1046,
	DS9_REG_B_WININ = 0x1048,
	DS9_REG_B_WINOUT = 0x104A,
	DS9_REG_B_MOSAIC = 0x104C,
	DS9_REG_B_BLDCNT = 0x1050,
	DS9_REG_B_BLDALPHA = 0x1052,
	DS9_REG_B_BLDY = 0x1054,
	DS9_REG_B_MASTER_BRIGHT = 0x106C,

	// Keypad
	DS9_REG_KEYINPUT = 0x130,
	DS9_REG_KEYCNT = 0x132,

	// Game card
	DS9_REG_AUXSPICNT = 0x1A0,
	DS9_REG_AUXSPIDATA = 0x1A2,
	DS9_REG_SLOT1CNT_LO = 0x1A4,
	DS9_REG_SLOT1CNT_HI = 0x1A6,
	DS9_REG_SLOT1CMD_0 = 0x1A8,
	DS9_REG_SLOT1CMD_1 = 0x1A9,
	DS9_REG_SLOT1CMD_2 = 0x1AA,
	DS9_REG_SLOT1CMD_3 = 0x1AB,
	DS9_REG_SLOT1CMD_4 = 0x1AC,
	DS9_REG_SLOT1CMD_5 = 0x1AD,
	DS9_REG_SLOT1CMD_6 = 0x1AE,
	DS9_REG_SLOT1CMD_7 = 0x1AF,
	DS9_REG_SLOT1DATA_0 = 0x100010,
	DS9_REG_SLOT1DATA_1 = 0x100011,
	DS9_REG_SLOT1DATA_2 = 0x100012,
	DS9_REG_SLOT1DATA_3 = 0x100013,

	// Etc
	DS9_REG_EXMEMCNT = 0x204,

	// Memory control
	DS9_REG_VRAMCNT_A = 0x240,
	DS9_REG_VRAMCNT_B = 0x241,
	DS9_REG_VRAMCNT_C = 0x242,
	DS9_REG_VRAMCNT_D = 0x243,
	DS9_REG_VRAMCNT_E = 0x244,
	DS9_REG_VRAMCNT_F = 0x245,
	DS9_REG_VRAMCNT_G = 0x246,
	DS9_REG_WRAMCNT = 0x247,
	DS9_REG_VRAMCNT_H = 0x248,
	DS9_REG_VRAMCNT_I = 0x249,

	// Math
	DS9_REG_DIVCNT = 0x280,
	DS9_REG_DIV_NUMER_0 = 0x290,
	DS9_REG_DIV_NUMER_1 = 0x292,
	DS9_REG_DIV_NUMER_2 = 0x294,
	DS9_REG_DIV_NUMER_3 = 0x296,
	DS9_REG_DIV_DENOM_0 = 0x298,
	DS9_REG_DIV_DENOM_1 = 0x29A,
	DS9_REG_DIV_DENOM_2 = 0x29C,
	DS9_REG_DIV_DENOM_3 = 0x29E,
	DS9_REG_DIV_RESULT_0 = 0x2A0,
	DS9_REG_DIV_RESULT_1 = 0x2A2,
	DS9_REG_DIV_RESULT_2 = 0x2A4,
	DS9_REG_DIV_RESULT_3 = 0x2A6,
	DS9_REG_DIVREM_RESULT_0 = 0x2A8,
	DS9_REG_DIVREM_RESULT_1 = 0x2AA,
	DS9_REG_DIVREM_RESULT_2 = 0x2AC,
	DS9_REG_DIVREM_RESULT_3 = 0x2AE,
	DS9_REG_SQRTCNT = 0x2B0,
	DS9_REG_SQRT_RESULT_LO = 0x2B4,
	DS9_REG_SQRT_RESULT_HI = 0x2B6,
	DS9_REG_SQRT_PARAM_0 = 0x2B8,
	DS9_REG_SQRT_PARAM_1 = 0x2BA,
	DS9_REG_SQRT_PARAM_2 = 0x2BC,
	DS9_REG_SQRT_PARAM_3 = 0x2BE,

	DS9_REG_MAX = 0x106E,

	DS9_REG_POSTFLG = 0x300,
	DS9_REG_POWCNT1 = 0x304,
};

mLOG_DECLARE_CATEGORY(DS_IO);

extern const char* const DS7IORegisterNames[];
extern const char* const DS9IORegisterNames[];

struct DS;
void DS7IOInit(struct DS* ds);
void DS7IOWrite(struct DS* ds, uint32_t address, uint16_t value);
void DS7IOWrite8(struct DS* ds, uint32_t address, uint8_t value);
void DS7IOWrite32(struct DS* ds, uint32_t address, uint32_t value);
uint16_t DS7IORead(struct DS* ds, uint32_t address);

void DS9IOInit(struct DS* ds);
void DS9IOWrite(struct DS* ds, uint32_t address, uint16_t value);
void DS9IOWrite8(struct DS* ds, uint32_t address, uint8_t value);
void DS9IOWrite32(struct DS* ds, uint32_t address, uint32_t value);
uint16_t DS9IORead(struct DS* ds, uint32_t address);

CXX_GUARD_END

#endif

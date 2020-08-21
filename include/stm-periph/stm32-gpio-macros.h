/* Reflow Oven Controller
 *
 * Copyright (C) 2020  Mario Hüttel <mario.huettel@gmx.net>
 *
 * This file is part of the Reflow Oven Controller Project.
 *
 * The reflow oven controller is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * GDSII-Converter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the reflow oven controller project.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __STM32GPIOMACROS_H__
#define __STM32GPIOMACROS_H__

#define MODER_DELETE(pin) ~(0x3U << ((pin) * 2))
#define PUPDR_DELETE(pin) ~(0x3U << ((pin) * 2))
#define OUTPUT(pin)  (0x01U << ((pin) * 2))
#define PULLUP(pin) (0x1U << ((pin)* 2))
#define PULLDOWN(pin) (0x2U << ((pin)* 2))
#define ALTFUNC(pin) ((0x2) << ((pin) * 2))
#define PINMASK(pin) ((0x3) << ((pin) * 2))
#define SETAF(PORT,PIN,AF)  PORT->AFR[((PIN) < 8 ? 0 : 1)] |= (AF) << (((PIN) < 8 ? (PIN) : ((PIN) - 8)) * 4)
#define ANALOG(pin)  (0x03 << ((pin) * 2))
#define OTYP_OPENDRAIN(pin) (0x1U << (pin))

#define BITMASK_TO_BITNO(x) (x&0x1?0:x&0x2?1:x&0x4?2:x&0x8?3: \
		 x&0x10?4:x&0x20?5:x&0x40?6:x&0x80?7: \
		 x&0x100?8:x&0x200?9:x&0x400?10:x&0x800?11: \
		 x&0x1000?12:x&0x2000?13:x&0x4000?14:x&0x8000?15: \
		 x&0x10000?16:x&0x20000?17:x&0x40000?18:x&0x80000?19: \
		 x&0x100000?20:x&0x200000?21:x&0x400000?22:x&0x800000?23: \
		 x&0x1000000?24:x&0x2000000?25:x&0x4000000?26:x&0x8000000?27: \
		 x&0x10000000?28:x&0x20000000?29:x&0x40000000?30:x&0x80000000?31:32)

#endif /* __STM32GPIOMACROS_H__ */

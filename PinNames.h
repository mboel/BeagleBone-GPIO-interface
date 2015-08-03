/*
 * PinNames.h
 *
 *  Created on: Jul 31, 2015
 *      Author: Martin Boel
 */
/* ============================================
This code code is placed under the MIT license
Copyright (c) 2015 Martin Boel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#ifndef PINNAMES_H_
#define PINNAMES_H_


typedef enum pins
{
	P9_22 = 2,		// 2
	P9_21,			// 3
	P9_18,			// 4 - Maybe allocated (I2C1_SDA)
	P9_17,			// 5 - Maybe allocated (I2C1_SCL)
	P9_42 = 7,		// 7
	P8_35,			// 8 - Allocated
	P8_33,			// 9 - Allocated
	P8_31,			// 10 - Allocated
	P8_32,			// 11 - Allocated
	P9_20,			// 12 - Allocated (I2C2_SDA)
	P9_19,			// 13 - Allocated (I2C2_SCL)
	P9_26 = 14,		// 14
	P9_24,			// 15
	P8_19 = 22,		// 22
	P8_13,			// 23
	P8_14 = 26,		// 26
	P8_17,			// 27
	P9_11 = 30,		// 30
	P9_13,			// 31 - Maybe allocated
	P8_25,			// 32 - Allocated
	P8_24,			// 33 - Allocated
	P8_05,			// 34 - Allocated
	P8_06,			// 35 - Allocated
	P8_23, 			// 36 - Allocated
	P8_22, 			// 37 - Allocated
	P8_03,			// 38 - Allocated
	P8_04,			// 39 - Allocated
	P8_12 = 44,		// 44
	P8_11,			// 45
	P8_16,			// 46
	P8_15, 			// 47
	P9_15,			// 48
	P9_23,			// 49
	P9_14,			// 50
	P9_16,			// 51
	P9_12 = 60,		// 60
	P8_26,			// 61
	P8_21,			// 62 - Allocated
	P8_20,			// 63 - Allocated
	P8_18 = 65,		// 65
	P8_07,			// 66
	P8_08,			// 67
	P8_10,			// 68
	P8_09,			// 69
	P8_45,			// 70 - Allocated
	P8_46,			// 71 - Allocated
	P8_43,			// 72 - Allocated
	P8_44,			// 73 - Allocated
	P8_41,			// 74 - Allocated
	P8_42,			// 75 - Allocated
	P8_39,			// 76 - Allocated
	P8_40,			// 77 - Allocated
	P8_37,			// 78 - Allocated
	P8_38,			// 79 - Allocated
	P8_36,			// 80 - Allocated
	P8_34,			// 81 - Allocated
	P8_27 = 86,		// 86 - Allocated
	P8_29,			// 87 - Allocated
	P8_28,			// 88 - Allocated
	P8_30,			// 89 - Allocated
	P9_31 = 110,	// 110
	P9_29,			// 110
	P9_30,			// 112
	P9_28,			// 113
	P9_27 = 115,	// 115
	P9_41,			// 116
	P9_25			// 117
} PinName;

#endif /* PINNAMES_H_ */

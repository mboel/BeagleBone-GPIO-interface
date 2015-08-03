/*
 * GpioOut.h
 *
 *  Created on: Aug 3, 2015
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

#ifndef GPIOOUT_H_
#define GPIOOUT_H_

#include "GpioSysfs.h"

class GpioOut: public GpioSysfs
{
public:
	GpioOut(PinName pin);
	virtual ~GpioOut();

	/** Write the output, represented as 0 or 1 (int)
	 *
	 *  @param
	 *    A bool representing the state of the output pin,
	 *    0 for logical 0, 1 for logical 1
	 */
	int write(bool value)
	{
		return set_value(value);
	}

	/** A shorthand for write()
	 */
	GpioOut& operator=(int value)
	{
		write(value);
		return *this;
	}

};

#endif /* GPIOOUT_H_ */

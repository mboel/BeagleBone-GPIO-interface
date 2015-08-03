/*
 * GpioIn.h
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

#ifndef GPIOIN_H_
#define GPIOIN_H_


#include "PinNames.h"
#include "GpioSysfs.h"

class GpioIn : public GpioSysfs
{
private:
public:
	GpioIn(PinName pin);
	virtual ~GpioIn();

	/** Read the input, represented as 0 or 1 (int)
	 *
	 *  @returns
	 *    An integer representing the state of the input pin,
	 *    0 for logical 0, 1 for logical 1
	 */
	int read()
	{
		return get_value();
	}

	/** An operator shorthand for read()
	 */
	operator int()
	{
		return read();
	}
};

#endif /* GPIOIN_H_ */

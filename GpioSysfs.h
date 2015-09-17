/*
 * GpioSysfs.h
 *
 *  Created on: Aug 2, 2015
 *      Author: Martin Boel
 *  Other: Documentation about the sysfs interface can be found at
 *  https://www.kernel.org/doc/Documentation/gpio/sysfs.txt
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

#ifndef GPIOSYSFS_H_
#define GPIOSYSFS_H_

#include <string>
#include "PinNames.h"

class GpioSysfs
{
	int gpio_num;
	int export_gpio();
	int unexport_gpio();
public:
	GpioSysfs(PinName PinName);
	virtual ~GpioSysfs();
	int set_direction(std::string dir);
	int get_value();
	int set_value(bool value);
	int set_edge(std::string edge);
	int poll_pin(int time);
};

#endif /* GPIOSYSFS_H_ */

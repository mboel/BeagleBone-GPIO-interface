/*
 * GpioSysfs.cpp
 *
 *  Created on: Aug 2, 2015
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

#include "GpioSysfs.h"
#include <unistd.h>
#include <iostream>
#include <fcntl.h>

/** Export a GPIO pin
 *	@param gpio_num		The pin number to export
 *	@return The Status of export operation (1 = success)
 */
int GpioSysfs::export_gpio()
{
	int retval = 1;
	std::string export_str = "/sys/class/gpio/export";
	std::string number_str = std::to_string(gpio_num);
	int fd = open(export_str.c_str(), O_WRONLY | O_SYNC);
	if (fd < 0)
	{
		std::cerr << "could not open /sys/class/gpio/export\n";
	}

	retval = write(fd, number_str.c_str(), number_str.length());
	if (retval < 0)
	{
		std::cerr << "could not write " << gpio_num
				<< " to /sys/class/gpio/export\n";
	}

	retval = close(fd);
	if (retval < 0)
	{
		std::cerr << "could not close /sys/class/gpio/export\n";
	}

	return fd;
}

/** Unexport a GPIO pin
 *	@param gpio_num		The pin number to export
 *	@return The Status of unexport operation (1 = success)
 */
int GpioSysfs::unexport_gpio()
{
	int retval = 1;
	std::string unexport_str = "/sys/class/gpio/unexport";
	std::string number_str = std::to_string(gpio_num);
	int fd = open(unexport_str.c_str(), O_WRONLY | O_SYNC);
	if (fd < 0)
	{
		std::cerr << "could not open /sys/class/gpio/unexport\n";
	}

	retval = write(fd, number_str.c_str(), number_str.length());
	if (retval < 0)
	{
		std::cerr << "could not write to /sys/class/gpio/unexport\n";
	}

	retval = close(fd);
	if (retval < 0)
	{
		std::cerr << "could not close /sys/class/gpio/unexport\n";
	}

	return fd;
}

GpioSysfs::GpioSysfs(PinName PinName)
{
	gpio_num = PinName;
	export_gpio();

}

GpioSysfs::~GpioSysfs()
{
	unexport_gpio();
}

/**
 * Set pin direction
 * @param 	dir	The direction of the pin. Valid inputs are "in" and "out"
 * @return	Returns the status of the operation (-1 = failed)
 */
int GpioSysfs::set_direction(std::string dir)
{
	int fd;
	int retval = -1;
	std::string dir_str = "/sys/class/gpio/gpio" + std::to_string(gpio_num)
			+ "/direction";

	fd = open(dir_str.c_str(), O_WRONLY | O_SYNC); // open direction file for gpio
	if (fd < 0)
	{
		std::cerr << "could not open " << dir_str << std::endl;
	}

	if (dir.compare("in") && dir.compare("out"))
	{
		std::cerr << "Invalid direction value. Should be \"in\" or \"out\". \n";
	}

	retval = write(fd, dir.c_str(), dir.length());
	if (retval < 0)
	{
		std::cerr << "could not write to " << dir_str << std::endl;
	}

	retval = close(fd);
	if (retval < 0)
	{
		std::cerr << "could not close " << dir_str << std::endl;
	}

	return retval;
}

/**
 * Read the value of a gpio pin.
 * @return Returns the value of the pin (-1 = could not read the value)
 */
int GpioSysfs::get_value()
{
	int fd;
	int retval = -1;
	char val;
	std::string setValStr = "/sys/class/gpio/gpio" + std::to_string(gpio_num)
			+ "/value";

	fd = open(setValStr.c_str(), O_WRONLY | O_SYNC);
	if (fd < 0)
	{
		std::cerr << "could not open " << setValStr;
	}

	retval = read(fd, &val, 1);
	if (retval != -1)
	{
		retval = val;
	}
	else
	{
		std::cerr << "could not read " << setValStr << std::endl;
	}
	return retval;
}

/**
 * Set the output value of a gpio pin
 * @param value	The output value (1 = output high)
 * @return
 */
int GpioSysfs::set_value(bool value)
{
	int fd;
	int retval = -1;
	char val;
	std::string setValStr = "/sys/class/gpio/gpio" + std::to_string(gpio_num)
			+ "/value";

	if (value)
	{
		val = '1';
	}
	else
	{
		val = '0';
	}

	fd = open(setValStr.c_str(), O_WRONLY | O_SYNC);
	if (fd < 0)
	{
		std::cerr << "could not open " << setValStr << std::endl;
	}

	retval = write(fd, &val, 1);
	if (retval < 0)
	{
		std::cerr << "could not write to " << setValStr << std::endl;
	}

	retval = close(fd);
	if (retval < 0)
	{
		std::cerr << "could not close " << setValStr << std::endl;
	}

	return retval;
}

/**
 * The the edge of the pin can be used as interrups
 * @param edge The val that makes poll(2) return.
 * <pre>
 * Valid inputs are:
 *  - "none"
 *  - "rising"
 *  - "falling"
 *  </pre>
 * @return Return the status (0 = success)
 */
int GpioSysfs::set_edge(std::string edge)
{
	int fd;
	int retval = -1;
	std::string edge_str = "/sys/class/gpio/gpio" + std::to_string(gpio_num)
			+ "/edge";

	fd = open(edge_str.c_str(), O_WRONLY | O_SYNC); // open direction file for gpio
	if (fd < 0)
	{
		std::cerr << "could not open " << edge_str << std::endl;
	}

	if (edge.compare("none") && edge.compare("rising") && edge.compare("falling"))
	{
		std::cerr << "Invalid edge value. Should be \"none\", \"rising\" or \"falling\". \n";
	}

	retval = write(fd, edge.c_str(), edge.length());
	if (retval < 0)
	{
		std::cerr << "could not write to " << edge_str << std::endl;
	}

	retval = close(fd);
	if (retval < 0)
	{
		std::cerr << "could not close " << edge_str << std::endl;
	}

	return retval;
}

/*
 * test.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: boel
 */

#include <iostream>
#include "GpioIn.h"
#include "GpioOut.h"
#include "GpioSysfs.h"
#include "unistd.h"

int main()
{
	int runs = 4;

	GpioSysfs *pin7 = new GpioSysfs(P9_42);
	pin7->set_direction("out");

	while(runs--)
	{
		std::cout << "GpioSysfs On\n";
		pin7->set_value(1);
		sleep(1);
		std::cout << "GpioSysfs Off\n";
		pin7->set_value(0);
		sleep(1);
	}

	delete pin7;

	GpioOut pin(P9_31);

	runs = 2;

	while(runs--)
	{
		std::cout << "GpioOut On\n";
		pin = 1;
		sleep(1);
		std::cout << "GpioOut Off\n";
		pin = 0;
		sleep(1);

	}

	GpioIn pin_in(P9_30);

	std::cout << "Pin value: " << pin_in << std::endl;

	return 0;
}


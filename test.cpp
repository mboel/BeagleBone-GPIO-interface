/*
 * test.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: boel
 */

#include <iostream>
#include "unistd.h" // for sleep
#include "GpioIn.h"
#include "GpioOut.h"
#include "GpioSysfs.h"
#include "InterruptIn.h"

bool interrupt_occurred = false;

void interrupt_func()
{
	std::cout << "\nHello interrupt! :)\n" << std::endl;
	//interrupt_occurred = true;
}




int main()
{
	int runs = 4;

//	GpioSysfs *pin7 = new GpioSysfs(P9_42);
//	pin7->set_direction("out");
//
//	while(runs--)
//	{
//		std::cout << "GpioSysfs On\n";
//		pin7->set_value(1);
//		sleep(1);
//		std::cout << "GpioSysfs Off\n";
//		pin7->set_value(0);
//		sleep(1);
//	}
//
//	delete pin7;
//
//	GpioOut pin(P9_31);
//
//	runs = 2;
//
//	while(runs--)
//	{
//		std::cout << "GpioOut On\n";
//		pin = 1;
//		sleep(1);
//		std::cout << "GpioOut Off\n";
//		pin = 0;
//		sleep(1);
//
//	}
//
//	runs = 20;
//	GpioIn pin_in(P9_42);
//	while(runs--)
//	{
//		std::cout << "Pin value: " << pin_in << std::endl;
//		sleep(1);
//	}

//	// test interrupt in
//	GpioOut interrupt_trigger(P9_41);
//	InterruptIn *int7 = new InterruptIn(P9_42);
//	int7->set_edge("rising");
//	int7->enable(interrupt_func);
//
//	interrupt_trigger = 0;
//	int num_of_dots = 45;
//	bool value = 0;
//	std::cout << "just before while loop" << std::endl;
//	while(!interrupt_occurred)
//	{
//		usleep(5000);
//		printf(".");
//		fflush(stdout);
//		usleep(5000);
//		if(!num_of_dots--)
//		{
//			printf("\n");
//			printf("value: %d\n",value);
//			num_of_dots = 45;
//			value = value ? 0 : 1;
//			interrupt_trigger = value;
//		}
//	}
//
//	delete int7;

	GpioSysfs pin(P9_21);
	runs = 20;

	pin.set_direction("in");
	pin.set_edge("rising");

	while(runs--)
	{
		int retval = pin.poll_pin(-1);
		std::cout << "Retval: " << retval << std::endl;
	}

	return 0;
}


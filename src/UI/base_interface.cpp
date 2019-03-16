/*
 * base_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */
#include <iostream>
#include "base_interface.hpp"

namespace UI {


int Interface::get_number()
{
	int input;
	std::cin >> input;
	while(std::cin.fail()) {
		std::cout << "Error, please enter an integer" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> input;
	}
	return input;
}

std::string Interface::get_name()
{
	std::string input;
	std::cin >> input;
	return input;
}

}//end namespace

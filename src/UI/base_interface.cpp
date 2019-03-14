/*
 * base_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#include "base_interface.hpp"

namespace UI {


int Interface::get_number()
{
	int x;
	std::cin >> x;
	while(std::cin.fail()) {
		std::cout << "Error, please enter an integer" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> x;
	}
	return x;
}

}//end namespace

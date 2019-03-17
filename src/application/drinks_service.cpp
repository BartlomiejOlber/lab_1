/*
 * drinks_service.cpp
 *
 *  Created on: Mar 16, 2019
 *      Author: bartlomiej
 */

#include "drinks_service.hpp"


namespace application {

const char* DrinksService::get_container_config_file()
{
	return "drinks.txt";
}

}// end namespace

/*
 * containers_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#include "containers_interface.hpp"

namespace UI{

void ContainersInterface::display_inventory()
{
	std::cout<< "[1]. Open refridgerator"<< std::endl;
	std::cout<< "[2]. Open candy drawer"<< std::endl;
	std::cout<< "[3]. Open drinks cupboard"<< std::endl;
	std::cout<< "[4]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ContainersInterface::display_options()
{
	std::cout<< "[1]. Remove an item"<< std::endl;
	std::cout<< "[2]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}


void ContainersInterface::loop()
{
	int choice = 0;
	do{
		//std::system("clear");
		display_inventory();
		choice = get_number();
		switch(choice)
		{
			case 1:
				run_refridgerator();
				break;
			case 2:
				run_candys();
				break;
			case 3:
				run_drinks();
				break;
		}

	}while(choice != 4);
}

int ContainersInterface::get_choice()
{
	int choice = 0;
	int item_choice = 0;
	choice = get_number();
	if( choice == 2 )
		return 0;
	std::cout << "Enter the index of chosen item" << std::endl;
	item_choice = get_number();
	return item_choice;
}

void ContainersInterface::run_refridgerator()
{
	application::RefridgeratorService service;
	//std::system("clear");
	service.display_content();
	display_options();
	service.remove( get_choice() );
}


void ContainersInterface::run_candys()
{
	application::CandysService service;
	//std::system("clear");
	service.display_content();
	display_options();
	service.remove( get_choice() );
}

void ContainersInterface::run_drinks()
{
	application::DrinksService service;
	//std::system("clear");
	service.display_content();
	display_options();
	service.remove( get_choice() );
}

}//end namespace

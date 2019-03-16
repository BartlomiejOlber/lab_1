/*
 * shopping_list_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#include "shopping_list_interface.hpp"
#include <iostream>

namespace UI{

void ListInterface::display()
{
	std::cout<< "[1]. Generate shopping list"<< std::endl;
	std::cout<< "[2]. Edit shopping list"<< std::endl;
	std::cout<< "[3]. Generation preferences"<< std::endl;
	std::cout<< "[4]. Save shopping list"<< std::endl;
	std::cout<< "[5]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ListInterface::display_edit()
{
	std::cout<< "[1]. Remove an item"<< std::endl;
	std::cout<< "[2]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ListInterface::display_preferences()
{
	std::cout<< "[1]. Generate by containers state"<< std::endl;
	std::cout<< "[2]. Generate by expiry date"<< std::endl;
	std::cout<< "[3]. Generate by initial preferences"<< std::endl;
	std::cout<< "[4]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ListInterface::loop()
{
	int choice = 0;
	do{
		//std::system("clear");
		display();
		choice = get_number();
		switch(choice)
		{
			case 1:
				run_generation();
				break;
			case 2:
				run_edit();
				break;
			case 3:
				run_preferences();
				break;
			case 4:
				save();
				break;
		}

	}while(choice != 5);
}

void ListInterface::run_generation()
{/**
	application::ListService list;
	list.generate();
	list.display_content();
**/
}

void ListInterface::run_edit()
{

}

void ListInterface::run_preferences()
{

}

void ListInterface::save()
{

}


}//end namespace

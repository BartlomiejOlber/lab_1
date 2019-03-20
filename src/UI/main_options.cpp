/*
 * main_options.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */
#include <iostream>
#include <cstdlib>
#include "main_options.hpp"
#include "containers_interface.hpp"
#include "preference_interface.hpp"
#include "shopping_list_interface.hpp"
#include "stock_interface.hpp"

namespace UI{

void MainOptions::display()
{
	std::cout<< "\n\n\t*Available options:*\n\n" << std::endl;
	std::cout<< "[1]. Show stock" << std::endl;
	std::cout<< "[2]. House inventory"<< std::endl;
	std::cout<< "[3]. Shopping list"<<std::endl;
	std::cout<< "[4]. Preferences"<<std::endl;
	std::cout<< "[5]. Exit"<<std::endl;
	std::cout<< "\n Selection: ";
}

void MainOptions::loop_controler()
{
	int choice = 3;
	do{
		std::system("clear");
		display();
		//choice = get_number();
		switch(choice)
		{
			case 1:
				run_stock();
				break;
			case 2:
				run_containers();
				break;
			case 3:
				run_shopping_list();
				break;
			case 4:
				run_preferences();
				break;
		}

	}while(choice != 5);
}

void MainOptions::run_stock()
{
	StockInterface si;
	si.show();
}

void MainOptions::run_containers()
{
	ContainersInterface ci;
	ci.loop();
}

void MainOptions::run_shopping_list()
{
	ListInterface li;
	li.loop();
}

void MainOptions::run_preferences()
{
	PreferenceInterface pi;
	pi.loop();
}

}


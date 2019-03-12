/*
 * main_options.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */
#include "main_options.hpp"
#include "../application/stock_service.hpp"
#include "../domain/model/stock.hpp"
#include "../domain/model/available_item.hpp"
#include <iostream>
#include <cstdlib>

namespace UI{

void MainOptions::display()
{
	std::cout<< "Available options: " << std::endl;
	std::cout<< "[1]. Show stock" << std::endl;
	std::cout<< "[2]. House inventory"<< std::endl;
	std::cout<< "[3]. Shopping list"<<std::endl;
	std::cout<< "[4]. Exit"<<std::endl;
	std::cout<< "\n Selection: ";
}

void MainOptions::display_house_inventory()
{
	std::cout<< "[1]. Open refridgerator"<< std::endl;
	std::cout<< "[2]. Open candy drawer"<< std::endl;
	std::cout<< "[3]. Open drinks cupboard"<< std::endl;
}

int MainOptions::get_choice()
{
	int choice;
	std::cin >> choice;
	return choice;
}

void MainOptions::loop_controler()
{
	int choice = 0;
	do{
		//std::system("clear");
		display();
		choice = get_choice();
		switch(choice)
		{
			case 1:
				show_stock();
				break;

		}

	}while(choice != 4);
}

void MainOptions::show_stock()
{
	domain::model::Stock stock;
	application::StockService stock_service;
	stock_service.get_stock( stock );
	const domain::model::Stock::AvailableItemsT& items = stock.get_items();
	domain::model::Stock::AvailableItemsT::const_iterator pos;
	for(pos = items.begin(); pos!=items.end(); ++pos){
		std::cout << pos->get_name() << ": " << pos->get_price() << "$ " << pos->get_quantity()
				<< pos->get_unit() << std::endl;
	}
}

}


/*
 * containers_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#include "containers_interface.hpp"
#include "../application/refridgerator_service.hpp"
#include "../domain/model/refridgerator.hpp"

namespace UI{

using namespace domain::model;
using namespace application;

class ContainerUI {

public:
	static void print_content( const SmartProductContainer& container );
};

void ContainerUI::print_content( const SmartProductContainer& container )
{
	std::system("clear");
	const SmartProductContainer::ContentT& products = container.get_products();
	SmartProductContainer::ContentT::const_iterator pos;
	for(pos = products.begin(); pos!=products.end(); ++pos){
		std::cout << pos->get_name() << ":  " << pos->get_price() << "$   " << pos->get_current_quantity()
			<< ProductUnitConverter::to_str(pos->get_unit())<< "    "<< pos->get_expiry_date_str() <<std::endl;
	}
}

void ContainersInterface::display_inventory()
{
	std::system("clear");
	std::cout<< "[1]. Open refridgerator"<< std::endl;
	std::cout<< "[2]. Open candy drawer"<< std::endl;
	std::cout<< "[3]. Open drinks cupboard"<< std::endl;
	std::cout<< "[4]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ContainersInterface::display_options()
{
	std::cout<< "\n\n[1]. Remove an item"<< std::endl;
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
		return -1;
	std::cout << "Enter the index of chosen item" << std::endl;
	item_choice = get_number();
	return item_choice;
}

void ContainersInterface::run_refridgerator()
{
	int choice = 0;
	Refridgerator refridgerator;
	SmartProductContainer::ContentT products;
	RefridgeratorService service;
	service.init_container( refridgerator );
	ContainerUI::print_content( refridgerator );

	display_options();
	do{
		choice = get_number();
		if( choice == 1){
			std::cout << "\n\tName the product you want to consume: ";
			std::string consumed_product = get_name();
			refridgerator.find_product( consumed_product, products );
			refridgerator.remove_product( products );
		}
	}while( choice!=2 );
	service.save_container( refridgerator );

}


void ContainersInterface::run_candys()
{
	/**
	application::CandysService service;
	//std::system("clear");
	service.display_content();
	display_options();
	service.remove( get_choice() );
**/
}

void ContainersInterface::run_drinks()
{/**
	application::DrinksService service;
	//std::system("clear");
	service.display_content();
	display_options();
	service.remove( get_choice() );
	**/
}

}//end namespace

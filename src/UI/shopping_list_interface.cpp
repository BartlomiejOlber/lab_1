/*
 * shopping_list_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */
#include <iomanip>
#include <iostream>
#include "shopping_list_interface.hpp"
#include "../application/shopping_list_service.hpp"
#include "../application/stock_service.hpp"



namespace UI{

using namespace domain::model;
using namespace application;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

class ListUI : public Interface {

public:
	ShoppingList& shopping_list_;
	const Stock& stock_;
	ListUI( ShoppingList& shopping_list , const Stock& stock) : shopping_list_( shopping_list ), stock_(stock) {};
	void run_edit();
	void print_list();
	void edit_options();
	void remove_item();
	void add_item();
};


void ListUI::run_edit()
{
	int choice = 0;
	do{
		edit_options();
		choice = get_number();
		switch(choice)
		{
			case 1:
				remove_item();
				break;
			case 2:
				add_item();
				break;
		}
	}while(choice != 3);
}

void ListUI::print_list()
{
	std::system( "clear" );
	const ShoppingList::ItemListT& items = shopping_list_.get_items();
	ShoppingList::ItemListT::const_iterator pos;
	cout<< " \n\n\t *Shopping list*\n\n";
	for(pos = items.begin(); pos!=items.end(); ++pos){
		cout << "\t| Product | "<< setw( 10 ) << right <<pos->get_name() << " | " << setw( 5 )<< right <<pos->get_price()
				<< "$ | "<< setw(3) << right <<pos->get_quantity() << setw(5) << left
				<< ProductUnitConverter::to_str(pos->get_unit())<< " |" << endl;
	}
	cout<< " \n [1]. Back"<<endl;
	cout<< "\n Selection: ";
	int choice = 0;
	while (choice!=1)
	{
		choice = get_number();
	}
}

void ListUI::remove_item()
{
	std::string item_name;
	cout << "\n\tName the item: ";
	item_name = get_name();
	shopping_list_.remove_item( item_name );
}

void ListUI::add_item()
{
	std::string item_name;
	cout << "\n\tName the item: ";
	item_name = get_name();
	const AvailableItem* item = stock_.find_item( item_name );
	if( !item ){
		cout << "No such item in stock"<<endl;
	}
	shopping_list_.add_item( *item );
}

void ListUI::edit_options()
{
	std::cout<< "[1]. Remove an item"<< std::endl;
	std::cout<< "[2]. Add an item"<< std::endl;
	std::cout<< "[3]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ListInterface::display()
{
	std::cout<< "[1]. Show shopping list"<< std::endl;
	std::cout<< "[2]. Edit shopping list"<< std::endl;
	std::cout<< "[3]. Save shopping list"<< std::endl;
	std::cout<< "[4]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ListInterface::loop()
{
	ShoppingList shopping_list;
	ShoppingListService service;
	Stock stock;
	StockService stock_service;
	stock_service.get_stock( stock );
	service.generate_list( shopping_list );
	ListUI shopping_list_ui( shopping_list );
	int choice = 0;
	do{
		//std::system("clear");
		display();
		choice = get_number();
		switch(choice)
		{
			case 1:
				shopping_list_ui.print_list();
				break;
			case 2:
				shopping_list_ui.run_edit();
				break;
			case 3:
				service.store( shopping_list );
				break;
		}
	}while(choice != 4);
}

}//end namespace

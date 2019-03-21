/*
 * stock_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */
#include <iomanip>
#include "stock_interface.hpp"
#include "../application/stock_service.hpp"
#include "../domain/model/stock.hpp"
#include "../domain/model/available_item.hpp"
#include "../domain/model/product_unit.hpp"

namespace UI{

using namespace domain::model;
using namespace application;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

void StockInterface::show()
{
	int choice = 0;
	std::system( "clear" );
	Stock stock;
	StockService stock_service;
	stock_service.get_stock( stock );
	const Stock::AvailableItemsT& items = stock.get_items();
	Stock::AvailableItemsT::const_iterator pos;
	cout<< " \n\n\t *Shop inventory*\n\n";
	for(pos = items.begin(); pos!=items.end(); ++pos){
		cout << "\t| Product | "<< setw( 20 ) << right <<pos->get_name() << " | " << setw( 5 )<< right <<pos->get_price()
				<< "$ | "<< setw(3) << right <<pos->get_quantity() << setw(5) << left
				<< ProductUnitConverter::to_str(pos->get_unit())<< " |" << endl;
	}
	cout<< " \n [1]. Back"<<endl;
	cout<< "\n Selection: ";
	while (choice!=1)
	{
		choice = get_number();
	}
}

}//end namespace

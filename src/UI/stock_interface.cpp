/*
 * stock_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#include "stock_interface.hpp"
#include "../application/stock_service.hpp"
#include "../domain/model/stock.hpp"
#include "../domain/model/available_item.hpp"
#include "../domain/model/product_unit.hpp"

namespace UI{

using namespace domain::model;
using namespace application;

void StockInterface::show()
{
	Stock stock;
	StockService stock_service;
	stock_service.get_stock( stock );
	const Stock::AvailableItemsT& items = stock.get_items();
	Stock::AvailableItemsT::const_iterator pos;
	for(pos = items.begin(); pos!=items.end(); ++pos){
		std::cout << pos->get_name() << ": " << pos->get_price() << "$ " << pos->get_quantity()
				<< ProductUnitConverter::to_str(pos->get_unit()) << std::endl;
	}
}

}//end namespace

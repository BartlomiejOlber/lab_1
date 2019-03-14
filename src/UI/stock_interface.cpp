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

namespace UI{


void StockInterface::show()
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

}//end namespace

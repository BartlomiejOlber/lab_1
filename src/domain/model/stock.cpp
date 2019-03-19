/*
 * stock.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#include "stock.hpp"

namespace domain {
namespace model {

void Stock::add_item( const AvailableItem& item )
{
	stock_.push_back( item );
}

void Stock::add_item( const std::string& name, double price, double quantity, int unit )
{
	AvailableItem item( name, price, quantity, unit );
	stock_.push_back( item );
}

const AvailableItem* Stock::find_item( const std::string& name ) const
{
	AvailableItem* result = 0;
	Stock::AvailableItemsT::const_iterator pos = stock_.begin();
	while( !result && pos!=stock_.end() )
	{
		if( pos->get_name() == name ){
			result = pos;
		}
		++pos;
	}
	return result;
}

const Stock::AvailableItemsT& Stock::get_items() const
{
	return stock_;
}

}//end namespace model
}//end namespace domain

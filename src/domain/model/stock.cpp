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

void Stock::print() const
{
	std::vector<AvailableItem>::const_iterator pos;
	for(pos = stock_.begin(); pos!=stock_.end(); ++pos){
		(*pos).print();
	}
}

const std::vector<AvailableItem>& Stock::get_items() const
{
	return stock_;
}

}//end namespace model
}//end namespace domain

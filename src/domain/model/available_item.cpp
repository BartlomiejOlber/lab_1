/*
 * available_item.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */
#include "available_item.hpp"

namespace domain {
namespace model {

void AvailableItem::set_name( const std::string& name )
{
	name_ = name;
}

void AvailableItem::set_price( double price )
{
	price_ = price;
}
void AvailableItem::set_quantity( double quantity )
{
	quantity_ = quantity;
}
void AvailableItem::set_unit( ProductUnit unit )
{
	unit_ = unit;
}

}//end namespace model
}//end namespace domain


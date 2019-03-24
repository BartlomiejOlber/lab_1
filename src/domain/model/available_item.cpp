/*
 * available_item.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */
#include "available_item.hpp"
#include <iostream>

namespace domain {
namespace model {


const std::string& AvailableItem::get_name() const
{
	return name_;
}

double AvailableItem::get_price() const
{
	return price_;
}

double AvailableItem::get_quantity() const
{
	return quantity_;
}

ProductUnit AvailableItem::get_unit() const
{
	return unit_;

}

int AvailableItem::how_many_needed( double quantity_needed ) const
{
	return (int)( quantity_needed/quantity_ + 0.5) ;
}


}//end namespace model
}//end namespace domain


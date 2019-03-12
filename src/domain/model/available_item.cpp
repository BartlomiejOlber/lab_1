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

void AvailableItem::print() const
{
	std::cout << name_ << ": " << price_ << "$ " << quantity_ << (int)unit_ << std::endl;
}

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
std::string AvailableItem::get_unit() const
{
	return "kilo";
}



}//end namespace model
}//end namespace domain


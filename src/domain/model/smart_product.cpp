/*
 * product.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: bartlomiej
 */

#include "smart_product.hpp"

#include <iostream>

namespace domain {
namespace model {


SmartProduct::SmartProduct( const std::string& name, double price, time_t expiry_date, double quantity, ProductUnit unit )
{
	name_ = name;
	price_ = price;
	initial_quantity_ = quantity;
	current_quantity_ = quantity;
	expiry_date_ = expiry_date; //todo: change to a proper format
	unit_ = unit;
}

void SmartProduct::validate()
{
	if( name_.length() < 4)
		throw SmartProductNameException();
	if( price_ < 0.0 )
		throw SmartProductPriceException();
	if( expiry_date_ < 0 ) //todo: validate expiry date to be a future date
		throw SmartProductExpiryDateException();
	if( initial_quantity_ < 0 )
		throw SmartProductQuantityException();
}

time_t SmartProduct::get_expiry_date() const
{
	return expiry_date_;
}

const std::string& SmartProduct::get_name() const
{
	return name_;
}

double SmartProduct::get_price() const
{
	return price_;
}

double SmartProduct::get_current_quantity() const
{
	return current_quantity_;

}

double SmartProduct::get_initial_quantity() const
{
	return initial_quantity_;
}

void SmartProduct::print_state() const
{
	std::cout << "Milk:"<<std::endl;
	std::cout << "\tName: "<< name_<< std::endl;
	std::cout << "\tPrice: "<< price_<< std::endl;
	std::cout << "\tCurrent quantity: "<< current_quantity_<< std::endl;
	std::cout << "\tExpiry date: "<< expiry_date_ << std::endl;
}

bool SmartProduct::operator==( const SmartProduct& right ) const
{
	return name_ == right.name_ && expiry_date_ == right.expiry_date_ &&
			price_ == right.price_ && current_quantity_ == right.current_quantity_ && initial_quantity_ == right.initial_quantity_;
}


}//end namespace model
}//end namespace domain



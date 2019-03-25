/*
 * product.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: bartlomiej
 */

#include "smart_product.hpp"

#include <iostream>
#include <sstream>

namespace domain {
namespace model {


const std::tm& SmartProduct::get_expiry_date() const
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

ProductUnit SmartProduct::get_unit() const
{
	return unit_;
}

std::string SmartProduct::get_expiry_date_str() const
{
	char date[11] = {0};
	std::strftime(date,11,"%Y-%m-%d", &expiry_date_ );
	return std::string(date);

}

bool SmartProduct::operator==( const SmartProduct& right ) const
{
	time_t this_time = mktime( (std::tm*)&expiry_date_ );
	time_t right_time = mktime( (std::tm*)&right.expiry_date_);
	return name_ == right.name_ && difftime( this_time, right_time ) == 0 &&
			price_ == right.price_ && current_quantity_ == right.current_quantity_ && initial_quantity_ == right.initial_quantity_;
}


}//end namespace model
}//end namespace domain



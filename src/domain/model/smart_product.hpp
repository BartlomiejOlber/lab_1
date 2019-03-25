/*
 * product.hpp
 *
 *  Created on: Mar 9, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_SMART_PRODUCT_HPP_
#define DOMAIN_MODEL_SMART_PRODUCT_HPP_

#include <ctime>
#include <string>
#include "smart_product_exception.hpp"
#include "product_unit.hpp"

namespace domain {
namespace model {

class SmartProduct {
private:
	std::string name_;
	double price_;
	double initial_quantity_;
	double current_quantity_;
	std::tm expiry_date_;
	ProductUnit unit_;

public:
	SmartProduct() :name_(""), price_(0.0), initial_quantity_(0.0), current_quantity_(0.0),
	  unit_( ProductUnit::UNKNOWN ) {

	};
	SmartProduct( const std::string& name, double price, const std::tm& expiry_date, double quantity, int unit ) :
		name_(name), price_(price), initial_quantity_(quantity), current_quantity_(quantity),
		 expiry_date_(expiry_date), unit_( ProductUnitConverter::from_int( unit ) ){};
	const std::string& get_name() const;
	double get_price() const;
	double get_current_quantity() const;
	double get_initial_quantity() const;
	const std::tm& get_expiry_date() const;
	std::string get_expiry_date_str() const;
	ProductUnit get_unit() const;
	bool operator==( const SmartProduct& right ) const;
};

} //end namespace model
} // end namespace domain



#endif /* DOMAIN_MODEL_SMART_PRODUCT_HPP_ */

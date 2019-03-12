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
	time_t expiry_date_;
	ProductUnit unit_;
	void validate();

public:
	SmartProduct( const std::string& name, double price, time_t expiry_date, double quantity, ProductUnit unit );
	const std::string& get_name() const;
	double get_price() const;
	double get_current_quantity() const;
	double get_initial_quantity() const;
	time_t get_expiry_date() const;
	void print_state() const;
	bool operator==( const SmartProduct& right ) const;
};

} //end namespace model
} // end namespace domain



#endif /* DOMAIN_MODEL_SMART_PRODUCT_HPP_ */

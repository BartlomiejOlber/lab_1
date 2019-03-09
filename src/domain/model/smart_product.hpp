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

namespace domain {
namespace model {

enum ProductUnit {
	PRODUCT_UNIT_KILO = 0,
	PRODUCT_UNIT_LITER = 1,
	PRODUCT_UNIT_ITEMS = 2
};


class SmartProduct {
private:
	std::string name_;
	double price_;
	double initial_quantity_;
	double current_quantity_;
	time_t expiry_date_;
	ProductUnit unit_;



public:
	SmartProduct( const std::string& name, double price, time_t expiry_date, double quantity, ProductUnit unit );
	const std::string& get_name() const;
	double get_price() const;
	double get_current_quantity() const;
	double get_initial_quantity() const;
	time_t get_expiry_date() const;
	void print_state() const;
	virtual void validate(){};
	virtual ~SmartProduct(){};
};



} //end namespace model
} // end namespace domain



#endif /* DOMAIN_MODEL_SMART_PRODUCT_HPP_ */

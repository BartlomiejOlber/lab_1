/*
 * milk.hpp
 *
 *  Created on: Mar 9, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_MILK_HPP_
#define DOMAIN_MODEL_MILK_HPP_

#include "smart_product.hpp"

namespace domain {
namespace model {

class Milk : public SmartProduct {



public:
	Milk( const std::string& name, double price, time_t expiry_date, double quantity = 1.0 ) :
		SmartProduct( name, price, expiry_date, quantity, ProductUnit::PRODUCT_UNIT_LITER ){};
	virtual void validate();
	virtual ~Milk(){};
};

} //end namespace model
} // end namespace domain

#endif /* DOMAIN_MODEL_MILK_HPP_ */

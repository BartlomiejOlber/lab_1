/*
 * milk.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: bartlomiej
 */

#include "milk.hpp"
#include "smart_product_exception.hpp"

namespace domain {
namespace model {

void Milk::validate()
{
	if( get_name().length() < 4)
		throw SmartProductNameException();
	if( get_price() < 0.0 )
		throw SmartProductPriceException();
	if( get_expiry_date() < 0 )
		throw SmartProductExpiryDateException();
	if( get_initial_quantity() < 0 )
		throw SmartProductQuantityException();
}

} //end namespace model
} // end namespace domain

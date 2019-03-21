/*
 * smart_product_exception.hpp
 *
 *  Created on: Mar 9, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_SMART_PRODUCT_EXCEPTION_HPP_
#define DOMAIN_MODEL_SMART_PRODUCT_EXCEPTION_HPP_

#include <stdexcept>

namespace domain {
namespace model {

class SmartProductException : public std::invalid_argument {
public:
	SmartProductException( const char* what_arg ) : invalid_argument( what_arg ){};

};

class SmartProductNameException : public SmartProductException {
public:
	SmartProductNameException() : SmartProductException( "name" ){};

};

class SmartProductPriceException : public SmartProductException {
public:
	SmartProductPriceException() : SmartProductException( "price" ){};

};

class SmartProductExpiryDateException : public SmartProductException {
public:
	SmartProductExpiryDateException() : SmartProductException( "expiry date" ){};

};

class SmartProductQuantityException : public SmartProductException {
public:
	SmartProductQuantityException() : SmartProductException( "quantity" ){};

};

} //end namespace model
} // end namespace domain

#endif /* DOMAIN_MODEL_SMART_PRODUCT_EXCEPTION_HPP_ */

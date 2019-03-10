/*
 * smart_product_container_exception.hpp
 *
 *  Created on: Mar 10, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_SMART_PRODUCT_CONTAINER_EXCEPTION_HPP_
#define DOMAIN_MODEL_SMART_PRODUCT_CONTAINER_EXCEPTION_HPP_

#include <stdexcept>

namespace domain {
namespace model {

class SmartProductContainerException : public std::domain_error {
public:
	SmartProductContainerException( const char* what_arg ) : domain_error( what_arg ){};

};

}//end namespace model
}//end namespace domain

#endif /* DOMAIN_MODEL_SMART_PRODUCT_CONTAINER_EXCEPTION_HPP_ */

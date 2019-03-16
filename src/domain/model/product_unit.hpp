/*
 * product_unit.hpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_PRODUCT_UNIT_HPP_
#define DOMAIN_MODEL_PRODUCT_UNIT_HPP_

#include <iostream>

namespace domain {
namespace model {

enum class ProductUnit {
	UNKNOWN = 0,
	KILO = 1,
	LITER = 2,
	ITEMS = 3,
	MAXIMUM = 4
};

class ProductUnitConverter {

public:
	static std::string to_str( ProductUnit unit );
	static ProductUnit from_int( int unit );
	static int from_string( const std::string& string );

};

}
}

#endif /* DOMAIN_MODEL_PRODUCT_UNIT_HPP_ */

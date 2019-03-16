/*
 * product_unit.cpp
 *
 *  Created on: Mar 16, 2019
 *      Author: bartlomiej
 */

#include "product_unit.hpp"

namespace domain {
namespace model {



std::string ProductUnitConverter::to_str( ProductUnit unit)
{
	std::string unit_str = "";
	switch( unit )
		{
			case ProductUnit::KILO:
				unit_str = "kg";
				break;
			case ProductUnit::LITER:
				unit_str =  "l";
				break;
			case ProductUnit::ITEMS:
				unit_str = "items";
				break;
		}
	return unit_str;
}

ProductUnit ProductUnitConverter::from_int( int unit )
{
	if( unit > (int)ProductUnit::UNKNOWN && unit < (int)ProductUnit::MAXIMUM )
		return (ProductUnit)unit;
	return ProductUnit::UNKNOWN;
}

int ProductUnitConverter::from_string( const std::string& string )
{
	int unit = 0;
	if( string == "kg" )
		unit = 1;
	if( string == "l" )
		unit = 2;
	if( string == "items" )
		unit = 3;
	return unit;
}

}
}

/*
 * preference_type.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#include "preference_type.hpp"

namespace domain {
namespace model {

PreferenceType PreferenceTypeConverter::from_string( const std::string& string )
{
	PreferenceType type = PreferenceType::UNKNOWN;
	if( string == "expiry_date" )
		type = PreferenceType::EXPIRY_DATE;
	if( string == "minimal_quantity" )
		type = PreferenceType::MINIMAL_QUANTITY;
	return type;

}

std::string PreferenceTypeConverter::to_string( PreferenceType type )
{
	std::string type_str = "";
	switch( type )
	{
		case PreferenceType::EXPIRY_DATE:
			type_str = "expiry_date";
			break;
		case PreferenceType::MINIMAL_QUANTITY:
			type_str = "minimal_quantity";
			break;

	}
	return type_str;
}

}//end namespace
}


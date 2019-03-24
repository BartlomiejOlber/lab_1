/*
 * preference_type.hpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_PREFERENCE_TYPE_HPP_
#define DOMAIN_MODEL_PREFERENCE_TYPE_HPP_

#include <string>

namespace domain {
namespace model {

enum class PreferenceType {
	UNKNOWN = 0,
	MINIMAL_QUANTITY = 1,
	EXPIRY_DATE = 2
};

class PreferenceTypeConverter {

public:
	static PreferenceType from_string( const std::string& string );
	static std::string to_string( PreferenceType );
};

}//end namespace
}

#endif /* DOMAIN_MODEL_PREFERENCE_TYPE_HPP_ */

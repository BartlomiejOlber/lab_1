/*
 * preference.hpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_PREFERENCE_HPP_
#define DOMAIN_MODEL_PREFERENCE_HPP_

#include "preference_type.hpp"
#include <string>

namespace domain {
namespace model {

class Preference {

private:
	std::string item_name_;
	PreferenceType type_;
	double value_;
public:
	Preference( const std::string& item_name, const std::string& type, double value = 0.0 ) : item_name_( item_name ),
		type_( PreferenceTypeConverter::from_string( type ) ), value_(value) {};
	const std::string& getItemName() const {
		return item_name_;
	}

	PreferenceType getType() const {
		return type_;
	}

	double getValue() const {
		return value_;
	}
	bool operator==( const Preference& right ) {
		return (item_name_ == right.item_name_ && type_ == right.type_);
	}

};

}
}

#endif /* DOMAIN_MODEL_PREFERENCE_HPP_ */

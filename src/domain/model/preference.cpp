/*
 * preference.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: bartlomiej
 */

#include "preference.hpp"
#include <ctime>

namespace domain {
namespace model {

double Preference::how_much_needed( const SmartProduct& product ) const
{
	if( value_ > product.get_current_quantity() )
		return value_ - product.get_current_quantity();
	return 0;
}

bool Preference::is_expired( const SmartProduct& product) const
{
	time_t t = time(0);
	struct tm* now = localtime( & t );
	now->tm_mday += value_;
	if( difftime( mktime( (std::tm*)&product.get_expiry_date() ) , mktime( now )  ) < 0){
		return true;
	}
	return false;

}


}
}

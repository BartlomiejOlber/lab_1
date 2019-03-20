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
	time_t rawtime;
	struct tm* ptm;
	time ( &rawtime );
	ptm = gmtime ( &rawtime );
	ptm->tm_mday += value_;
	if( difftime( mktime( (struct tm*)&product.get_expiry_date() ), mktime( (struct tm*)&ptm )) < 0)
		return true;
	return false;

}


}
}

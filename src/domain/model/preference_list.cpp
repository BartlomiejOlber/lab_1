/*
 * preference_list.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#include "preference_list.hpp"

namespace domain {
namespace model {

void PreferenceList::add_preference( const std::string& name, const std::string& type, double value )
{
	Preference new_preference( name, type, value );
	list_.push_back( new_preference );
}

void PreferenceList::remove_preference( const std::string& name, const std::string& type )
{
	ListT::iterator pos;
	for( pos = list_.begin(); pos != list_.end(); ++pos ) {
		if( pos->getItemName() == name && PreferenceTypeConverter::to_string( pos->getType() ) == type ){
			list_.erase( pos );
			pos--;
		}
	}
}

bool PreferenceList::find_preference( const std::string& name, const std::string& type, Preference& preference ) const
{
	bool result = false;
	PreferenceList::ListT::const_iterator pos( list_.begin() );
	while( pos!=list_.end() )
	{
		if( pos->getItemName() == name && PreferenceTypeConverter::to_string( pos->getType() ) == type ){
			preference = *pos;
			result = true;
		}
		++pos;
	}
	return result;
}

const PreferenceList::ListT& PreferenceList::get_preferences() const
{
	return list_;
}

}//end namespace
}

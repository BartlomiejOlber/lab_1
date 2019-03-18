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
	const Preference preference( name, type );
	for( pos = list_.begin(); pos != list_.end(); ++pos ) {
		if( *pos == preference ){
			list_.erase( pos );
			pos--;
		}
	}
}

const PreferenceList::ListT& PreferenceList::get_preferences() const
{
	return list_;
}

}//end namespace
}

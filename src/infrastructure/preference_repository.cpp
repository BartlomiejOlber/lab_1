/*
 * preferences_repository.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */
#include <fstream>
#include <sstream>
#include "preference_repository.hpp"



namespace infrastructure {

using namespace domain::model;

void PreferenceRepository::load( PreferenceList& preference_list )
{
	std::ifstream ifs;
	ifs.open( get_path() , std::ifstream::in);
	std::string line;
	std::string name;
	std::string type;
	double value;
	while (std::getline( ifs, line )) {
		std::stringstream iss(line);
		std::getline(iss, name, ',');
		std::getline(iss, type, ',');
		std::string value_str;
		std::getline(iss, value_str, ',');
		value = std::stod( value_str );
		preference_list.add_preference( name, type, value );
	}
	ifs.close();
}

void PreferenceRepository::store( const PreferenceList& preference_list )
{
	std::ofstream ofs;
	ofs.open( get_path() , std::ofstream::out | std::ofstream::trunc);
	const PreferenceList::ListT& list = preference_list.get_preferences();
	PreferenceList::ListT::const_iterator pos;
	for(pos = list.begin(); pos!=list.end(); ++pos){
		ofs << pos->getItemName() << "," << PreferenceTypeConverter::to_string( pos->getType() )
			<< "," << pos->getValue() << std::endl;
	}
	ofs.close();
}

}

/*
 * test_preference_list.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/domain/model/preference_list.hpp"

namespace test {

using namespace domain::model;

SCENARIO( "Preference list usage" ) {

    GIVEN( "Two preferences are added to the list" ) {
    	PreferenceList preference_list;
    	Preference empty_preference( "", "");
    	std::string name1("milk");
    	std::string name2("butter");
    	std::string type1("expiry_date");
    	std::string type2("minimal_quantity");
    	double value1(1.5);
    	double value2(3.2);
    	preference_list.add_preference( name1, type1, value1 );
		preference_list.add_preference( name2, type2, value2 );
		THEN( "List size = 2" ) {
			REQUIRE( preference_list.get_preferences().size() == 2);
		}
        WHEN( "Finding preference of name1 and type1" ) {
        	preference_list.find_preference( name1, type1, empty_preference );
			THEN( "found preference's name = name1; type = type1; value = value1" ) {
				REQUIRE( empty_preference.getItemName() == name1 );
				REQUIRE( PreferenceTypeConverter::to_string(empty_preference.getType()) == type1 );
				REQUIRE( empty_preference.getValue() == value1 );
			}
		}
        WHEN( "Removing preference of name1 and type1" ) {
        	preference_list.remove_preference( name1, type1 );
			THEN( "List size = 1" ) {
				REQUIRE( preference_list.get_preferences().size() == 1 );
			}
		}

    }
}

}// end namespace test



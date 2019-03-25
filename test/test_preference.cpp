/*
 * test_preference.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: bartlomiej
 */


#include "catch.hpp"
#include "../src/domain/model/preference.hpp"

namespace test {

using namespace domain::model;

SCENARIO( "Preference creation" ) {

    GIVEN( "Name, type, value" ) {
    	std::string name("milk");
    	std::string type("expiry_date");
    	double value(1.6);

        WHEN( "Preference is created" ) {

        	Preference preference( name, type, value );

            THEN( "Preference's attributes are correct" ) {
                REQUIRE( preference.getItemName() == name );
                REQUIRE( PreferenceTypeConverter::to_string( preference.getType()) == type );
                REQUIRE( preference.getValue() == value );
            }
        }
    }
}

}// end namespace test


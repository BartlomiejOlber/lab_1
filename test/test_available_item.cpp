
/*
 * unit_tests.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: bartlomiej
 */


#include "catch.hpp"
#include "../src/domain/model/available_item.hpp"

namespace test {

using namespace domain::model;

SCENARIO( "Available item creation" ) {

    GIVEN( "Name, price, quantity, unit" ) {
    	std::string name("milk");
    	double price = 1.0;
    	double quantity = 2.0;
    	int unit = 1;

        WHEN( "Item is created" ) {

        	AvailableItem item( name, price, quantity, unit );

            THEN( "Item attributes are correct" ) {
                REQUIRE( item.get_name() == name );
                REQUIRE( item.get_price() == price );
                REQUIRE( item.get_quantity() == quantity );
                REQUIRE( (int)item.get_unit() == unit );
            }
        }
        WHEN( "Quantity equals 2 and needed quantity = 1.5" ) {
        	double needed_quantity = 1.5;
			AvailableItem item( name, price, quantity, unit );
			THEN( "Needed items = 1" ) {
				REQUIRE( item.how_many_needed( needed_quantity ) == 1 );
			}
		}
    }
}

}// end namespace test


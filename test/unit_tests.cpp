
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

    GIVEN( "Given name, price, quantity, unit" ) {
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
    }
}

}// end namespace test




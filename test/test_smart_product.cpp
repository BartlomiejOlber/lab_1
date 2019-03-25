/*
 * test_smart_product.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/domain/model/smart_product.hpp"

namespace test {

using namespace domain::model;

SCENARIO( "Smart product creation" ) {

    GIVEN( "Name, type, quantity, unit, expiry_date" ) {
    	std::string name("milk");
		double price = 1.0;
		double quantity = 2.0;
		int unit = 1;
		time_t t = time(0);
		struct tm* expiry_date = localtime( & t );
		WHEN( "Product is created" ) {

			SmartProduct product( name, price, *expiry_date, quantity, unit );
            THEN( "Product's attributes are correct" ) {
                REQUIRE( product.get_current_quantity() == quantity );
                REQUIRE( (int)product.get_unit() == unit );
                REQUIRE( difftime( mktime( (std::tm*)&product.get_expiry_date() ) , mktime(expiry_date)  ) == 0 );
                REQUIRE( product.get_price() == price );
                REQUIRE( product.get_name() == name );
            }
        }
		WHEN( "Two identical products are created" ) {

			SmartProduct product1( name, price, *expiry_date, quantity, unit );
			SmartProduct product2( name, price, *expiry_date, quantity, unit );
			THEN( "Products are equal" ) {
				REQUIRE( product1 == product2 );
			}
		}
    }
}

}

/*
 * test_smart_product_container.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/domain/model/refridgerator.hpp"

namespace test {

using namespace domain::model;

SCENARIO( "Smart product container usage - refridgerator example" ) {

    GIVEN( "Two products are added to the refridgerator" ) {
    	Refridgerator container;
    	SmartProductContainer::ContentT content;
    	std::string name1("milk");
		double price1 = 1.0;
		double quantity1 = 2.0;
		int unit1 = 1;
		std::string name2("butter");
		double price2 = 1.6;
		double quantity2 = 2.5;
		int unit2 = 2;
		time_t t = time(0);
		struct tm* expiry_date = localtime( & t );
		SmartProduct product1( name1, price1, *expiry_date, quantity1, unit1 );
		SmartProduct product2( name2, price2, *expiry_date, quantity2, unit2 );

		container.add_product( product1 );
		container.add_product( product2 );
		THEN( "Container size = 2" ) {
			REQUIRE( container.get_products().size() == 2);
		}
        WHEN( "Finding a product of name1 in the container" ) {
        	container.find_product( name1, content );
        	THEN( "Number of found products = 1" ) {
				REQUIRE( content.size() == 1 );
			}
		}
        WHEN( "Removing a product of name1" ) {
        	container.find_product( name1, content);
        	container.remove_product( content);
        	THEN( "Container size = 1" ) {
				REQUIRE( container.get_products().size() == 1 );
			}
		}

    }
}

}// end namespace test


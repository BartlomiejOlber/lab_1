/*
 * test_stock.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/domain/model/stock.hpp"

namespace test {

using namespace domain::model;

SCENARIO( "Stock usage" ) {

    GIVEN( "Two items are added to the stock" ) {
    	Stock stock;
    	std::string name1("milk");
		double price1 = 1.0;
		double quantity1 = 2.0;
		int unit1 = 1;
		std::string name2("butter");
		double price2 = 1.6;
		double quantity2 = 2.5;
		int unit2 = 2;
		AvailableItem item1( name1, price1, quantity1, unit1 );
		AvailableItem item2( name2, price2, quantity2, unit2 );
		stock.add_item( item1 );
		stock.add_item( item2 );
		THEN( "Stock size = 2" ) {
			REQUIRE( stock.get_items().size() == 2);
		}
        WHEN( "Finding an item of name1" ) {
        	THEN( "Result is positive" ) {
				REQUIRE( stock.find_item( name1, item1 )  );
			}
		}

    }
}

}



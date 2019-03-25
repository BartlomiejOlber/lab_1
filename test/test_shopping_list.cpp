/*
 * test_shopping_list.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: bartlomiej
 */

#include "catch.hpp"
#include "../src/domain/model/shopping_list.hpp"

namespace test {

using namespace domain::model;

SCENARIO( "Shopping list usage" ) {

    GIVEN( "Two items are added to the list [price2 > price1]" ) {
    	ShoppingList shopping_list;
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
		shopping_list.add_item(item1);
		shopping_list.add_item(item2);
		THEN( "List size = 2" ) {
			REQUIRE( shopping_list.get_items().size() == 2);
		}
        WHEN( "Finding the most expentive item in the list" ) {
        	THEN( "Found item's price = price2" ) {
				REQUIRE( shopping_list.find_pricey().get_price() == price2 );
			}
		}
        WHEN( "Removing an item of name1" ) {
        	shopping_list.remove_item( name1 );
        	THEN( "List size = 1" ) {
				REQUIRE( shopping_list.get_items().size() == 1 );
			}
		}

    }
}

}// end namespace test



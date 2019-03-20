/*
 * shopping_list_repository.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: bartlomiej
 */

#include "shopping_list_repository.hpp"

namespace infrastructure {

void ShoppingListRepository::store( const domain::model::ShoppingList& shopping_list )
{
	std::ofstream ofs;
	ofs.open( get_path() , std::ofstream::out | std::ofstream::trunc);
	const domain::model::ShoppingList::ItemListT& list = shopping_list.get_items();
	domain::model::ShoppingList::ItemListT::const_iterator pos;
	for(pos = list.begin(); pos!=list.end(); ++pos){
		ofs << "Product: " <<pos->get_name() << "  price: " << pos->get_price() << "$  quantity: "
		<< pos->get_quantity()<< ::domain::model::ProductUnitConverter::to_str(pos->get_unit())<< ""<< std::endl;
	}
	ofs.close();
}

}//end namespcae



/*
 * item_list.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */
#include "shopping_list.hpp"

namespace domain {
namespace model {

void ShoppingList::add_item( const AvailableItem& item )
{
	list_.push_back( item );
}

void ShoppingList::remove_item( const std::string& name )
{

}

const AvailableItem& ShoppingList::find_pricey()
{

}

const ShoppingList::ItemListT& ShoppingList::get_items()
{
	return list_;
}

void ShoppingList::generate( const DefinedSmartProductContainersT& defined_containers,
			const PreferenceList& preference_list, const Stock& stock)
{
		/** foreach container
			foreach	product
			find the product in preference list by type; if not found take default
			compare product state with preference
			if needed check if available in stock and add
		**/
}


}//end namespace model
}//end namespace domain

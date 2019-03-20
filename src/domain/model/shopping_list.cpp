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
	ShoppingList::ItemListT::const_iterator pos = list_.begin();
	while( pos!=list_.end() )
	{
		if( pos->get_name() == name ){
			list_.erase( pos );
		}
		++pos;
	}
}

const AvailableItem* ShoppingList::find_pricey()
{
	ShoppingList::ItemListT::const_iterator pos = list_.begin();
	AvailableItem* result = 0;
	*result = *pos;
	while( pos!=list_.end() )
	{
		if( pos->get_price() > result->get_price() ){
			*result = *pos;
		}
		++pos;
	}
	return result;
}

const ShoppingList::ItemListT& ShoppingList::get_items() const
{
	return list_;
}


void ShoppingList::generate( const DefinedSmartProductContainersT& defined_containers,
			const PreferenceList& preference_list, const Stock& stock)
{
	DefinedSmartProductContainersT::const_iterator pos_containers;
	SmartProductContainer::ContentT::const_iterator pos_product;
	SmartProductContainer::ContentT products;
	const std::string expiry_date_str = "expiry_date";
	const std::string minimal_quantity_str = "minimal_quantity";
	const std::string default_preference_str = "default";
	const Preference* expiry_date_preference;
	const Preference* minimal_quantity_preference;
	const AvailableItem* item_to_add = 0;
	double how_much_to_add = 0.0;
	int how_many_to_add = 0;
	for( pos_containers = defined_containers.begin(); pos_containers != defined_containers.end(); ++pos_containers ){
		//foreach container
		products = pos_containers->get_products(); //get container
		for( pos_product = products.begin(); pos_product != products.end(); ++pos_product ){
			//foreach product in the container
			item_to_add = stock.find_item( pos_product->get_name() ); //find the product in our shop inventory
			if( !item_to_add )
				continue;  	// skip the rest if not found in the inventory

			expiry_date_preference = preference_list.find_preference( pos_product->get_name(), expiry_date_str );
			std::cerr <<"elo2";
			//search for expiry date preference in preference list for current product
			if( !expiry_date_preference ) // if not found get the default expiry date preference
				expiry_date_preference = preference_list.find_preference( default_preference_str, expiry_date_str );
			std::cerr <<"elo3";
			minimal_quantity_preference = preference_list.find_preference( pos_product->get_name(), minimal_quantity_str );
			std::cerr <<"elo4";
			if( !minimal_quantity_preference ) // the same for minimal quantity preference
				minimal_quantity_preference = preference_list.find_preference( default_preference_str, minimal_quantity_str);
			std::cerr <<"elo5";
			how_much_to_add = minimal_quantity_preference->how_much_needed( *pos_product ); // how much do we need to add depending on quantity preferences
			how_many_to_add = item_to_add->how_many_needed( how_much_to_add ); //  how many items do we need to add
			std::cerr <<"elo6";
			for( int i = 0; i<how_many_to_add ; ++i ){
				std::cerr <<"elo7\n"<<how_many_to_add<<item_to_add->get_name();
				add_item( *item_to_add );  // adding items
			}
			std::cerr <<"elo8";
			if( expiry_date_preference->is_expired( *pos_product ) ){ // if product is expired
					how_many_to_add = item_to_add->how_many_needed( pos_product->get_current_quantity() ); // how many do we still need
					for( int i = 0; i<how_many_to_add ; ++i ){
						add_item( *item_to_add );  // adding items
					}//end for
				}//end expiry if
			std::cerr <<"elo2";  //reset them i guess
		}//end one product loop

	}//end one container loop


	/** foreach container
		foreach	product
		find the product in preference list by type; if not found take default
		compare product state with preference
		if needed check if available in stock and add
	**/
}


}//end namespace model
}//end namespace domain

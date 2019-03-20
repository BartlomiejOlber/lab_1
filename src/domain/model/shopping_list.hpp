/*
 * item_list.hpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_SHOPPING_LIST_HPP_
#define DOMAIN_MODEL_SHOPPING_LIST_HPP_

#include <vector>
#include "available_item.hpp"
#include "smart_product_container.hpp"
#include "preference_list.hpp"
#include "stock.hpp"


namespace domain {
namespace model {

class ShoppingList {

public:
	typedef std::vector<AvailableItem> ItemListT;

private:
	ItemListT list_;

public:
	void add_item( const AvailableItem& item );
	void remove_item( const std::string& name );
	const AvailableItem* find_pricey();
	const ItemListT& get_items() const;
	void generate( const DefinedSmartProductContainersT& defined_containers,
			const PreferenceList& preference_list,
			const Stock& stock );


};

}//end namespace model
}//end namespace domain

#endif /* DOMAIN_MODEL_SHOPPING_LIST_HPP_ */

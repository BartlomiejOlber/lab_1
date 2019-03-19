/*
 * stock.hpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_STOCK_HPP_
#define DOMAIN_MODEL_STOCK_HPP_

#include <vector>
#include <fstream>
#include "available_item.hpp"

namespace domain {
namespace model {

class Stock {

public:
	typedef std::vector<AvailableItem> AvailableItemsT;

private:
	AvailableItemsT stock_;

public:
	void add_item( const AvailableItem& item );
	void add_item( const std::string& name, double price, double quantity, int unit );
	const AvailableItem* find_item( const std::string& name ) const;
	const AvailableItemsT& get_items() const;
};


}//end namespace model
}//end namespace domain

#endif /* DOMAIN_MODEL_STOCK_HPP_ */

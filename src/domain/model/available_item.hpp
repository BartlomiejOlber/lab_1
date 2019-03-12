/*
 * available_item.hpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_AVAILABLE_ITEM_HPP_
#define DOMAIN_MODEL_AVAILABLE_ITEM_HPP_

#include "product_unit.hpp"
#include <string>

namespace domain {
namespace model {

class AvailableItem {

private:
	std::string name_;
	double price_;
	double quantity_;
	ProductUnit unit_;

public:
	AvailableItem( const std::string& name, double price, double quantity, int unit ) :
		name_(name), price_(price), quantity_(quantity), unit_(ProductUnit::UNKNOWN) {
		if( unit > (int)ProductUnit::UNKNOWN && unit < (int)ProductUnit::MAXIMUM )
			unit_ = (ProductUnit) unit;
	};
	void print() const;
	const std::string& get_name() const;
	double get_price() const;
	double get_quantity() const;
	std::string get_unit() const;

};


}//end namespace model
}//end namespace domain


#endif /* DOMAIN_MODEL_AVAILABLE_ITEM_HPP_ */

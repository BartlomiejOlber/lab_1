/*
 * available_item.hpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_AVAILABLE_ITEM_HPP_
#define DOMAIN_MODEL_AVAILABLE_ITEM_HPP_

#include "smart_product.hpp"

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
		name_(name), price_(price), quantity_(quantity), unit_(PRODUCT_UNIT_KILO) {
		unit_ = (ProductUnit) unit;
	};
	void set_name( const std::string& name );
	void set_price( double price );
	void set_quantity( double quantity );
	void set_unit( ProductUnit unit );

};


}//end namespace model
}//end namespace domain


#endif /* DOMAIN_MODEL_AVAILABLE_ITEM_HPP_ */

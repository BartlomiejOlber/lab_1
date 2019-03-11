/*
 * stock.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#include "stock.hpp"

namespace domain {
namespace model {

void Stock::add_item( const AvailableItem& item )
{
	stock_.push_back( item );
}

void Stock::print() const
{

}

}//end namespace model
}//end namespace domain

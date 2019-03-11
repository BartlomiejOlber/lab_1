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

private:
	std::vector<AvailableItem> stock_;

public:
	void add_item( const AvailableItem& item );
	void print() const;
};


}//end namespace model
}//end namespace domain

#endif /* DOMAIN_MODEL_STOCK_HPP_ */

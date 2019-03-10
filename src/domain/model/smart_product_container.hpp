/*
 * smart_product_container.hpp
 *
 *  Created on: Mar 10, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_SMART_PRODUCT_CONTAINER_HPP_
#define DOMAIN_MODEL_SMART_PRODUCT_CONTAINER_HPP_

#include <vector>
#include "smart_product.hpp"

namespace domain {
namespace model {

class SmartProductContainer {

private:
	std::vector<SmartProduct> container_;
	unsigned int max_volume_;

protected:
	SmartProductContainer( int max_volume ) : max_volume_(max_volume){};

public:
	void add_product( const SmartProduct& product );
	void remove_product( const std::vector<SmartProduct>& products );
	std::vector<SmartProduct> find_product( const SmartProduct& product ) const;
	std::vector<SmartProduct> find_product( const std::string& name ) const;
	const std::vector<SmartProduct>& get_product_list() const;
	int get_max_volume() const {return max_volume_;};
	virtual ~SmartProductContainer(){};
};

}//end namespace model
}//end namespace domain


#endif /* DOMAIN_MODEL_SMART_PRODUCT_CONTAINER_HPP_ */

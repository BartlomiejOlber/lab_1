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

public:
	typedef std::vector<SmartProduct> ContentT;

private:
	ContentT container_;
	unsigned int max_volume_;

protected:
	SmartProductContainer( int max_volume ) : max_volume_(max_volume){};

public:
	void add_product( const SmartProduct& product );
	void add_product( const std::string& name, double price, const std::tm& expiry_date, double quantity, int unit );
	void remove_product( const ContentT& products );
	//ContentT find_product( const SmartProduct& product ) const;
	void find_product( const std::string& name, ContentT& result ) const;
	const ContentT& get_products() const;
	int get_max_volume() const {return max_volume_;};
	virtual ~SmartProductContainer(){};
};

}//end namespace model
}//end namespace domain


#endif /* DOMAIN_MODEL_SMART_PRODUCT_CONTAINER_HPP_ */

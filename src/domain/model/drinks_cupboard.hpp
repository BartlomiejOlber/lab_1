/*
 * drinks_cupboard.hpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_DRINKS_CUPBOARD_HPP_
#define DOMAIN_MODEL_DRINKS_CUPBOARD_HPP_

#include "smart_product_container.hpp"


namespace domain {
namespace model {

class DrinksCupboard : public SmartProductContainer {

public:
	DrinksCupboard( int max_volume = 16 ) : SmartProductContainer( max_volume ){}
};

}//end namespace model
}//end namespace domain



#endif /* DOMAIN_MODEL_DRINKS_CUPBOARD_HPP_ */

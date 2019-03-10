/*
 * refridgerator.hpp
 *
 *  Created on: Mar 10, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_REFRIDGERATOR_HPP_
#define DOMAIN_MODEL_REFRIDGERATOR_HPP_

#include "smart_product_container.hpp"


namespace domain {
namespace model {

class Refridgerator : public SmartProductContainer {

public:
	Refrigerator( int max_volume = 32 ) : SmartProductContainer( max_volume ){};
};

}//end namespace model
}//end namespace domain

#endif /* DOMAIN_MODEL_REFRIDGERATOR_HPP_ */

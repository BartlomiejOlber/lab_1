/*
 * candy_drawer.hpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_CANDY_DRAWER_HPP_
#define DOMAIN_MODEL_CANDY_DRAWER_HPP_


#include "smart_product_container.hpp"


namespace domain {
namespace model {

class CandyDrawer : public SmartProductContainer {

public:
	CandyDrawer( int max_volume = 8 ) : SmartProductContainer( max_volume ){}
};

}//end namespace model
}//end namespace domain


#endif /* DOMAIN_MODEL_CANDY_DRAWER_HPP_ */

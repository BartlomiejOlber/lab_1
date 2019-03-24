/*
 * smart_product_container_factory.cpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#include "smart_product_container_factory.hpp"
#include "../domain/model/refridgerator.hpp"
#include "../domain/model/candy_drawer.hpp"
#include "../domain/model/drinks_cupboard.hpp"

namespace application {

std::unique_ptr<domain::model::SmartProductContainer> SmartProductContainerFactory::create( ContainerTypes type )
{
	domain::model::SmartProductContainer* container = 0;
	switch(type)
	{
		case ContainerTypes::CANDY_DRAWER :
			container = new domain::model::CandyDrawer();
			break;
		case ContainerTypes::DRINKS_CUPBOARD :
			container = new domain::model::DrinksCupboard();
			break;
		case ContainerTypes::REFRIDGERATOR :
			container = new domain::model::Refridgerator();
			break;

	}
	return std::unique_ptr<domain::model::SmartProductContainer>(container);
}

}




/*
 * container_service_factory.cpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#include "container_service_factory.hpp"
#include "drinks_service.hpp"
#include "candys_service.hpp"
#include "refridgerator_service.hpp"

namespace application {

std::unique_ptr<ContainerService> ContainerServiceFactory::create( ContainerTypes type )
{
	ContainerService* container_service = 0;
	switch(type)
	{
		case ContainerTypes::CANDY_DRAWER :
			container_service = new CandysService();
			break;
		case ContainerTypes::DRINKS_CUPBOARD :
			container_service = new DrinksService();
			break;
		case ContainerTypes::REFRIDGERATOR :
			container_service = new RefridgeratorService();
			break;
	}
	return std::unique_ptr<ContainerService>(container_service) ;
}

}



/*
 * containers_service.cpp
 *
 *  Created on: Mar 16, 2019
 *      Author: bartlomiej
 */

#include "../infrastructure/smart_product_containter_repository.hpp"
#include "container_service.hpp"

namespace application {

using namespace infrastructure;

void ContainerService::init_container( domain::model::SmartProductContainer& container )
{
	SmartProductContainerRepository repository( get_container_config_file() );
	repository.load( container );

}

void ContainerService::save_container( domain::model::SmartProductContainer& container )
{
	SmartProductContainerRepository repository( get_container_config_file() );
	repository.store( container );
}

}// end namespace


/*
 * container_service_factory.hpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_CONTAINER_SERVICE_FACTORY_HPP_
#define APPLICATION_CONTAINER_SERVICE_FACTORY_HPP_

#include "container_service.hpp"
#include "container_types.hpp"
#include <memory>

namespace application {

class ContainerServiceFactory {

public:
	static std::unique_ptr<ContainerService> create( ContainerTypes type );

};

}

#endif /* APPLICATION_CONTAINER_SERVICE_FACTORY_HPP_ */

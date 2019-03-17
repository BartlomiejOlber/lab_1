/*
 * smart_containers_factory.hpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_SMART_PRODUCT_CONTAINER_FACTORY_HPP_
#define APPLICATION_SMART_PRODUCT_CONTAINER_FACTORY_HPP_

#include <memory>
#include  "../domain/model/smart_product_container.hpp"
#include "container_types.hpp"

namespace application {

class SmartProductContainerFactory {

public:
	static std::unique_ptr<domain::model::SmartProductContainer> create( ContainerTypes type );
};

}


#endif /* APPLICATION_SMART_PRODUCT_CONTAINER_FACTORY_HPP_ */

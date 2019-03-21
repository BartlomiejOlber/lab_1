/*
 * containers_service.hpp
 *
 *  Created on: Mar 16, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_CONTAINER_SERVICE_HPP_
#define APPLICATION_CONTAINER_SERVICE_HPP_

#include "../domain/model/smart_product_container.hpp"

namespace application {


class ContainerService {

protected:
	virtual const char* get_container_config_file() = 0;

public:
	void init_container( domain::model::SmartProductContainer& container);
	void save_container( domain::model::SmartProductContainer& container );
	virtual ~ContainerService(){};
};

}// end namespace


#endif /* APPLICATION_CONTAINER_SERVICE_HPP_ */

/*
 * refridgerator_service.hpp
 *
 *  Created on: Mar 16, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_REFRIDGERATOR_SERVICE_HPP_
#define APPLICATION_REFRIDGERATOR_SERVICE_HPP_

#include "container_service.hpp"

namespace application {

class RefridgeratorService : public ContainerService {

protected:
	virtual const char* get_container_config_file();

public:
	virtual ~RefridgeratorService(){};
};

}// end namespace



#endif /* APPLICATION_REFRIDGERATOR_SERVICE_HPP_ */

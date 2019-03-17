/*
 * drinks_service.hpp
 *
 *  Created on: Mar 16, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_DRINKS_SERVICE_HPP_
#define APPLICATION_DRINKS_SERVICE_HPP_

#include "container_service.hpp"

namespace application {

class DrinksService : public ContainerService {

protected:
	virtual const char* get_container_config_file();

public:
	virtual ~DrinksService(){};
};

}// end namespace



#endif /* APPLICATION_DRINKS_SERVICE_HPP_ */

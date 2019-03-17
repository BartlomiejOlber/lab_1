/*
 * candys_service.hpp
 *
 *  Created on: Mar 16, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_CANDYS_SERVICE_HPP_
#define APPLICATION_CANDYS_SERVICE_HPP_

#include "container_service.hpp"

namespace application {

class CandysService : public ContainerService {

protected:
	virtual const char* get_container_config_file();

public:
	virtual ~CandysService(){};
};

}// end namespace




#endif /* APPLICATION_CANDYS_SERVICE_HPP_ */

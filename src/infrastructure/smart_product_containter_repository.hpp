/*
 * smart_product_containter_repository.hpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#ifndef INFRASTRUCTURE_SMART_PRODUCT_CONTAINTER_REPOSITORY_HPP_
#define INFRASTRUCTURE_SMART_PRODUCT_CONTAINTER_REPOSITORY_HPP_

#include "../domain/model/smart_product_container.hpp"

namespace infrastructure {

class SmartProductContainerRepository {

private:
	const char* file_path_;

public:
	SmartProductContainerRepository( const char* file_path ) : file_path_( file_path ) {};
	void load( domain::model::SmartProductContainer& container );

};

}



#endif /* INFRASTRUCTURE_SMART_PRODUCT_CONTAINTER_REPOSITORY_HPP_ */

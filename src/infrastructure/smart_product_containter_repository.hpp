/*
 * smart_product_containter_repository.hpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#ifndef INFRASTRUCTURE_SMART_PRODUCT_CONTAINTER_REPOSITORY_HPP_
#define INFRASTRUCTURE_SMART_PRODUCT_CONTAINTER_REPOSITORY_HPP_

#include "../domain/model/smart_product_container.hpp"
#include "base_repository.hpp"

namespace infrastructure {

class SmartProductContainerRepository : public BaseRepository {

public:
	SmartProductContainerRepository( const char* file_path ) : BaseRepository( file_path ) {};
	void load( domain::model::SmartProductContainer& container );
	void store( const domain::model::SmartProductContainer& container );

};

}



#endif /* INFRASTRUCTURE_SMART_PRODUCT_CONTAINTER_REPOSITORY_HPP_ */

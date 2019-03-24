/*
 * preferences_repository.hpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#ifndef INFRASTRUCTURE_PREFERENCE_REPOSITORY_HPP_
#define INFRASTRUCTURE_PREFERENCE_REPOSITORY_HPP_


#include "base_repository.hpp"
#include "../domain/model/preference_list.hpp"

namespace infrastructure {

class PreferenceRepository : public BaseRepository {

public:
	PreferenceRepository( const char* file_path ) : BaseRepository( file_path ) {};
	void load( domain::model::PreferenceList& preference_list );
	void store( const domain::model::PreferenceList& preference_list );

};

}


#endif /* INFRASTRUCTURE_PREFERENCE_REPOSITORY_HPP_ */

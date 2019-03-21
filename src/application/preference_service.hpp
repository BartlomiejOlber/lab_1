/*
 * preferences_service.hpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_PREFERENCE_SERVICE_HPP_
#define APPLICATION_PREFERENCE_SERVICE_HPP_

#include "../domain/model/preference_list.hpp"

namespace application {

class PreferenceService {

public:
	void init_preference_list( domain::model::PreferenceList& preference_list );
	void save_preference_list( domain::model::PreferenceList& preference_list );

};

}


#endif /* APPLICATION_PREFERENCE_SERVICE_HPP_ */

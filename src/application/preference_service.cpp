/*
 * preference_service.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */


#include "../infrastructure/preference_repository.hpp"
#include "preference_service.hpp"

namespace application {

using namespace infrastructure;

void PreferenceService::init_preference_list( domain::model::PreferenceList& preference_list )
{
	PreferenceRepository repository( "preferences.txt" );
	repository.load( preference_list );

}

void PreferenceService::save_preference_list( domain::model::PreferenceList& preference_list )
{
	PreferenceRepository repository( "preferences.txt" );
	repository.store( preference_list );
}

}// end namespace


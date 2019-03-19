/*
 * preferences_interface.hpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#ifndef UI_PREFERENCE_INTERFACE_HPP_
#define UI_PREFERENCE_INTERFACE_HPP_


#include "base_interface.hpp"


namespace UI{

class PreferenceInterface : public Interface{

public:
	void display_options();
	void loop();
};

}//end namespace


#endif /* UI_PREFERENCE_INTERFACE_HPP_ */

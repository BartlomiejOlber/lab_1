/*
 * shopping_list_interface.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#ifndef UI_SHOPPING_LIST_INTERFACE_HPP_
#define UI_SHOPPING_LIST_INTERFACE_HPP_

#include "base_interface.hpp"

namespace UI{

class ListInterface : public Interface{

public:
	void display();
	void display_edit();
	void display_preferences();
	void run_generation();
	void run_edit();
	void run_preferences();
	void save();
	void loop();
};

}//end namespace


#endif /* UI_SHOPPING_LIST_INTERFACE_HPP_ */

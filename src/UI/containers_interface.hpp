/*
 * containers_interface.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#ifndef UI_CONTAINERS_INTERFACE_HPP_
#define UI_CONTAINERS_INTERFACE_HPP_

#include "base_interface.hpp"


namespace UI{

class ContainersInterface : public Interface{

public:
	void display_inventory();
	void display_options();
	int get_choice();
	void run_refridgerator();
	void run_candys();
	void run_drinks();
	void loop();
};

}//end namespace



#endif /* UI_CONTAINERS_INTERFACE_HPP_ */

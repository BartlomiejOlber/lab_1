/*
 * main_options.hpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#ifndef UI_MAIN_OPTIONS_HPP_
#define UI_MAIN_OPTIONS_HPP_

#include "base_interface.hpp"

namespace UI{

class MainOptions : public Interface{

public:
	void display();
	void loop_controler();
	void run_stock();
	void run_containers();
	void run_shopping_list();
};

}//end UI



#endif /* UI_MAIN_OPTIONS_HPP_ */

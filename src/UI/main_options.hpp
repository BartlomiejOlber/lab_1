/*
 * main_options.hpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#ifndef UI_MAIN_OPTIONS_HPP_
#define UI_MAIN_OPTIONS_HPP_

namespace UI{

class MainOptions {

public:
	void display();
	void loop_controler();
	void show_stock();
	void display_house_inventory();
	int get_choice();
};

}//end UI



#endif /* UI_MAIN_OPTIONS_HPP_ */

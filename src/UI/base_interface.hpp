/*
 * base_interface.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */

#ifndef UI_BASE_INTERFACE_HPP_
#define UI_BASE_INTERFACE_HPP_

#include <string>

namespace UI {

class Interface {

public:
	int get_number();
	std::string get_name();
};

}//end namespace



#endif /* UI_BASE_INTERFACE_HPP_ */

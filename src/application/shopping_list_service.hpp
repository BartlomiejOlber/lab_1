/*
 * shopping_list_service.hpp
 *
 *  Created on: Mar 19, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_SHOPPING_LIST_SERVICE_HPP_
#define APPLICATION_SHOPPING_LIST_SERVICE_HPP_

#include "../domain/model/shopping_list.hpp"

namespace application {

class ShoppingListService {

public:
	void generate_list( domain::model::ShoppingList& shopping_list );
	void save_list( domain::model::ShoppingList& shopping_list );
};

}



#endif /* APPLICATION_SHOPPING_LIST_SERVICE_HPP_ */

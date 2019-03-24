/*
 * shopping_list_repository.hpp
 *
 *  Created on: Mar 20, 2019
 *      Author: bartlomiej
 */

#ifndef INFRASTRUCTURE_SHOPPING_LIST_REPOSITORY_HPP_
#define INFRASTRUCTURE_SHOPPING_LIST_REPOSITORY_HPP_


#include "../domain/model/shopping_list.hpp"
#include "base_repository.hpp"

namespace infrastructure {

class ShoppingListRepository :  public BaseRepository {

public:
	ShoppingListRepository( const char* file_path ) : BaseRepository( file_path ) {};
	void store( const domain::model::ShoppingList& shopping_list );

};

}


#endif /* INFRASTRUCTURE_SHOPPING_LIST_REPOSITORY_HPP_ */

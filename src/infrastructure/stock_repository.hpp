/*
 * stock_repository.hpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#ifndef INFRASTRUCTURE_STOCK_REPOSITORY_HPP_
#define INFRASTRUCTURE_STOCK_REPOSITORY_HPP_


#include "../domain/model/stock.hpp"
#include "base_repository.hpp"

namespace infrastructure {

class StockRepository :  public BaseRepository {

public:
	StockRepository( const char* file_path ) : BaseRepository( file_path ) {};
	void load( domain::model::Stock& stock );

};

}

#endif /* INFRASTRUCTURE_STOCK_REPOSITORY_HPP_ */

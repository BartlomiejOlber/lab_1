/*
 * stock_repository.hpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#ifndef INFRASTRUCTURE_STOCK_REPOSITORY_HPP_
#define INFRASTRUCTURE_STOCK_REPOSITORY_HPP_

#include <string>
#include "../domain/model/stock.hpp"

namespace infrastructure {

class StockRepository {

private:
	const char* file_path_;

public:
	StockRepository( const char* file_path ) : file_path_( file_path ) {};
	void load( domain::model::Stock& stock );

};

}

#endif /* INFRASTRUCTURE_STOCK_REPOSITORY_HPP_ */

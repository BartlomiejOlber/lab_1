/*
 * stock_service.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#include "stock_service.hpp"
#include "../domain/model/smart_product_exception.hpp"
#include "../domain/model/stock.hpp"
#include "../infrastructure/stock_repository.hpp"

namespace application {

void StockService::get_stock( domain::model::Stock& stock )
{
	infrastructure::StockRepository stock_repository( "products.txt" );
	stock_repository.load( stock );
}

}



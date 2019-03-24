/*
 * stock_service.hpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */

#ifndef APPLICATION_STOCK_SERVICE_HPP_
#define APPLICATION_STOCK_SERVICE_HPP_

#include "../domain/model/stock.hpp"

namespace application {

class StockService {

public:
	 void get_stock( domain::model::Stock& stock );

};

}



#endif /* APPLICATION_STOCK_SERVICE_HPP_ */

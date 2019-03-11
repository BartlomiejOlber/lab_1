//============================================================================
// Name        : lab_1.cpp
// Author      : d
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../domain/model/smart_product_exception.hpp"
#include "../domain/model/stock.hpp"
#include "../infrastructure/stock_repository.hpp"

using namespace std;


int main() {

	domain::model::Stock stock;
	infrastructure::StockRepository stack_repository( "products.txt" );
	stack_repository.load( stock );

	return 0;
}

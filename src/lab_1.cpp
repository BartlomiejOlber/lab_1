//============================================================================
// Name        : lab_1.cpp
// Author      : d
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "domain/model/smart_product_exception.hpp"
#include "domain/model/stock.hpp"
#include "infrastructure/stock_repository.hpp"
#include "UI/main_options.hpp"


using namespace std;


int main() {

/*	domain::model::Stock stock;
	infrastructure::StockRepository stock_repository( "products.txt" );
	stock_repository.load( stock );
	stock.print();
*/
	UI::MainOptions main_options;
	//main_options.display();
	main_options.loop_controler();

	return 0;
}

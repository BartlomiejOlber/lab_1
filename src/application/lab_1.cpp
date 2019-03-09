//============================================================================
// Name        : lab_1.cpp
// Author      : d
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../domain/model/milk.hpp"
#include "../domain/model/smart_product_exception.hpp"

using namespace std;


int main() {
	try {
		domain::model::Milk my_milk =  domain::model::Milk( "laciate", 3.2, 652 );
		my_milk.print_state();
		domain::model::Milk my_milk1 =  domain::model::Milk( "le", 3.2, 652 );
		my_milk1.validate();
		my_milk1.print_state();
	} catch( const domain::model::SmartProductException& ex) {
		std::cerr << "smart product exception: "<< ex.what() << std::endl;
	}

	return 0;
}

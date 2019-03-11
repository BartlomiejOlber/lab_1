/*
 * stock_repository.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: bartlomiej
 */

#include <sstream>
#include <iostream>
#include "stock_repository.hpp"

namespace infrastructure {

void StockRepository::load( domain::model::Stock& stock )
{
	std::ifstream ifs;
	ifs.open( file_path_, std::ifstream::in);
	std::string line;
	std::string name;
	double price;
	double quantity;
	int unit;

	while (std::getline( ifs, line )) {
		std::cout << line << std::endl;
		std::stringstream iss(line);
		std::getline(iss, name, ',');
		std::string price_string;
		std::getline(iss, price_string, ',');
		price = std::stod( price_string );
		std::string quantity_str;
		std::getline(iss, quantity_str, ',');
		quantity = std::stod( quantity_str );
		std::string unit_str;
		std::getline(iss, unit_str, ',');
		unit = std::stoi( unit_str );
		std::cout << name << ": " << price << ": " << quantity << ": " << unit << std::endl;
		domain::model::AvailableItem item( name, price, quantity, unit );
		stock.add_item(item);
	}

	ifs.close();
}

}


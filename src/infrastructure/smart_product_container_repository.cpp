/*
 * smart_product_container_repository.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: bartlomiej
 */
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "../domain/model/product_unit.hpp"
#include "smart_product_containter_repository.hpp"


namespace infrastructure {

using namespace domain::model;

void SmartProductContainerRepository::load( SmartProductContainer& container )
{
	std::ifstream ifs;
	ifs.open( get_path() , std::ifstream::in);
	std::tm date = {};
	std::string line;
	std::string name;
	double price;
	double quantity;
	int unit;
	while (std::getline( ifs, line )) {
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
		unit = ProductUnitConverter::from_string( unit_str );
		iss >> std::get_time(&date, "%Y-%m-%d");

		container.add_product( name, price, date, quantity, unit );
	}
	ifs.close();
}

void SmartProductContainerRepository::store( const SmartProductContainer& container )
{
	std::ofstream ofs;
	ofs.open( get_path() , std::ofstream::out | std::ofstream::trunc);
	const SmartProductContainer::ContentT& products = container.get_products();
	SmartProductContainer::ContentT::const_iterator pos;
	for(pos = products.begin(); pos!=products.end(); ++pos){
		ofs << pos->get_name() << "," << pos->get_price() << "," << pos->get_current_quantity()<<","
			<< ProductUnitConverter::to_str(pos->get_unit())<< ","<< pos->get_expiry_date_str() << std::endl;
	}
	ofs.close();
}

}



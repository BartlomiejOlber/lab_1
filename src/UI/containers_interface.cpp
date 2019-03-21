/*
 * containers_interface.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: bartlomiej
 */
#include <iomanip>
#include "containers_interface.hpp"
#include "../domain/model/smart_product_container.hpp"
#include "../application/smart_product_container_factory.hpp"
#include "../application/container_service_factory.hpp"
#include "../application/container_service.hpp"


namespace UI{

using namespace domain::model;
using namespace application;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

class ContainerUI : public Interface {

private:
	SmartProductContainer* container_;
	ContainerService* service_;
public:
	ContainerUI( SmartProductContainer* container, ContainerService* service ):
		container_(container), service_(service) {};
	void print_content();
	void process_container();
	void display_options();
};

void ContainerUI::print_content()
{
	std::system("clear");
	const SmartProductContainer::ContentT& products = container_->get_products();
	SmartProductContainer::ContentT::const_iterator pos;
	cout << "\n\n\t*Container contents*\n\n";
	for(pos = products.begin(); pos!=products.end(); ++pos){
		cout << "\t| Product | "<< setw( 20 ) << right <<pos->get_name() << " | "
				<< setw( 5 )<< right <<pos->get_price() << "$ | "<< setw(3) << right <<
				pos->get_current_quantity() << setw(5) << left
				<< ProductUnitConverter::to_str(pos->get_unit())<< " |" << endl;
	}
}

void ContainerUI::process_container()
{
	int choice = 0;
	SmartProductContainer::ContentT products;
	service_->init_container( *container_ );
	print_content();
	display_options();
	do{
		choice = get_number();
		if( choice == 1){
			std::cout << "\n\tName the product you want to consume: ";
			std::string consumed_product = get_name();
			container_->find_product( consumed_product, products );
			container_->remove_product( products );
		}
	}while( choice!=2 );
	service_->save_container( *container_ );
}

void ContainerUI::display_options()
{
	std::cout<< "\n\n[1]. Remove an item"<< std::endl;
	std::cout<< "[2]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}

void ContainersInterface::display_inventory()
{
	std::system("clear");
	std::cout<<"\n\n\t*House containers*\n\n"<<	std::endl;
	std::cout<< "[1]. Open refridgerator"<< std::endl;
	std::cout<< "[2]. Open candy drawer"<< std::endl;
	std::cout<< "[3]. Open drinks cupboard"<< std::endl;
	std::cout<< "[4]. Back"<<std::endl;
	std::cout<< "\n Selection: ";
}




void ContainersInterface::loop()
{
	int choice = 0;
	do{
		display_inventory();
		choice = get_number();
		switch(choice)
		{
			case 1:
				run_refridgerator( );
				break;
			case 2:
				run_candys();
				break;
			case 3:
				run_drinks();
				break;
		}

	}while(choice != 4);
	std::system("clear");
}

void ContainersInterface::run_refridgerator()
{
	std::unique_ptr<SmartProductContainer> container = SmartProductContainerFactory::create( ContainerTypes::REFRIDGERATOR );
	std::unique_ptr<ContainerService> service = ContainerServiceFactory::create( ContainerTypes::REFRIDGERATOR );
	ContainerUI container_ui( container.get(), service.get() );
	container_ui.process_container();
}

void ContainersInterface::run_candys()
{
	std::unique_ptr<SmartProductContainer> container = SmartProductContainerFactory::create( ContainerTypes::CANDY_DRAWER );
	std::unique_ptr<ContainerService> service = ContainerServiceFactory::create( ContainerTypes::CANDY_DRAWER );
	ContainerUI container_ui( container.get(), service.get() );
	container_ui.process_container();
}

void ContainersInterface::run_drinks()
{
	std::unique_ptr<SmartProductContainer> container = SmartProductContainerFactory::create( ContainerTypes::DRINKS_CUPBOARD );
	std::unique_ptr<ContainerService> service = ContainerServiceFactory::create( ContainerTypes::DRINKS_CUPBOARD );
	ContainerUI container_ui( container.get(), service.get() );
	container_ui.process_container();
}

}//end namespace

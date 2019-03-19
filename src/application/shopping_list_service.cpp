/*
 * shopping_list_service.cpp
 *
 *  Created on: Mar 19, 2019
 *      Author: bartlomiej
 */

#include "shopping_list_service.hpp"
#include "container_service_factory.hpp"
#include "../domain/model/smart_product_container.hpp"
#include "smart_product_container_factory.hpp"
#include "stock_service.hpp"
#include "preference_service.hpp"

namespace application {

using namespace domain::model;

void ShoppingListService::generate_list( domain::model::ShoppingList& shopping_list )
{
	std::unique_ptr<SmartProductContainer> refridgerator = SmartProductContainerFactory::create( ContainerTypes::REFRIDGERATOR );
	std::unique_ptr<ContainerService> refridgerator_service = ContainerServiceFactory::create( ContainerTypes::REFRIDGERATOR );
	std::unique_ptr<SmartProductContainer> candy_drawer = SmartProductContainerFactory::create( ContainerTypes::CANDY_DRAWER );
	std::unique_ptr<ContainerService> candy_drawer_service = ContainerServiceFactory::create( ContainerTypes::CANDY_DRAWER );
	std::unique_ptr<SmartProductContainer> drinks_cupboard = SmartProductContainerFactory::create( ContainerTypes::DRINKS_CUPBOARD );
	std::unique_ptr<ContainerService> drinks_cupboard_service = ContainerServiceFactory::create( ContainerTypes::DRINKS_CUPBOARD );
	refridgerator_service->init_container( *(refridgerator.get()) );
	candy_drawer_service->init_container( *(candy_drawer.get()) );
	drinks_cupboard_service->init_container( *(drinks_cupboard.get()) );
	DefinedSmartProductContainersT defined_containers;
	defined_containers.push_back( *(refridgerator.get()) );
	defined_containers.push_back( *(drinks_cupboard.get()) );
	defined_containers.push_back( *(candy_drawer.get()) );
	PreferenceList preference_list;
	PreferenceService preference_list_service;
	preference_list_service.init_preference_list( preference_list );
	Stock stock;
	StockService stock_service;
	stock_service.get_stock( stock );
	shopping_list.generate( defined_containers, preference_list, stock );
}

void ShoppingListService::store( domain::model::ShoppingList& shopping_list )
{

}

}



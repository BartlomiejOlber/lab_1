/*
 * smart_product_container.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: bartlomiej
 */

#include "smart_product_container.hpp"
#include "smart_product_container_exception.hpp"
#include <algorithm>

namespace domain {
namespace model {

class Comparator {

private:
	SmartProduct product_;
public:
	Comparator( const SmartProduct& product );
	bool operator()( const SmartProduct& product) const
	{
		return product_ == product;
	};
};

class ComparatorName {

private:
	SmartProduct product_;
public:
	ComparatorName( const std::string& name_ );
	bool operator()( const std::string& name ) const
	{
		return product_.get_name() == name;
	};
};

void SmartProductContainer::add_product( const SmartProduct& product )
{
	if( container_.size() < max_volume_ ){
		container_.push_back( product );
	}else
		throw SmartProductContainerException( "container overload" );
}

void SmartProductContainer::remove_product( const std::vector<SmartProduct>& products )
{
	std::vector<SmartProduct>::const_iterator pos;

	for( pos = products.begin(); pos != products.end(); ++pos ){
		std::remove_if( container_.begin(), container_.end(), Comparator( *pos ) );
	}
}

std::vector<SmartProduct> SmartProductContainer::find_product( const SmartProduct& product ) const
{
	std::vector<SmartProduct> result;
	std::copy_if(container_.begin(), container_.end(), result.begin(), Comparator( product ) );
	return result;
}

std::vector<SmartProduct> SmartProductContainer::find_product( const std::string& name ) const
{
	std::vector<SmartProduct> result;
	std::copy_if(container_.begin(), container_.end(), result.begin(), ComparatorName( name ) );
	return result;
}

const std::vector<SmartProduct>& SmartProductContainer::get_product_list() const
{
	return container_;
}



}//end namespace model
}//end namespace domain

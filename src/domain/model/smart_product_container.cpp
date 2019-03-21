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
	const SmartProduct& product_;
public:
	Comparator( const SmartProduct& product ) : product_(product){};
	bool operator()( const SmartProduct& product) const
	{
		return product_ == product;
	};
};

class ComparatorProducts {

private:
	const SmartProductContainer::ContentT& products_;
public:
	ComparatorProducts( const SmartProductContainer::ContentT& products ) : products_(products){};
	bool operator()( const SmartProduct& product ) const
	{
		SmartProductContainer::ContentT::const_iterator it = std::find_if (products_.begin(),
				products_.end(), Comparator( product ));
		return it != products_.end();
	};

};

class ComparatorName {

private:
	const std::string& name_;
public:
	ComparatorName( const std::string& name ) : name_(name) {std::cerr<<name_<<std::endl;};
	bool operator()( const SmartProduct& product ) const
	{

		return product.get_name() == name_;
	};
};

void SmartProductContainer::add_product( const SmartProduct& product )
{
	if( container_.size() < max_volume_ ){
		container_.push_back( product );
	}else
		throw SmartProductContainerException( "container overload" );
}

void SmartProductContainer::add_product( const std::string& name, double price, const std::tm& expiry_date, double quantity, int unit )
{
	if( container_.size() < max_volume_ ){
		SmartProduct product( name, price, expiry_date, quantity, unit );
		container_.push_back( product );
	}else
		throw SmartProductContainerException( "container overload" );
}

void SmartProductContainer::remove_product( const ContentT& products )
{
	ContentT::const_iterator pos;
	pos = std::remove_if ( container_.begin(), container_.end(), ComparatorProducts( products ));
	container_.erase( pos, container_.end() );
}

void SmartProductContainer::find_product( const std::string& name, ContentT& result ) const
{
	ContentT::const_iterator pos;
	for( pos = container_.begin(); pos != container_.end(); ++pos ){
		if( pos->get_name() == name )
			result.push_back( *pos );
	}
}

const SmartProductContainer::ContentT& SmartProductContainer::get_products() const
{
	return container_;
}



}//end namespace model
}//end namespace domain

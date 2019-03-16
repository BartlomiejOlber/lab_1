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
	ContentT::const_iterator pos_,pos;
	for( pos_ = container_.begin(); pos_!= container_.end(); ++pos_ ){
		for( pos = products.begin(); pos != products.end(); ++pos ){
			if( *pos == *pos_){
				container_.erase(pos_);
				pos_--;
			}
		}
	}
}

/**SmartProductContainer::ContentT SmartProductContainer::find_product( const SmartProduct& product ) const
{
	ContentT result(container_.size());
	std::copy_if(container_.begin(), container_.end(), result.begin(), Comparator( product ) );
	return result;
}**/

const SmartProductContainer::ContentT& SmartProductContainer::find_product( const std::string& name, ContentT& result ) const
{
	ContentT::const_iterator pos;
	for( pos = container_.begin(); pos != container_.end(); ++pos ){
		if( pos->get_name() == name )
			result.push_back( *pos );
	}
	return result;
}

const SmartProductContainer::ContentT& SmartProductContainer::get_products() const
{
	return container_;
}



}//end namespace model
}//end namespace domain

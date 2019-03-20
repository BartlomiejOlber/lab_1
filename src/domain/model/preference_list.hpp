/*
 * preference_list.hpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#ifndef DOMAIN_MODEL_PREFERENCE_LIST_HPP_
#define DOMAIN_MODEL_PREFERENCE_LIST_HPP_

#include <vector>
#include "preference.hpp"

namespace domain {
namespace model {

class PreferenceList {

public:
	typedef std::vector<Preference> ListT;

private:
	ListT list_;

public:
	void add_preference( const std::string& name, const std::string& type, double value );
	void remove_preference( const std::string& name, const std::string& type );
	const Preference* find_preference( const std::string& name, const std::string& type ) const;
	const ListT& get_preferences() const;
};

}//end namespace model
}//end namespace domain



#endif /* DOMAIN_MODEL_PREFERENCE_LIST_HPP_ */

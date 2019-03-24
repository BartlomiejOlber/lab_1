/*
 * preferences_interface.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: bartlomiej
 */

#include <iomanip>
#include <iostream>
#include "base_interface.hpp"
#include "preference_interface.hpp"
#include "../application/preference_service.hpp"


namespace UI{

using namespace domain::model;
using namespace application;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

class PreferenceUI : public Interface {

public:
	PreferenceList& preference_list_;
	PreferenceUI( PreferenceList& preference_list ) : preference_list_( preference_list ) {};
	void print_list();
	void remove_item();
	void add_item();
};

void PreferenceUI::remove_item()
{
	std::string item_name, preference_type;
	cout << "\n\tName the item: ";
	item_name = get_name();
	cout << "\n\tName the preference type [expiry_date OR minimal_quantity]: ";
	preference_type = get_name();
	preference_list_.remove_preference( item_name, preference_type );
}

void PreferenceUI::add_item()
{
	double preference_value = 0.0;
	std::string item_name, preference_type;
	std::cout << "\n***You can add your specified preference e.g. milk expiry_date 3"
			" - a milk will be added to the shopping list if the one in refridgerator expires within 3 days***";
	std::cout << "\n\tName the item: ";
	item_name = get_name();
	std::cout << "\n\tName the preference type [expiry_date OR minimal_quantity]: ";
	preference_type = get_name();
	std::cout << "\n\tSet the value: ";
	preference_value = get_double();
	preference_list_.add_preference( item_name, preference_type, preference_value );
}

void PreferenceUI::print_list()
{
	std::system("clear");
	const PreferenceList::ListT& preferences = preference_list_.get_preferences();
	PreferenceList::ListT::const_iterator pos;
	std::cout << "*Preferences*" << std::endl;
	std::cout <<std::endl;
	for(pos = preferences.begin(); pos!=preferences.end(); ++pos){
		cout << "\t| Preference | "<< setw( 20 ) << right <<pos->getItemName() << " | "
			<< setw( 17 )<< right <<PreferenceTypeConverter::to_string(pos->getType())<< " | "
			<< setw(3) << right <<pos->getValue() << " |" << endl;
	}
}

void PreferenceInterface::display_options()
{
	cout<< "\n\n[1]. Remove a preference"<< endl;
	cout<< "[2]. Add a preference"<< endl;
	cout<< "[3]. Back"<<std::endl;
	cout<< "\n Selection: ";
}

void PreferenceInterface::loop()
{
	PreferenceList preferences;
	PreferenceService service;
	service.init_preference_list( preferences );
	PreferenceUI preference_ui( preferences );
	int choice = 0;
	do{
		std::system("clear");
		preference_ui.print_list();
		display_options();
		choice = get_number();
		switch(choice)
		{
			case 1:
				preference_ui.remove_item();
				break;
			case 2:
				preference_ui.add_item();
				break;
		}
	}while(choice != 3);
	service.save_preference_list( preferences );
	std::system("clear");
}

}//end namespace


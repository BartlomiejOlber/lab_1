//============================================================================
// Name        : lab_1.cpp
// Author      : d
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "main_or_test.hpp"
#include "UI/main_options.hpp"

#ifndef UNIT_TEST_CATCH


using namespace std;


int main() {

	UI::MainOptions main_options;
	main_options.loop_controler();

	return 0;
}

#endif

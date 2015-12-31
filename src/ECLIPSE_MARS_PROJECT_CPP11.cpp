//============================================================================
// Name        : ECLIPSE_MARS_PROJECT_CPP11.cpp
// Author      : Francesco Forcher
// Version     : 0.1
// Copyright   : All rights reserved © 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <vector>
using namespace std;



// PROGETTO PENSATO PER SALVARE TUTTE LE VARIE OPZIONI POSSIBILI
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	std::unique_ptr<double> p(new double(4));
	std::vector<double> v = {1,2,3};


	cout << *p;
	cout << v[1];
	return 0;
}


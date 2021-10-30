#include<iostream>
#include"SudokuMap.h"
#include"UnitTests.h"


int main()
{
	SudokuMap myMap;
	myMap.showMap();
	std::cout << std ::endl;
	testInit();
	showTests();
	return 0;
}
#include<iostream>
#include"SudokuMap.h"
#include"UnitTests.h"


bool TestConstructorSudokuMapReturnsStartMatrix()
{
	SudokuMap testMap;
	int StartMatrix[9][9] = {
		{1,2,3,4,5,6,7,8,9},
		{4,5,6,7,8,9,1,2,3},
		{7,8,9,1,2,3,4,5,6},
		{2,3,4,5,6,7,8,9,1},
		{5,6,7,8,9,1,2,3,4},
		{8,9,1,2,3,4,5,6,7},
		{3,4,5,6,7,8,9,1,2},
		{6,7,8,9,1,2,3,4,5},
		{9,1,2,3,4,5,6,7,8}
	};
	for (int i = 0; i < testMap.dim; i++)
		for (int j = 0; j < testMap.dim; j++)
			if (StartMatrix[i][j] != testMap.map[i][j])
				return false;
	return true;
}

void testInit()
{
	testsPtr[0] = TestConstructorSudokuMapReturnsStartMatrix;
}

void showTests()
{
	for (int i = 0; i < testCount; i++)
		std :: cout << "Test " << i + 1 << " : " << testsPtr[i]();
}

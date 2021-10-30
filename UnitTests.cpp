#include<iostream>
#include<iomanip>
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
bool TestTransposeReturnsTransposedMatrix()
{
	SudokuMap testMap;
	testMap.transpose();
	int TransposedStartMatrix[9][9] = {
		{1,4,7,2,5,8,3,6,9},
		{2,5,8,3,6,9,4,7,1},
		{3,6,9,4,7,1,5,8,2},
		{4,7,1,5,8,2,6,9,3},
		{5,8,2,6,9,3,7,1,4},
		{6,9,3,7,1,4,8,2,5},
		{7,1,4,8,2,5,9,3,6},
		{8,2,5,9,3,6,1,4,7},
		{9,3,6,1,4,7,2,5,8}
	};
	for (int i = 0; i < testMap.dim; i++)
		for (int j = 0; j < testMap.dim; j++)
			if (TransposedStartMatrix[i][j] != testMap.map[i][j])
				return false;
	return true;
}

void testInit()
{
	testsPtr[0] = TestConstructorSudokuMapReturnsStartMatrix;
	testsPtr[1] = TestTransposeReturnsTransposedMatrix;
}

void showTests()
{
	for (int i = 0; i < testCount; i++)
		std::cout << "Test " << i + 1 << " : " << testsPtr[i]() << std :: endl;
}

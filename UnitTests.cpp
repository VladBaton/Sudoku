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
bool SwapRowsSwapsRows()
{
	SudokuMap testMap, helpMap; 
	testMap.swapRows();
	int changedRow1 = -1, changedRow2 = -1;
	for (int i = 0; i < testMap.dim; i++)
		if (testMap.map[i][0] != helpMap.map[i][0] && changedRow1 == -1)
			changedRow1 = i;
		else if(testMap.map[i][0] != helpMap.map[i][0] && changedRow2 == -1)
			changedRow2 = i;
	for (int i = 0; i < testMap.dim; i++)
		if (i == changedRow1)
			for (int j = 0; j < testMap.dim; j++)
				if (testMap.map[i][j] != helpMap.map[changedRow2][j])
					return false;
				else
					continue;
		else if (i == changedRow2)
			for (int j = 0; j < testMap.dim; j++)
				if (testMap.map[i][j] != helpMap.map[changedRow1][j])
					return false;
				else
					continue;
		else
			for (int j = 0; j < testMap.dim; j++)
				if (testMap.map[i][j] != helpMap.map[i][j])
					return false;
				else
					continue;
	return true;
}
bool SwapRowRegionsSwapsRowRegions()
{
	SudokuMap testMap, helpMap;
	testMap.swapRowRegions();
	int changedRowRegion1 = -1, changedRowRegion2;
	for (int i = 0; i < 3; i++)
		if (testMap.map[i * 3][0] != helpMap.map[i * 3][0] && changedRowRegion1 == -1)
			changedRowRegion1 = i;
		else if (testMap.map[i * 3][0] != helpMap.map[i * 3][0])
			changedRowRegion2 = i;
	for (int i = 0; i < 3; i++)
		if (i == changedRowRegion1)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 9; k++)
					if (testMap.map[i * 3 + j][k] != helpMap.map[changedRowRegion2 * 3 + j][k])
						return false;
					else
						continue;
		else if (i == changedRowRegion2)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 9; k++)
					if (testMap.map[i * 3 + j][k] != helpMap.map[changedRowRegion1 * 3 + j][k])
						return false;
					else
						continue;
		else
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 9; k++)
					if (testMap.map[i * 3 + j][k] != helpMap.map[i * 3 + j][k])
						return false;
					else
						continue;
	return true;
}

void testInit()
{
	testsPtr[0] = TestConstructorSudokuMapReturnsStartMatrix;
	testsPtr[1] = TestTransposeReturnsTransposedMatrix;
	testsPtr[2] = SwapRowsSwapsRows;
	testsPtr[3] = SwapRowRegionsSwapsRowRegions;
}

void showTests()
{
	for (int i = 0; i < testCount; i++)
		std::cout << "Test " << i + 1 << " : " << testsPtr[i]() << std :: endl;
}

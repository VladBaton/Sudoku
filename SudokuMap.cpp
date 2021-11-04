#include<iostream>
#include<time.h>
#include"SudokuMap.h"
#include<iomanip>

SudokuMap::SudokuMap()
{
	srand(time(0));
	dim = 9;
	map = new int*[dim];
	for (int i = 0; i < dim; i++)
		map[i] = new int[dim];
	for (int i = 0; i < dim / 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < dim; k++)
				map[j + 3 * i][k] = (k + 3 * j + i) % 9 + 1;
}
SudokuMap::~SudokuMap()
{
	for (int i = 0; i < dim; i++)
		delete[] map[i];
	delete[] map; 
}
void SudokuMap::transpose()
{
	int** temp = new int* [dim];
	for (int i = 0; i < dim; i++)
		temp[i] = new int[dim];
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			temp[i][j] = map[j][i];
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			map[i][j] = temp[i][j];
	for (int i = 0; i < dim; i++)
		delete[] temp[i];
	delete[] temp;
}
void SudokuMap::swapRows()
{
	srand(time(0));
	int randRegion = rand() % 3;
	int randRow1 = rand() % 3;
	int randRow2; 
	do
	{
		randRow2 = rand() % 3;
	} while (randRow1 == randRow2);

	int* temp = new int[dim];

	for (int j = 0; j < dim; j++)
		temp[j] = map[3 * randRegion + randRow1][j];
	for (int j = 0; j < dim; j++)
		map[3 * randRegion + randRow1][j] = map[3 * randRegion + randRow2][j];
	for (int j = 0; j < dim; j++)
		map[3 * randRegion + randRow2][j] = temp[j];
	delete[] temp;
}
void SudokuMap::swapColumns()
{
	transpose();
	swapRows();
	transpose();
}
void SudokuMap::swapRowRegions()
{
	srand(time(0));
	int randRegion1 = rand() % 3;
	int randRegion2;
	do
	{
		randRegion2 = rand() % 3;
	} while (randRegion1 == randRegion2);

	int** tempRegion = new int*[3];
	for (int i = 0; i < 3; i++)
		tempRegion[i] = new int[9];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < dim; j++)
			tempRegion[i][j] = map[randRegion1 * 3 + i][j];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < dim; j++)
			map[randRegion1 * 3 + i][j] = map[randRegion2 * 3 + i][j];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < dim; j++)
			map[randRegion2 * 3 + i][j] = tempRegion[i][j];

	for (int i = 0; i < 3; i++)
		delete[] tempRegion[i];
	delete[] tempRegion;
}
void SudokuMap::swapColumnRegions()
{
	transpose();
	swapRowRegions();
	transpose();
}
const int* SudokuMap::operator[](unsigned int i) const
{
	return map[i];
}
int SudokuMap::giveDim() const
{
	return dim;
}

void SudokuMap::showMap() const
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
				std::cout << '|';
			std::cout << map[i][j];
		}
		std :: cout << std :: endl;

		if (i % 3 == 2)
		{
			std::cout.fill('-');
			std::cout << std :: setw(13) << ' ';
			std :: cout << std :: endl;
		}
	}
}
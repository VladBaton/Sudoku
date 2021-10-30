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
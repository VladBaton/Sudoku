#include"SudokuGame.h"
#include<iostream>
#include<iomanip>
#include<time.h>

SudokuGame :: SudokuGame() : SudokuMap()
{
	isVisible = new bool*[giveDim()];
	for (int i = 0; i < giveDim(); i++)
	{
		isVisible[i] = new bool[giveDim()];
		for (int j = 0; j < giveDim(); j++)
			isVisible[i][j] = true;
	}
}

SudokuGame::~SudokuGame()
{
	for (int i = 0; i < giveDim(); i++)
		delete[] isVisible[i];
	delete[] isVisible;
}

void SudokuGame::mixMap()
{
	srand(time(0));
	for (int i = 0; i < 99; i++)
	{
		int randomAction = rand() % 5;
		switch (randomAction)
		{
		case 0: SudokuMap :: transpose(); break;
		case 1: SudokuMap :: swapRows(); break;
		case 2: SudokuMap :: swapColumns(); break;
		case 3: SudokuMap :: swapRowRegions(); break;
		case 4: SudokuMap :: swapColumnRegions(); break;
		}
	}
}

void SudokuGame::show() const
{
	for (int i = 0; i < giveDim(); i++)
	{
		for (int j = 0; j < giveDim(); j++)
		{
			if (j % 3 == 0)
				std::cout << '|';
			if (isVisible[i][j])
				std::cout << SudokuGame::operator[](i)[j];
			else
				std::cout << '-';
		}
		std::cout << std::endl;

		if (i % 3 == 2)
		{
			std::cout.fill('-');
			std::cout << std::setw(13) << ' ';
			std::cout << std::endl;
		}
	}
}
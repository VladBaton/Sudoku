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
	for (int i = 0; i < 999; i++)
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

void SudokuGame::setGame()
{
	srand(time(0));
	bool** isViewed = new bool*[giveDim()];
	for (int i = 0; i < giveDim(); i++)
		isViewed[i] = new bool[giveDim()];
	for (int i = 0; i < giveDim(); i++)
		for (int j = 0; j < giveDim(); j++)
			isViewed[i][j] = false;

	do
	{
		bool isAllElemViewed = true;
		for (int i = 0; i < giveDim(); i++)
			for (int j = 0; j < giveDim(); j++)
				if (isViewed[i][j] != true)
					isAllElemViewed = false;
		if (isAllElemViewed)
			break;

		int randomI = rand() % giveDim();
		int randomJ = rand() % giveDim();
		isViewed[randomI][randomJ] = true;
		isVisible[randomI][randomJ] = false;

		bool* setOfVisibleNeighbors = new bool[giveDim()];
		for (int i = 0; i < giveDim(); i++)
			setOfVisibleNeighbors[i] = false;

		for (int j = 0; j < giveDim(); j++)
			if (isVisible[randomI][j])
				setOfVisibleNeighbors[SudokuMap::operator[](randomI)[j] - 1] = true;

		for (int i = 0; i < giveDim(); i++)
			if (isVisible[i][randomJ])
				setOfVisibleNeighbors[SudokuMap::operator[](i)[randomJ] - 1] = true;

		int iRegion = randomI / 3;
		int jRegion = randomJ / 3;
		for (int iInReg = 0; iInReg < 3; iInReg++)
			for (int jInReg = 0; jInReg < 3; jInReg++)
				if (isVisible[iRegion * 3 + iInReg][jRegion * 3 + jInReg])
					setOfVisibleNeighbors[SudokuMap::operator[](iRegion * 3 + iInReg)[jRegion * 3 + jInReg] - 1] = true;

		int falseCount = 0;
		for (int i = 0; i < giveDim(); i++)
			if (setOfVisibleNeighbors[i] == false)
				falseCount++;

		if (falseCount != 1)
			isVisible[randomI][randomJ] = true;

		delete[] setOfVisibleNeighbors;
	} while (true);

	for (int i = 0; i < giveDim(); i++)
		delete[] isViewed[i];
	delete[] isViewed;

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
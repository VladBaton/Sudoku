#include<iostream>
#include<time.h>
#include"SudokuMap.h"

SudokuMap::SudokuMap()
{
	srand(time(0));
	//map = new int*[9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			map[i][j] = -1;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int k;
			while (true)
			{
				k = rand() % 9 + 1;
				bool isEqualNumInLine = false;
				bool isEqualNumInColumn = false;
				bool isEqualNumInSquare = false;
				for (int jj = 0; jj < 9; jj++)
					if (map[i][jj] == k)
						isEqualNumInLine = true;
				for (int ii = 0; ii < 9; ii++)
					if (map[ii][j] == k)
						isEqualNumInColumn = true;
				int JSquare = j / 3; // 0 - если нах-с€ в первых трЄх стобцах, 1 - во вторых, 2 - в третьих
				int ISquare = i / 3;// 0 - если нах-с€ в первых трЄх строках, 1 - во вторых, 2 - в третьих
				for (int ii = 3 * ISquare; ii < 3 * ISquare + 3; ii++)
					for (int jj = 3 * JSquare; jj < 3 * JSquare + 3; jj++)
						if (map[ii][jj] == k)
							isEqualNumInSquare = true;
				if(!isEqualNumInColumn && !isEqualNumInLine && !isEqualNumInSquare)
					break; // Ќјшли элемент, удовлетвор€ющий услови€м
			}
			map[i][j] = k;
		}
	}
}
void SudokuMap::showMap() const
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
				std::cout << ' ';
			std::cout << map[i][j];
		}
		std :: cout << std :: endl;
	}
}
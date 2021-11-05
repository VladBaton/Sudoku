#include<iostream>
#include"SudokuMap.h"
#include"UnitTests.h"
#include"SudokuGame.h"


int main()
{
	SudokuGame myGame;
	myGame.show();
	myGame.mixMap();
	myGame.setGame();
	std::cout << std::endl;
	myGame.show();
	return 0;
}
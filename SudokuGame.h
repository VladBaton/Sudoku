#pragma once
#include"SudokuMap.h"
#include<string>
#include<tuple>
#include"drawSudoku.h"


class SudokuGame : public SudokuMap
{
private:
	bool** isVisible;
public:
	SudokuGame();
	SudokuGame(std :: string file); // loads isVisible from file
	~SudokuGame();
	void mixMap();
	void setGame();
	void saveGame() const;
	void show() const;
	bool insertNumber(int number, int row, int column);
	std::tuple<Cell**, int> getMap();
};
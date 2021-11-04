#pragma once
#include"SudokuMap.h"

class SudokuGame : public SudokuMap
{
private:
	bool** isVisible;
public:
	SudokuGame();
	~SudokuGame();
	void mixMap();
	void show() const;
};
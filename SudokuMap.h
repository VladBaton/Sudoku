#ifndef SUDOKUMAP
#define SUDOKUMAP
#include"UnitTests.h"
class SudokuMap
{
private:
	int** map;
	int dim;
public:
	SudokuMap();
	~SudokuMap();
	void transpose();
	void showMap() const;
	friend bool TestConstructorSudokuMapReturnsStartMatrix();
};
#endif
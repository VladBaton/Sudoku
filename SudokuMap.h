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
	void swapRows();
	void swapColumns();
	void showMap() const;
	friend bool TestConstructorSudokuMapReturnsStartMatrix();
	friend bool TestTransposeReturnsTransposedMatrix();
	friend bool SwapRowsSwapsRows();
};
#endif
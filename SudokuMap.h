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
	void swapRowRegions();
	void showMap() const;
	friend bool TestConstructorSudokuMapReturnsStartMatrix();
	friend bool TestTransposeReturnsTransposedMatrix();
	friend bool SwapRowsSwapsRows();
	friend bool SwapRowRegionsSwapsRowRegions();
};
#endif
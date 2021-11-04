#ifndef SUDOKUMAP
#define SUDOKUMAP
#include"UnitTests.h"
class SudokuMap
{
private:
	int** map;
	int dim;
protected:
	const int* operator[] (unsigned int i) const;
	void transpose();
	void swapRows();
	void swapColumns();
	void swapRowRegions();
	void swapColumnRegions();
	int giveDim() const;
public:
	SudokuMap();
	~SudokuMap();
	void showMap() const;
	friend bool TestConstructorSudokuMapReturnsStartMatrix();
	friend bool TestTransposeReturnsTransposedMatrix();
	friend bool SwapRowsSwapsRows();
	friend bool SwapRowRegionsSwapsRowRegions();
	friend bool OperatorStraightBracketsReturnsMapElem();
	friend bool  OperatorStraightBracketsAllowChangingMapElem();
};
#endif
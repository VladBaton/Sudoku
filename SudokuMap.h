#ifndef SUDOKUMAP
#define SUDOKUMAP
#include"UnitTests.h"
#include<string>
class SudokuMap
{
private:
	int** map;
	int dim;
protected:
	void operator=(SudokuMap& secondMap);
	void transpose();
	void swapRows();
	void swapColumns();
	void swapRowRegions();
	void swapColumnRegions();
public:
	SudokuMap();
	SudokuMap(std :: string file);
	~SudokuMap();
	void showMap() const;
	int giveDim() const;
	const int* const operator[] (unsigned int i) const;
	friend bool TestConstructorSudokuMapReturnsStartMatrix();
	friend bool TestTransposeReturnsTransposedMatrix();
	friend bool SwapRowsSwapsRows();
	friend bool SwapRowRegionsSwapsRowRegions();
	friend bool OperatorStraightBracketsReturnsMapElem();
};
#endif
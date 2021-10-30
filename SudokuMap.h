#ifndef SUDOKUMAP
#define SUDOKUMAP

class SudokuMap
{
private:
	int** map;
	int dim;
public:
	SudokuMap();
	void showMap() const;
};
#endif
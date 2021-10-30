#ifndef SUDOKUMAP
#define SUDOKUMAP

class SudokuMap
{
private:
	int** map;
	int dim;
public:
	SudokuMap();
	~SudokuMap();
	void showMap() const;
};
#endif
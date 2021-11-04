#ifndef UNITTESTS
#define UNITTESTS

const int testCount = 6;
static bool (*testsPtr[testCount])();
bool TestConstructorSudokuMapReturnsStartMatrix();
bool TestTransposeReturnsTransposedMatrix();
bool SwapRowsSwapsRows();
bool SwapRowRegionsSwapsRowRegions();
bool OperatorStraightBracketsReturnsMapElem();
void testInit();
void showTests();
#endif
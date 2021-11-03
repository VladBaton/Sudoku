#ifndef UNITTESTS
#define UNITTESTS

const int testCount = 4;
static bool (*testsPtr[testCount])();
bool TestConstructorSudokuMapReturnsStartMatrix();
bool TestTransposeReturnsTransposedMatrix();
bool SwapRowsSwapsRows();
bool SwapRowRegionsSwapsRowRegions();
void testInit();
void showTests();
#endif
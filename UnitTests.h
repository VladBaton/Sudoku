#ifndef UNITTESTS
#define UNITTESTS

const int testCount = 3;
static bool (*testsPtr[testCount])();
bool TestConstructorSudokuMapReturnsStartMatrix();
bool TestTransposeReturnsTransposedMatrix();
bool SwapRowsSwapsRows();
void testInit();
void showTests();
#endif
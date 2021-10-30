#ifndef UNITTESTS
#define UNITTESTS

const int testCount = 2;
static bool (*testsPtr[testCount])();
bool TestConstructorSudokuMapReturnsStartMatrix();
bool TestTransposeReturnsTransposedMatrix();
void testInit();
void showTests();
#endif
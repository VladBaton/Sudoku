#ifndef UNITTESTS
#define UNITTESTS
const int testCount = 1;
static bool (*testsPtr[testCount])();
bool TestConstructorSudokuMapReturnsStartMatrix();
void testInit();
void showTests();
#endif
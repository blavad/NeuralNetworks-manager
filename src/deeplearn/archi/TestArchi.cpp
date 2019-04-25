#include <cppunit/ui/text/TestRunner.h>
#include "TestTenseur.hpp"
#include "Tenseur.cpp"
#include "DimTenseur.cpp"

int main(int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(TestTenseur::suite());
    runner.run();
    return 0;
}
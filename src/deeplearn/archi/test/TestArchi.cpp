#include <cppunit/ui/text/TestRunner.h>
#include "TestGraphe.hpp"
#include "TestCouche.hpp"
#include "TestTenseur.hpp"
#include "../Tenseur.cpp"
#include "../DimTenseur.cpp"

int main(int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(TestTenseur::suite());
    runner.addTest(TestCouche::suite());
    runner.addTest(TestGraphe::suite());
    runner.run();
    return 0;
}

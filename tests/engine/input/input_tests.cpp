// map_tests.h

#include "input_tests.h"

InputTest::InputTest()
    : d_in( StevensDev::sgdi::Input::inst() )
{
}

void InputTest::SetUp()
{
    d_in.preTick();
}

void InputTest::TearDown()
{
}

InputTest::~InputTest()
{
}


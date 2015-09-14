// game.m.cpp

#include "src/engine/memory/default_allocator.h"
#include "src/engine/containers/dynamic_array.h"
#include <iostream>

int main( int argc, char **argv )
{
    using namespace StevensDev;

    sgdm::DefaultAllocator<int*> alloc;

    sgdc::DynamicArray<int*>     array(&alloc);

    array.push(new int(1));
    array.push(new int(2));

    std::cout << array.getLength() << std::endl;

    return 0;
}

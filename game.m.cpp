// game.m.cpp

#include <iostream>
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/containers/dynamic_array.h"
#include <iostream>

int main( int argc, char **argv )
{
    using namespace StevensDev;

    sgdm::CountingAllocator<int>     d_alloc;
    sgdc::DynamicArray<int>          arr(&d_alloc);

    arr.push(42);
    arr.push(44);
    arr.push(48);

    return arr.getLength();

    /*
    sgdc::DynamicArray<int*>     array(&alloc);

    array.push(new int(1));
    array.push(new int(2));

    std::cout << array.getLength() << std::endl;
    */

}

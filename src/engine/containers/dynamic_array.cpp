// dynamic_array.cpp

#include "dynamic_array.h"

namespace sgdc
{

DynamicArray::DynamicArray( IAllocator* alloc )
    : d_allocator( alloc ), d_array( 0 )
{
    // TODO: Allocate d_array?
}

} // End sgdc namespace

// dynamic_array.cpp

template<typename T>
StevensDev::sgdc::DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
    : d_allocator( alloc ), d_array( 0 )
{
}

template<typename T>
unsigned int const StevensDev::sgdc::DynamicArray<T>::getLength()
{
    return d_length;
}

template<typename T>
const T StevensDev::sgdc::DynamicArray<T>::at( unsigned int index )
{
    return *(d_array + index);
}

// TODO
template<typename T>
T StevensDev::sgdc::DynamicArray<T>::operator[]( int index )
{
    return 0;
}

/*
template<typename T>
const T StevensDev::sgdc::DynamicArray<T>::operator[]( int index )
{
    return *(d_array + index);
}
*/

template<typename T>
void StevensDev::sgdc::DynamicArray<T>::push( const T& element)
{
    // TODO: Error checking, do we have to check if element is null?? XXX

    // Allocate new memory if needed
    if ( d_length >= d_size)
    {
        // TODO
    }

    // Push the element into the array and increase size
    d_array[d_length] = element;
    d_length++;
}

// TODO: See push()
template<typename T>
void StevensDev::sgdc::DynamicArray<T>::pushFront( T element )
{
}

template<typename T>
T StevensDev::sgdc::DynamicArray<T>::pop()
{
    // Error checking
    if ( d_length <= 0 )
        return 0;

    // Decrease size of the array and return the last element
    d_length--;
    return d_array[d_length];
}

template<typename T>
T StevensDev::sgdc::DynamicArray<T>::popFront()
{
    // Error checking
    if ( d_length <= 0 )
        return 0;

    // Keep the element to return
    T ret = d_array[0];

    // Shift and decrease size
    // TODO: Shift, before decreasing size
    d_length--;

    // Return
    return ret;
}

template<typename T>
T StevensDev::sgdc::DynamicArray<T>::removeAt( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        return 0; // TODO: Throw exception

    // Decrease size and shift array
    shift( index, true );
    d_length--;
}

template<typename T>
T StevensDev::sgdc::DynamicArray<T>::insertAt( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        return 0; // TODO: Throw exception

    // Shift array and decrease size
    shift( index, false );
    d_length++;

    // Insert
    T val = 0; // TODO: Where is the value we wanna insert?
    d_array[index] = val;

    // Return
    return val;
}

// TODO: Shift element from index to the last one
template<typename T>
void StevensDev::sgdc::DynamicArray<T>::shift( unsigned int index, bool shiftLeft )
{
    // Error checking
    if ( index < 0 || index > d_length )
        return 0; // TODO: Throw exception

    // If shift right, check if allocated size is enough
    if (!shiftLeft && d_length + 1 >= d_size)
        return 0; // TODO: Allocate new memory

    // TODO: Shift
}

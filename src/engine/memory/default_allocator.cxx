// default_allocator.cxx

template<class T>
StevensDev::sgdm::DefaultAllocator<T>::DefaultAllocator()
{
}

template<class T>
T* StevensDev::sgdm::DefaultAllocator<T>::get( int count )
{
    // Error checking
    if (count < 0)
        return 0;

    // Create the value
    T       *val = new T[count];

    // Return the memory
    return val;
}

template<class T>
void StevensDev::sgdm::DefaultAllocator<T>::release( T* ptr, int count )
{
    // Error checking
    if (ptr == 0 || count < 0)
        return 0;

    // Release the memory
    // TODO: How are we supposed to use count?
    // Maybe, if count > 1 then use delete[] otherwise use delete.
    delete[] ptr;
}

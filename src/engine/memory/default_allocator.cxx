// default_allocator.cxx

template<class T>
T* DefaultAllocator<T>::get( int count )
{
    return 0;
}

template<class T>
void DefaultAllocator<T>::release( T* ptr, int count )
{
    return;
}

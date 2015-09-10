// default_allocator.cxx

template<class T>
T* StevensDev::sgdm::DefaultAllocator<T>::get( int count )
{
    return 0;
}

template<class T>
void StevensDev::sgdm::DefaultAllocator<T>::release( T* ptr, int count )
{
    return;
}

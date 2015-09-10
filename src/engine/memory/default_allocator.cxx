// default_allocator.cxx

template<class T>
T* sgdm::DefaultAllocator<T>::get( int count )
{
    return 0;
}

template<class T>
void sgdm::DefaultAllocator<T>::release( T* ptr, int count )
{
    return;
}

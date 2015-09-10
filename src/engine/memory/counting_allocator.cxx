// counting_allocator.cxx

template<typename T>
StevensDev::sgdm::CountingAllocator<T>::CountingAllocator()
    : d_allocation_count( 0 ), d_release_count( 0 )
{
}

template<typename T>
int const StevensDev::sgdm::CountingAllocator<T>::getAllocationCount()
{
    return d_allocation_count;
}

template<typename T>
int const StevensDev::sgdm::CountingAllocator<T>::getReleaseCount()
{
    return d_release_count;
}

template<typename T>
int const StevensDev::sgdm::CountingAllocator<T>::getOutstandingCount()
{
    return d_allocation_count - d_release_count;
}

template<typename T>
int StevensDev::sgdm::CountingAllocator<T>::getTotalAllocationCount()
{
    return d_total_allocation_count;
}

template<typename T>
int StevensDev::sgdm::CountingAllocator<T>::getTotalReleaseCount()
{
    return d_total_release_count;
}

template<typename T>
int StevensDev::sgdm::CountingAllocator<T>::getTotalOutstandingCount()
{
    return d_total_allocation_count - d_total_release_count;
}


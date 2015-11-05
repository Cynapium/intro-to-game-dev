//
// File: stack_guard.h
// Author: Barbara Crepeau
//
// Define StackGuard templated class and its functions
//

#ifndef INCLUDED_STACK_GUARD
# define INCLUDED_STACK_GUARD

namespace StevensDev
{
namespace sgdm
{

// Act like a smart pointer around a given pointer
template<typename T>
class StackGuard
{
  private:

    T*                  d_ptr;
      // Pointer to type T


  public:

    // CONSTRUCTORS

    StackGuard( T* guarded );
      // Create a new StackGuard around a pointer

    StackGuard( const StackGuard<T>& stackGuard ) = delete;
      // Copy constructor
      // We explicitly tell the compiler to delete it because we don't want to
      // be able to make a copy of a StackGuard.


    // DESTRUCTOR

    ~StackGuard();
      // Destroy the pointer


    // OPERATORS

    T* operator->() const;
      // Pointer access operator

    const bool operator!();
      // Logical NOT operator

    const bool operator==( bool rhs );
      // Equality operator

    const bool operator!=( bool rhs );
      // Inequality operator
};

template<typename T>
inline
StackGuard<T>::StackGuard( T* guarded )
    : d_ptr( guarded )
{
}

template<typename T>
inline
StackGuard<T>::~StackGuard()
{
    if ( d_ptr != nullptr )
        delete d_ptr;
}

template<typename T>
inline
T*
StackGuard<T>::operator->() const
{
    return d_ptr;
}

template<typename T>
inline
const bool
StackGuard<T>::operator!()
{
    if ( d_ptr == nullptr )
        return true;

    return false;
}

template<typename T>
inline
const bool
StackGuard<T>::operator==( bool rhs )
{
    if ( d_ptr != nullptr )
        return rhs;

    return !rhs;
}

template<typename T>
inline
const bool
StackGuard<T>::operator!=( bool rhs )
{
    if ( d_ptr == nullptr )
        return rhs;

    return !rhs;
}

} // End sgdm namespace
} // End StevenDevs namespace

#endif // INCLUDED_STACK_GUARD

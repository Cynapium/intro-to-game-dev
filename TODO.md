# TODO

## Week 1

### GitHub Open Source Project
- [x] Create Github repository
- [x] Create file README

### Coding Style
- [x] Create coding style file
- [x] Link the file from README

### Main
- [x] Create main in `game.m.cpp`

### Structure
- [x] Create src/ directory

### Make
- [x] Configure CMake (CMakeList.txt)

### Google Test
- [x] Install gtest
- [x] Add gtest support to CMakeList.txt
- [x] Create dummy tests
- [x] Configure Travis

---

## Week 2

### Allocator Interface

- [ ] (ABSTRACT) get( int count ) : T\*
- [ ] (ABSTRACT) release( T\*, int count ) : void

### Default Allocator

- [ ] Default implementation of IAllocator using new and delete

### Counting Allocator

- [ ] getAllocationCount() : int const
- [ ] getReleaseCount() : int const
- [ ] getOutstandingCount() : int const
- [ ] (STATIC) getTotalAllocationCount() : int
- [ ] (STATIC) getTotalReleaseCount() : int
- [ ] (STATIC) getOutstandingCount() : int

### Dynamic Array

- [ ] DynamicArray( IAllocator\* alloc )
- [ ] push( const T& element ) : void
- [ ] pushFront( T element ) : void
- [ ] pop() : T
- [ ] popFront() : T
- [ ] getLength() : unsigned int const
- [ ] at( unsigned int index ) : T const
- [ ] [ int ] : T
- [ ] [ int ] : T const
- [ ] removeAt( unsigned int index ) : T
- [ ] insertAt( unsigned int index ) : T


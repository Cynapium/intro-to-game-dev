# TODO

---

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

- [x] \(ABSTRACT\) get( int count ) : T\*
- [x] \(ABSTRACT\) release( T\*, int count ) : void

### Default Allocator

- [x] get( int count ) : T\*
- [ ] release( T\*, int count ) : void

### Counting Allocator

- [x] getAllocationCount() : int const
- [x] getReleaseCount() : int const
- [x] getOutstandingCount() : int const
- [x] \(STATIC\) getTotalAllocationCount() : int
- [x] \(STATIC\) getTotalReleaseCount() : int
- [x] \(STATIC\) getOutstandingCount() : int

### Dynamic Array

- [x] DynamicArray( IAllocator\* alloc )
- [x] push( const T& element ) : void
- [x] pushFront( T element ) : void
- [x] pop() : T
- [x] popFront() : T
- [x] getLength() : unsigned int const
- [x] at( unsigned int index ) : T const
- [x] \[ int \] : T
- [x] \[ int \] : T const
- [x] removeAt( unsigned int index ) : T
- [x] insertAt( unsigned int index ) : T

---

## Week 3

### Allocator Interface

- [x] construct( T\* pointer, Args&&... args ) : void
- [x] construct( T\* pointer, const T& copy ) : void
- [x] destruct( T\* pointer ) : void

### Map

- [x] Map( IAllocator\* allocator )
- [x] Orthodox canonical form
- [x] Operator <<
- [x] \[ const string& key \] : T&
- [x] \[ const string& key \] const : const T&
- [x] has( const string& key ) : bool
- [x] remove( const string& key ) : T
- [x] keys() const : DynamicArray<string>
- [x] values() const : DynamicArray<T>
- [x] Tests
- [x] Trie implementation

### Node

- [x] Default constructor
- [x] Copy constructor
- [x] Move constructor
- [x] Move operator assignment
- [x] Destructor
- [x] addChild();

---

## Week 4

---

## Week 1

### ITickable

- [x] Create interface


### Input

- [ ] Implements ITickable
- [x] static inst() : Input&
- [x] isDown ( type : InputType ) : bool
- [x] isUp( type : InputType ) : bool
- [x] wasPressed( type : InputType ) : bool
- [x] preTick() : void
- [x] Delete copy constructor / assignment operator
- [ ] Destructor


### RenderableSprite

- [ ] d_sprite sf::Sprite
- [ ] sprite() const : const sf::Sprite&
- [ ] setPosition( x : float, y : float ) : void
- [ ] getPositionX() : float
- [ ] getPositionY() : float
- [ ] move( x : float, y : float ) : void

### Renderer

- [ ] d_sprites : DynamicArray<RenderableSprite*>
- [ ] draw() : void
- [ ] addSprite( sprite : RenderableSprite* ) : void
- [ ] removeSprite( sprite : RenderableSprite* ) : void
- [ ] setupWindow( width : int, height : int ) : void
- [ ] loadTexture( name : const String&, path : const String& ) : bool
- [ ] getTexture( name : const String& ) : const sf::Texture&
- [ ] isActive() : bool


### Scene

- [ ] Singleton implementation
- [ ] static inst() : Scene&
- [ ] tick() : void
- [ ] addTickable( tickable : ITickable* ) : void
- [ ] removeTickable( tickable : ITickable* ) : void
- [ ] setRenderer( renderer : Renderer* ) : void

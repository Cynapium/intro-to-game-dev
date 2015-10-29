// nxn_scene_graph.h

#ifndef INCLUDED_NXN_SCENE_GRAPH
# define INCLUDED_NXN_SCENE_GRAPH

#include "containers/dynamic_array.h"
#include "rectangle_bounds.h"
#include "itickable.h"
#include "icollider.h"

namespace StevensDev
{
namespace sgds
{

class NxNSceneGraph : public ITickable
{
  private:

    float                   d_dimensions;
      // Dimensions (w * h) of the scene

    int                     d_divisions;
      // Number of rows and columns in the scene

    sgdc::DynamicArray<ICollider*> d_colliders;
      // List of colliders


  public:

    // CONSTRUCTORS

    NxNSceneGraph() = delete;
      // Default constructor

    NxNSceneGraph( float dimensions, int divisions );
      // Constructor with dimensions which represents the width / height (this
      // scene being a square, width and height are the same) and the
      // divisions, which is the number of cells per column and row.

    NxNSceneGraph( const NxNSceneGraph& copy );
      // Copy constructor

    NxNSceneGraph( NxNSceneGraph&& move );
      // Move constructor


    // DESTRUCTOR

    virtual ~NxNSceneGraph();
      // Destructor


    // OPERATORS

    NxNSceneGraph&                  operator=( const NxNSceneGraph& copy );
      // Copy assignment operator

    NxNSceneGraph&                  operator=( NxNSceneGraph&& move );
      // Move assignment operator


    // ACCESSORS

    float                           dimensions();
      // Return the dimensions of the NxN scene

    int                             divisions();
      // Return the divisions of the NxN scene

    sgdc::DynamicArray<ICollider*>  colliders();
      // Return the list of colliders


    // MEMBER FUNCTIONS

    void                            addCollider( ICollider* collider );
      // Add a collider to the list

    void                            removeCollider( ICollider* collider );
      // Remove a collider from the list

    sgdc::DynamicArray<ICollider*>  find( float x, float y, float w, float h );
      // Find all colliders that collide with the given rectangle

    sgdc::DynamicArray<ICollider*>  find( float x, float y, float w, float h,
                                          unsigned short flags );
      // Find all colliders that collide with the given rectangle and flags

    sgdc::DynamicArray<ICollider*>  find( const RectangleBounds& bounds );
      // Find all colliders that collide with the given rectangle

    sgdc::DynamicArray<ICollider*>  find( const RectangleBounds& bounds,
                                          unsigned short flags );
      // Find all colliders that collide with the given rectangle and flags

    sgdc::DynamicArray<ICollider*>  find( const ICollider* collider );
      // Find all colliders that collide with this collider (except this one)

    void                            preTick();
      // Pre tick which represents the initialization phase

    void                            tick( float dts );
      // Physical work of the frame

    void                            postTick();
      // The post tick represents the clean-up phase
};

} // end sgds namespace
} // end StevensDev namespace

#endif // NxnSceneGraph

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
      // 

    int                     d_divisions;
      // 

    sgdc::DynamicArray<ICollider*> d_colliders;
      //


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
      //

    int                             divisions();
      //

    sgdc::DynamicArray<ICollider*>  colliders();
      //


    // MEMBER FUNCTIONS

    void                            addCollider( ICollider* collider );
      //

    void                            removeCollider( ICollider* collider );
      //

    sgdc::DynamicArray<ICollider*>  find( float x, float y, float w, float h );
      //

    sgdc::DynamicArray<ICollider*>  find( float x, float y, float w, float h,
                                          unsigned short flags );
      //

    sgdc::DynamicArray<ICollider*>  find( const RectangleBounds& bounds );
      //

    sgdc::DynamicArray<ICollider*>  find( const RectangleBounds& bounds,
                                          unsigned short flags );
      //

    sgdc::DynamicArray<ICollider*>  find( const ICollider* collider );
      // 

    void                            preTick();
      // 

    void                            tick( float dts );
      // Physical work of the frame

    void                            postTick();
      // The post tick represents the clean-up phase
};

} // end sgds namespace
} // end StevensDev namespace

#endif // NxnSceneGraph

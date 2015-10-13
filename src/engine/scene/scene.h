// scene.h

#ifndef INCLUDED_SCENE
# define INCLUDED_SCENE

#include <ctime>
#include "containers/dynamic_array.h"
#include "rendering/renderer.h"
#include "itickable.h"

namespace StevensDev
{
namespace sgds
{

class Scene
{
  private:

    static Scene                    *d_instance;
      // Static unique instance of Scene

    sgdr::Renderer                  *d_renderer;
      // Renderer

    time_t                           d_time;
      // Keep track of the last tick time

    sgdc::DynamicArray<ITickable*>   d_tickables;
      // Array of tickable objects


    // CONSTRUCTOR

    Scene();
      // Default constructor


  public:

    // ACCESSOR

    static Scene&                    inst();


    // MUTATORS

    void                             setRenderer( sgdr::Renderer *renderer );
      // 


    // MEMBER FUNCTIONS

    void                             tick();
      //

    void                             addTickable( ITickable *tickable );
      // 

    void                             removeTickable( ITickable *tickable );
      //
};

} // End sgds namespace
} // End StevensDev namespace

#endif // INCLUDED_SCENE

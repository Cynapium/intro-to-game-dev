//
// File: scene.h
// Author: Barbara Crepeau
//
// Declare Scene singleton class
//

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

// Manage the lifecycle of objects in the world, and the dissemination of ticks
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

    static Scene& inst();
      // Return the static instance of Scene


    // MUTATORS

    void setRenderer( sgdr::Renderer *renderer );
      // Set the renderer


    // MEMBER FUNCTIONS

    void tick();
      // Execute the pre-ticks, ticks and post-ticks of all ITickable

    void addTickable( ITickable *tickable );
      // Add an ITickable element

    void removeTickable( ITickable *tickable );
      // Remove an ITickable element
};

} // End sgds namespace
} // End StevensDev namespace

#endif // INCLUDED_SCENE

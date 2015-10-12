#ifndef INCLUDED_ITICKABLE
# define INCLUDED_ITICKABLE

namespace StevensDev
{
namespace sgds
{

class ITickable
{
  private:


  public:

    virtual void            preTick() = 0;
      // Used for caching, pre-conditions, additions,...

    virtual void            tick( float dts ) = 0;
      // Physical work of the frame

    virtual void            postTick() = 0;
      // The post tick represents the clean-up phase
};

} // End sgds namespace
} // End StevensDev namespace

#endif // INCLUDED_ITICKABLE

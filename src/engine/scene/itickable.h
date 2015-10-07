#ifndef INCLUDED_ITICKABLE
# define INCLUDED_ITICKABLE

namespace Stevens Dev
{
namespace sgds
{

class ITickable
{
  private:


  public:

    void                    preTick() = 0;
      // Used for caching, pre-conditions, additions,...

    void                    tick( float dts ) = 0;
      // Physical work of the frame

    void                    postTick() = 0;
      // The post tick represents the clean-up phase
};

} // End sgds namespace
} // End StevensDev namespace

#endif // INCLUDED_ITICKABLE

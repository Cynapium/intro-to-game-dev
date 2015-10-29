// ievent.h

#ifndef INCLUDED_IEVENT
# define INCLUDED_IEVENT

#include <string>

namespace StevensDev
{
namespace sgde
{

class IEvent
{
  private:

    std::string             d_type;
      // Infos about the event


  public:

    // CONSTRUCTORS

    IEvent( std::string type );
      // Default constructor


    // ACCESSORS

    std::string             type();
      // Return information about the event
};

} // end sgde namespace
} // end StevensDev namespace

#endif // IEvent

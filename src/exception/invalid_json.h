// invalid_json.h

#ifndef INCLUDED_INVALID_JSON
# define INCLUDED_INVALID_JSON

#include <exception>
#include <string>

namespace StevensDev
{

class InvalidJsonException : public std::exception
{
  private:

    const char*                     d_msg;


  public:

    InvalidJsonException ( std::string type, const std::string msg );
    InvalidJsonException ( const std::string msg, const char token );

    const char*                     what() const throw();

    void                            print();
};

} // End StevensDev namespace

#endif // INCLUDED_INVALID_JSON

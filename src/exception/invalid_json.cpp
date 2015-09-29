// invalid_json.cpp

#include "invalid_json.h"
#include <iostream>

namespace StevensDev
{

InvalidJsonException::InvalidJsonException( std::string       type,
                                            const std::string msg )
{
    std::string     str( msg );
    str += " ; Expected";
    str += type;

    d_msg = str.c_str();
}

InvalidJsonException::InvalidJsonException( const std::string msg,
                                            const char token )
{
    std::string     str( msg );
    str += ": ";
    str += token;

    d_msg = str.c_str();
}

const char*
InvalidJsonException::what() const throw()
{
    return d_msg;
}

void
InvalidJsonException::print()
{
    std::cerr << "InvalidJsonException: " << d_msg << std::endl;
}

} // End StevensDev namespace

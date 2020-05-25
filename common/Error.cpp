// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Error.hpp"
#include "Utils.hpp"  // utils::toString.

#include <sstream>


namespace pdl::common {
namespace error {
namespace {

// TODO: Migrate to std::format in C++20.
std::string createDescription (Module module, Code code, const Message& message, const Where& where)
{
    std::ostringstream out;
    out << where.file_name() << '.'
        << where.function_name() << ':'
        << where.line() << ": ("
        << utils::toString(module) << '.'
        << utils::toString(code) << ") - "
        << message << '.';
    return out.str();
}

}


// Constructor that specifies PDL Framework based exception.
Exception::Exception (Module module, Code code, const Message& message, const Where& where) :
    std::runtime_error{createDescription(module, code, message, where)}
{ }

// Operator that outputs exception information to stream.
std::ostream& operator<< (std::ostream& os, const Exception& exception)
{
    os << exception.what();
    return os;
}

}


// Function that throws the specified error::Exception.
void panic (Module module, Code code, const Message& message, Where where)
{
    throw error::Exception {module, code, message, where};
}

}

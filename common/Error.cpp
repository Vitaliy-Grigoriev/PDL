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
std::string createDescription (Module module, Code code, Message message, Where where)
{
    std::ostringstream out;
    out << where.file_name() << '.'
        << where.function_name() << ':'
        << where.line() << ": ("
        << utils::toString(module) << '.'
        << utils::toString(code) << ") - "
        << std::move(message) << '.';
    return out.str();
}

}


// Constructor that specifies PDL Framework based exception.
Exception::Exception (Module module, Code code, Message message, Where where) :
    std::runtime_error{createDescription(module, code, std::move(message), std::move(where))}
{ }

// Operator that outputs exception information to stream.
std::ostream& operator<< (std::ostream& out, const Exception& error)
{
    out << error.what();
    return out;
}

}


// Function that throws the specified error::Exception.
void panic (Module module, Code code, Message message, Where where)
{
    throw error::Exception {module, code, std::move(message), std::move(where)};
}

}

// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Error.hpp"
#include "Utils.hpp"

#include <sstream>


namespace pdl::common::error {
namespace {

// TODO: Migrate to std::format in C++20.
std::string createDescription(Module _module, Code _code, const Message& _message, const Where& _where)
{
    std::ostringstream out;

    out << _where.file_name() << '.'
        << _where.function_name() << ':'
        << _where.line() << ": ("
        << toString(_module) << '.'
        << toString(_code) << ") - "
        << _message << '.';

    return out.str();
}

}


// Constructor that specifies PDL Framework based exception.
Exception::Exception(Module _module, Code _code, const Message& _message, const Where& _where) :
    std::runtime_error{ createDescription(_module, _code, _message, _where) }
{ }

// Operator that outputs exception information to stream.
std::ostream& operator<<(std::ostream& _os, const Exception& _exception)
{
    _os << _exception.what();
    return _os;
}


// Function that throws the specified Exception.
void panic(Module _module, Code _code, const Message& _message, Where _where)
{
    throw Exception{ _module, _code, _message, _where };
}

}  // namespace error.

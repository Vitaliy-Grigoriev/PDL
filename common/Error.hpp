// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <iosfwd>
#include <ostream>
#include <stdexcept>
#include <experimental/source_location>


namespace pdl::common {

enum class Module {
    system = 0,
    framework,
    memory,
    raw_data,
    field,
    subfield,
    header
};

enum class Code {
    system_error = 0,
    internal_error,
    not_implemented,
    zero_memory_allocation,
    index_out_of_range,
    object_not_found
};

using Message = std::string;
using Where   = std::experimental::source_location;


namespace error {

/**
 * @class Exception   Error.hpp   "common/Error.hpp"
 * @brief This class implements error exception of PdlFramework.
 */
class Exception final : public std::runtime_error
{
public:
    /**
     * @brief Constructor that specifies PDL Framework based exception.
     *
     * @param [in] _module  - Module in which exception occurred.
     * @param [in] _code    - Code that indicates the type of exception.
     * @param [in] _message - Message that describes exception.
     * @param [in] _where   - Place in code where exception occurred.
     */
    Exception (Module _module, Code _code, const Message & _message, const Where & _where = Where::current());

    /**
     * @brief Operator that outputs exception information to stream.
     *
     * @param [in,out] _os        - Reference of out stream.
     * @param [in]     _exception - Reference of Exception class.
     * @return Lvalue reference of out stream.
     */
    friend std::ostream & operator<< (std::ostream & _os, const Exception & _exception);

};

}  // namespace error.

/**
 * @brief Function that throws the specified error::Exception.
 *
 * @param [in] _module  - Module in which exception occurred.
 * @param [in] _code    - Code that indicates the type of exception.
 * @param [in] _message - Message that describes exception.
 * @param [in] _where   - Location in source code where exception occurred.
 *
 * @throw error::Exception - PDL Framework based exception.
 */
[[noreturn]]
void panic (Module _module, Code _code, const Message & _message, Where _where = Where::current());

}  // namespace common.

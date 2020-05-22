// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <iosfwd>
#include <stdexcept>
#include <experimental/source_location>


namespace pdl::common {

enum class Module {
    system = 0,
    framework,
    memory,
    binary_data
};

enum class Code {
    system_error = 0,
    internal_error,
    not_implemented,
    zero_memory_allocation
};

using Message = std::string;
using Where   = std::experimental::source_location;


namespace error {

class Exception final : public std::runtime_error
{
public:
    /**
     * @brief Constructor that specifies PDL Framework based exception.
     *
     * @param [in] module  - Module in which exception occurred.
     * @param [in] code    - Code that indicates the type of exception.
     * @param [in] message - Message that describes exception.
     * @param [in] where   - Place in code where exception occurred.
     */
    Exception (Module module, Code code, Message message, Where where = Where::current());
};

/**
 * @brief Operator that outputs exception information to stream.
 *
 * @param [in,out] out   - Reference of out stream.
 * @param [in]     error - Constant lvalue reference of Error class.
 * @return Lvalue reference of out stream.
 */
std::ostream & operator<< (std::ostream & out, const Exception & error);

}  // namespace error.

/**
 * @brief Function that throws the specified error::Exception.
 *
 * @param [in] module  - Module in which exception occurred.
 * @param [in] code    - Code that indicates the type of exception.
 * @param [in] message - Message that describes exception.
 * @param [in] where   - Place in code where exception occurred.
 *
 * @throw error::Exception - PDL Framework based exception.
 */
void panic (Module module, Code code, Message message, Where where = Where::current());

}  // namespace common.

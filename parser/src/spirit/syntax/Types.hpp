#pragma once

#include <string>
#include <cstdint>


namespace pdl::spirit::syntax::types
{
    enum class VariableScope : uint16_t {
        LOCAL = 0,
        GLOBAL
    };

    enum class InternalVariableType : uint16_t {
        BIT = 0,
        BOOLEAN,
        BYTE,
        INT8,
        INT16,
        INT32,
        INT64,
        UINT8,
        UINT16,
        UINT32,
        UINT64,
        FLOAT,
        MAC,
        IPv4,
        IPv6,
        STRING
    };

    enum class EndianType : uint16_t {
        BIG = 0,
        LITTLE
    };

}  // namespace types.

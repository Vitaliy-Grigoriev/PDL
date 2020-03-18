#pragma once

#include <string>
#include <cstdint>


namespace pdl::detail::syntax
{
    enum class VariableType : uint16_t {
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
        IPv6
    };

    enum class EndianType : uint16_t {
        BIG = 0,
        LITTLE
    };

}  // namespace syntax.

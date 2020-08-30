#pragma once

#include <string>
#include <cstdint>


namespace pdl::spirit::syntax::types {

enum class VariableScope : uint16_t {
    Local = 0,
    Global
};

enum class InternalVariableType : uint16_t {
    Bit = 0,
    Boolean,
    Byte,
    Int8,
    Int16,
    Int32,
    Int64,
    UInt8,
    UInt16,
    UInt32,
    UInt64,
    Float32,
    Float64,
    Mac,
    IPv4,
    IPv6
};

enum class EndianType : uint16_t {
    Big = 0,
    Little
};

enum class InternalDefines : uint16_t {
    LocalMacAddress = 0,
    TargetMacAddress,
    LocalIpAddress,
    TargetIpAddress
};

enum class OptionalGroupType : uint16_t {
    Single = 0,
    Multi
};

}  // namespace types.

// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Utils.hpp"

#include <core/error/Error.hpp>

#include <sstream>


namespace pdl::core::endian {

std::string toString(const Endian _endian)
{
    switch (_endian) {
    case Endian::big:
        return "BigEndian";
    case Endian::middle_big:
        return "MiddleBigEndian";
    case Endian::middle_little:
        return "MiddleLittleEndian";
    case Endian::little:
        return "LittleEndian";
    case Endian::reverse_little:
        return "ReverseLittleEndian";
    case Endian::reverse_middle_big:
        return "ReverseMiddleBigEndian";
    case Endian::reverse_big:
        return "ReverseBigEndian";
    case Endian::reverse_middle_little:
        return "ReverseMiddleLittleEndian";
    case Endian::system:
        return toString(getSystemEndian());
    default:
        std::ostringstream str;
        str << "Endian '" << std::to_string(static_cast<uint32_t>(_endian)) << "' not found";
        panic(error::Module::Framework, error::Code::InternalError, str.str());
    }
}

}  // namespace endian.

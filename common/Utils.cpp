#include "Utils.hpp"

#include <sstream>


namespace pdl::common::utils {

std::string toString (const Module module)
{
    switch (module) {
    case Module::system:
        return "System";
    case Module::framework:
        return "Framework";
    case Module::memory:
        return "Memory";
    case Module::raw_data:
        return "RawData";
    case Module::field:
        return "Field";
    case Module::subfield:
        return "Subfield";
    case Module::header:
        return "Header";
    default:
        std::ostringstream str;
        str << "Module '" << std::to_string(static_cast<uint32_t>(module)) << "' not found";
        panic(Module::framework, Code::internal_error, str.str());
    }
}

std::string toString (const Code code)
{
    switch (code) {
    case Code::system_error:
        return "SystemError";
    case Code::internal_error:
        return "InternalError";
    case Code::not_implemented:
        return "NotImplemented";
    case Code::zero_memory_allocation:
        return "ZeroMemoryAllocation";
    case Code::index_out_of_range:
        return "IndexOutOfRange";
    case Code::object_not_found:
        return "ObjectNotFound";
    default:
        std::ostringstream str;
        str << "Code '" << std::to_string(static_cast<uint32_t>(code)) << "' not found";
        panic(Module::framework, Code::internal_error, str.str());
    }
}

std::string toString (const data::endian::Endian endian)
{
    switch (endian) {
    case data::endian::Endian::big:
        return "BigEndian";
    case data::endian::Endian::middle_big:
        return "MiddleBigEndian";
    case data::endian::Endian::middle_little:
        return "MiddleLittleEndian";
    case data::endian::Endian::little:
        return "LittleEndian";
    case data::endian::Endian::reverse_little:
        return "ReverseLittleEndian";
    case data::endian::Endian::reverse_middle_big:
        return "ReverseMiddleBigEndian";
    case data::endian::Endian::reverse_big:
        return "ReverseBigEndian";
    case data::endian::Endian::reverse_middle_little:
        return "ReverseMiddleLittleEndian";
    case data::endian::Endian::system:
        return toString(data::endian::getSystemEndian());
    default:
        std::ostringstream str;
        str << "Endian '" << std::to_string(static_cast<uint32_t>(endian)) << "' not found";
        panic(Module::framework, Code::internal_error, str.str());
    }
}

}  // namespace utils.

#include "Utils.hpp"

#include <sstream>


namespace pdl::common::utils {

std::string toString (const Module _module)
{
    switch (_module) {
    case Module::System:
        return "System";
    case Module::Framework:
        return "Framework";
    case Module::Memory:
        return "Memory";
    case Module::RawData:
        return "RawData";
    case Module::Field:
        return "Field";
    case Module::Subfield:
        return "Subfield";
    case Module::Header:
        return "Header";
    default:
        std::ostringstream str;
        str << "Module '" << std::to_string(static_cast<uint32_t>(_module)) << "' not found";
        panic(Module::Framework, Code::InternalError, str.str());
    }
}

std::string toString (const Code _code)
{
    switch (_code) {
    case Code::SystemError:
        return "SystemError";
    case Code::InternalError:
        return "InternalError";
    case Code::NotImplemented:
        return "NotImplemented";
    case Code::ZeroMemoryAllocation:
        return "ZeroMemoryAllocation";
    case Code::IndexOutOfRange:
        return "IndexOutOfRange";
    case Code::ObjectNotFound:
        return "ObjectNotFound";
    default:
        std::ostringstream str;
        str << "Code '" << std::to_string(static_cast<uint32_t>(_code)) << "' not found";
        panic(Module::Framework, Code::InternalError, str.str());
    }
}

std::string toString (const data::endian::Endian _endian)
{
    switch (_endian) {
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
        str << "Endian '" << std::to_string(static_cast<uint32_t>(_endian)) << "' not found";
        panic(Module::Framework, Code::InternalError, str.str());
    }
}

}  // namespace utils.

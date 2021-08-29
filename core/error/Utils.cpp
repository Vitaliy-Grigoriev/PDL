// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Utils.hpp"

#include <sstream>


namespace pdl::core::error {

std::string toString(const Module _module)
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

std::string toString(const Code _code)
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
    case Code::InvalidInputData:
        return "InvalidInputData";
    default:
        std::ostringstream str;
        str << "Code '" << std::to_string(static_cast<uint32_t>(_code)) << "' not found";
        panic(Module::Framework, Code::InternalError, str.str());
    }
}

}  // namespace error.

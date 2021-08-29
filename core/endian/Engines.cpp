// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Engines.hpp"
#include "Utils.hpp"

#include <error/Error.hpp>

#include <sstream>

namespace pdl::core::endian {

EngineInterface::UniquePtr getEngine(const Endian _endian, data::RawData& _data)
{
    switch (_endian) {
    case Endian::big:
        return std::make_unique<BigEndianEngine>(_data);
    case Endian::little:
        return std::make_unique<LittleEndianEngine>(_data);
    default:
        std::ostringstream str;
        str << "Endian '" << toString(_endian) << "' not found";
        panic(error::Module::Framework, error::Code::InternalError, str.str());
    }
}

}  // namespace endian.

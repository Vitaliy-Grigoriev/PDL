// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Converter.hpp"
#include "Engines.hpp"
#include "Utils.hpp"

#include <core/error/Error.hpp>

#include <sstream>


namespace pdl::core::endian {
namespace detail {

void littleBigConverter(data::RawData& _data) noexcept
{
    const std::size_t size = _data.size();

    for (std::size_t idx = 0; idx < size / 2; ++idx) {
        std::swap(*_data.get(idx), *_data.get(size - idx - 1));
    }
}

}

namespace {

void convertFromBigEndian(data::RawData& _data, const Endian _endian)
{
    switch (_endian) {
    case Endian::big:
        break;
    case Endian::little:
        detail::littleBigConverter(_data);
        break;
    default:
        std::ostringstream str;
        str << "Endian '" << toString(_endian) << "' not found";
        panic(error::Module::Framework, error::Code::InternalError, str.str());
    }
}

void convertFromLittleEndian(data::RawData& _data, const Endian _endian)
{
    switch (_endian) {
    case Endian::big:
        detail::littleBigConverter(_data);
        break;
    case Endian::little:
        break;
    default:
        std::ostringstream str;
        str << "Endian '" << toString(_endian) << "' not found";
        panic(error::Module::Framework, error::Code::InternalError, str.str());
    }
}

}

// Constructor of Converter class.
Converter::Converter(EngineInterface& _engine) noexcept :
    Declaration{ this },
    engine{ _engine }
{
}

EngineInterface::UniquePtr Converter::convert(const Endian _endian) const noexcept
{
    switch (engine.getEndianType()) {
    case Endian::big:
        convertFromBigEndian(engine.getData(), _endian);
        break;
    case Endian::little:
        convertFromLittleEndian(engine.getData(), _endian);
        break;
    default:
        std::ostringstream str;
        str << "Endian '" << toString(_endian) << "' not found";
        panic(error::Module::Framework, error::Code::InternalError, str.str());
    }

    return getEngine(_endian, engine.getData());
}

}  // namespace endian.

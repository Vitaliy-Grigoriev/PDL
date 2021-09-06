// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "BigEndianEngine.hpp"
#include "core/endian/Converter.hpp"
#include "impl/BigEndianImpl.hpp"

#include <core/data/PredefinedBytes.hpp>


namespace pdl::core::endian {

BigEndianEngine::BigEndianEngine(data::RawData& _data) noexcept :
    EngineInterface{ Endian::big, _data }
{ }

data::RawData::Byte BigEndianEngine::get(const std::size_t _index) const
{
    return data[size() - _index - 1];
}

EngineInterface& BigEndianEngine::shiftLeft(const std::size_t _shift,
                                            std::optional<data::RawData::Byte> _fill) noexcept
{
    if (!data) {
        return *this;
    }

    if (_shift >= size()) {
        const data::RawData::Byte byte = _fill ? *_fill : data::LowByte;
        data.fill(byte);
    } else if (_shift != 0) {
        data::RawData::MemoryPointer begin = data.get();
        leftShiftBE(begin, begin + size(), _shift, _fill);
    }

    return *this;
}

EngineInterface& BigEndianEngine::shiftRight(const std::size_t _shift,
                                             std::optional<data::RawData::Byte> _fill) noexcept
{
    if (!data) {
        return *this;
    }

    if (_shift >= size()) {
        const data::RawData::Byte byte = _fill ? *_fill : data::LowByte;
        data.fill(byte);
    } else if (_shift != 0) {
        data::RawData::MemoryPointer begin = data.get();
        rightShiftBE(begin, begin + size(), _shift, _fill);
    }

    return *this;
}

EngineInterface& BigEndianEngine::rotateLeft(std::size_t _shift) noexcept
{
    if (_shift >= size()) {
        _shift %= size();
    }

    data::RawData::MemoryPointer begin = data.get();
    leftRotateBE(begin, begin + size(), _shift);

    return *this;
}

EngineInterface& BigEndianEngine::rotateRight(std::size_t _shift) noexcept
{
    if (_shift >= size()) {
        _shift %= size();
    }

    data::RawData::MemoryPointer begin = data.get();
    rightRotateBE(begin, begin + size(), _shift);

    return *this;
}

EngineInterface& BigEndianEngine::reverse() noexcept
{
    [[maybe_unused]]
    auto engine = convert(Endian::little);
    return *this;
}

EngineInterface::UniquePtr BigEndianEngine::convert(const Endian _endian) noexcept
{
    Converter converter{ *this };
    return converter.convert(_endian);
}

}  // namespace endian.

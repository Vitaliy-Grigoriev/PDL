// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "LittleEndianEngine.hpp"
#include "impl/LittleEndianImpl.hpp"

#include <core/data/PredefinedBytes.hpp>


namespace pdl::core::endian {

LittleEndianEngine::LittleEndianEngine(data::RawData& _data) noexcept :
    EngineInterface{ Endian::little, _data }
{ }

data::RawData::Byte LittleEndianEngine::get(const std::size_t _index) const
{
    return data[_index];
}

EngineInterface& LittleEndianEngine::shiftLeft(const std::size_t _shift,
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
        leftShiftLE(begin, begin + size(), _shift, _fill);
    }

    return *this;
}

EngineInterface& LittleEndianEngine::shiftRight(const std::size_t _shift,
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
        data::RawData::MemoryConstPointer end = begin + size();
        rightShiftLE(begin, end, _shift, _fill);
    }

    return *this;
}

EngineInterface& LittleEndianEngine::rotateLeft(std::size_t _shift) noexcept
{
    if (_shift >= size()) {
        _shift %= size();
    }

    data::RawData::MemoryPointer begin = data.get();
    leftRotateLE(begin, begin + size(), _shift);

    return *this;
}

EngineInterface& LittleEndianEngine::rotateRight(std::size_t _shift) noexcept
{
    if (_shift >= size()) {
        _shift %= size();
    }

    data::RawData::MemoryPointer begin = data.get();
    rightRotateLE(begin, begin + size(), _shift);

    return *this;
}

EngineInterface& LittleEndianEngine::reverse() noexcept
{
    return *this;
}

}  // namespace endian.

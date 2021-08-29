// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Common.hpp"

#include <data/PredefinedBytes.hpp>

#include <cstring>  // memset.


namespace pdl::core::endian {

// Function that performs left shift to the selected byte in big-endian format.
void leftShiftBE(data::RawData::MemoryPointer _begin,
                 data::RawData::MemoryConstPointer _end,
                 data::RawData::MemoryPointer _target,
                 std::optional<data::RawData::Byte> _fill) noexcept
{
    data::RawData::MemoryPointer next = _target;

    while (next != _end) {
        *_begin++ = *next++;
    }

    const data::RawData::Byte byte = _fill ? *_fill : data::LowByte;
    memset(_begin, static_cast<int32_t>(byte), static_cast<std::size_t>(_end - _begin));
}

// Function that performs right shift to selected byte in big-endian format.
void rightShiftBE(data::RawData::MemoryPointer _begin,
                  data::RawData::MemoryPointer _end,
                  data::RawData::MemoryConstPointer _target,
                  std::optional<data::RawData::Byte> _fill) noexcept
{
    data::RawData::MemoryConstPointer prev = _target;
    data::RawData::MemoryConstPointer rend = std::prev(_begin);

    while (prev != rend) {
        *(--_end) = *prev--;
    }

    const data::RawData::Byte byte = _fill ? *_fill : data::LowByte;
    memset(_begin, static_cast<int32_t>(byte), static_cast<std::size_t>(_end - prev - 1));
}

// Function that performs left rotate to the selected byte.
void leftRotateBE(data::RawData::MemoryPointer _begin,
                  data::RawData::MemoryConstPointer _end,
                  data::RawData::MemoryPointer _target) noexcept
{
    data::RawData::MemoryPointer next = _target;

    while (_begin != next) {
        std::swap(*_begin++, *next++);

        if (next == _end) {
            next = _target;
        } else if (_begin == _target) {
            _target = next;
        }
    }
}

// Function that performs right rotate to the selected byte.
void rightRotateBE(data::RawData::MemoryConstPointer _begin,
                   data::RawData::MemoryPointer _end,
                   data::RawData::MemoryPointer _target) noexcept
{
    data::RawData::MemoryPointer prev = _target;
    data::RawData::MemoryConstPointer rend = std::prev(_begin);

    while (_end != prev) {
        std::swap(*prev--, *(--_end));

        if (prev == rend) {
            prev = _target;
        } else if (_end == _target) {
            _target = prev;
        }
    }
}

}  // namespace endian.

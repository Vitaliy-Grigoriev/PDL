// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Common.hpp"


namespace pdl::common::endian {

// Function that performs left shift by a specified byte offset in little-endian format.
void leftShiftLE(data::RawData::MemoryPointer _begin,
                 data::RawData::MemoryPointer _end,
                 const std::size_t _shift,
                 std::optional<data::RawData::Byte> _fill) noexcept
{
    rightShiftBE(_begin, _end, _end - _shift - 1, _fill);
}

// Function that performs right shift by a specified byte offset in little-endian format.
void rightShiftLE(data::RawData::MemoryPointer _begin,
                  data::RawData::MemoryConstPointer _end,
                  const std::size_t _shift,
                  std::optional<data::RawData::Byte> _fill) noexcept
{
    leftShiftBE(_begin, _end, _begin + _shift, _fill);
}

// Function that performs left rotate by a specified byte offset in little-endian format.
void leftRotateLE(data::RawData::MemoryConstPointer _begin,
                  data::RawData::MemoryPointer _end,
                  const std::size_t _shift) noexcept
{
    rightRotateBE(_begin, _end, _end - _shift - 1);
}

// Function that performs right rotate by a specified byte offset in little-endian format.
void rightRotateLE(data::RawData::MemoryPointer _begin,
                   data::RawData::MemoryConstPointer _end,
                   const std::size_t _shift) noexcept
{
    leftRotateBE(_begin, _end, _begin + _shift);
}

}  // namespace endian.

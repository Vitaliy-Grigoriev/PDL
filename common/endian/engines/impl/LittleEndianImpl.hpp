// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <common/data/RawData.hpp>

#include <optional>


namespace pdl::common::endian {

/**
 * @brief Function that performs left shift by a specified byte offset in little-endian format.
 *
 * @param [in] _begin - Pointer to begin position in byte sequence.
 * @param [in] _end   - Pointer to end position in byte sequence (the element following the last one).
 * @param [in] _shift - Byte offset for left shift.
 * @param [in] _fill  - New value of byte after left shift.
 */
void leftShiftLE(data::RawData::MemoryPointer _begin,
                 data::RawData::MemoryPointer _end,
                 size_t _shift,
                 std::optional<data::RawData::Byte> _fill) noexcept;

/**
 * @brief Function that performs right shift by a specified byte offset in little-endian format.
 *
 * @param [in] _begin - Pointer to begin position of the byte sequence.
 * @param [in] _end   - Pointer to end position of the byte sequence (the element following the last one).
 * @param [in] _shift - Byte offset for right shift.
 * @param [in] _fill  - New value of byte after right shift.
 */
void rightShiftLE(data::RawData::MemoryPointer _begin,
                  data::RawData::MemoryConstPointer _end,
                  size_t _shift,
                  std::optional<data::RawData::Byte> _fill) noexcept;

/**
 * @brief Function that performs left rotate by a specified byte offset in little-endian format.
 *
 * @param [in] _begin - Pointer to begin position in byte sequence.
 * @param [in] _end   - Pointer to end position in byte sequence (the element following the last one).
 * @param [in] _shift - Byte offset for left rotate.
 */
void leftRotateLE(data::RawData::MemoryConstPointer _begin,
                  data::RawData::MemoryPointer _end,
                  std::size_t _shift) noexcept;

/**
 * @brief Function that performs right rotate by a specified byte offset in little-endian format.
 *
 * @param [in] _begin - Pointer to begin position in byte sequence.
 * @param [in] _end   - Pointer to end position in byte sequence (the element following the last one).
 * @param [in] _shift - Byte offset for right rotate.
 */
void rightRotateLE(data::RawData::MemoryPointer _begin,
                   data::RawData::MemoryConstPointer _end,
                   std::size_t _shift) noexcept;

}  // namespace endian.

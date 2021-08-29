// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <common/data/RawData.hpp>

#include <optional>


namespace pdl::common::endian {

/**
 * @brief Function that performs left shift to the selected byte in big-endian format.
 *
 * @param [in] _begin  - Pointer to begin position in byte sequence.
 * @param [in] _end    - Pointer to end position in byte sequence (the element following the last one).
 * @param [in] _target - Pointer to byte to which left shift is performed.
 * @param [in] _fill   - New value of byte after left shift.
 */
void leftShiftBE(data::RawData::MemoryPointer _begin,
                 data::RawData::MemoryConstPointer _end,
                 data::RawData::MemoryPointer _target,
                 std::optional<data::RawData::Byte> _fill) noexcept;

/**
 * @brief Function that performs right shift to selected byte in big-endian format.
 *
 * @param [in] _begin  - Pointer to start position in byte sequence.
 * @param [in] _end    - Pointer to end position in byte sequence (the element following the last one).
 * @param [in] _target - Pointer to byte to which right shift is performed.
 * @param [in] _fill   - New value of byte after right shift.
 */
void rightShiftBE(data::RawData::MemoryPointer _begin,
                  data::RawData::MemoryPointer _end,
                  data::RawData::MemoryConstPointer _target,
                  std::optional<data::RawData::Byte> _fill) noexcept;

/**
 * @brief Function that performs left rotate to the selected byte.
 *
 * @param [in] _begin  - Pointer to begin position in byte sequence.
 * @param [in] _end    - Pointer to end position in byte sequence (the element following the last one).
 * @param [in] _target - Pointer to byte to which left rotate is performed.
*/
void leftRotateBE(data::RawData::MemoryPointer _begin,
                  data::RawData::MemoryConstPointer _end,
                  data::RawData::MemoryPointer _target) noexcept;

/**
 * @brief Function that performs right rotate to the selected byte.
 *
 * @param [in] _begin  - Pointer to begin position in byte sequence.
 * @param [in] _end    - Pointer to end position in byte sequence (the element following the last one).
 * @param [in] _target - Pointer to byte to which right rotate is performed.
 */
void rightRotateBE(data::RawData::MemoryConstPointer _begin,
                   data::RawData::MemoryPointer _end,
                   data::RawData::MemoryPointer _target) noexcept;

}  // namespace endian.

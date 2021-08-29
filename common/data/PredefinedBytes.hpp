// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <cstddef>


namespace pdl::common::data {

/**
 * @defgroup BYTE_CONSTANTS   Byte defines.
 * @brief This group of constants defines all bytes which are used in BinaryDataEngine class.
 * @{
 */
inline constexpr std::byte HighByte = std::byte(0xFF);
inline constexpr std::byte LowByte = std::byte(0x00);

inline constexpr std::byte HighPartByte = std::byte(0xF0);
inline constexpr std::byte LowPartByte = std::byte(0x0F);

inline constexpr std::byte HighAlternateByte = std::byte(0xAA);
inline constexpr std::byte LowAlternateByte = std::byte(0x55);

inline constexpr std::byte HighBitsInHalvesByte = std::byte(0xCC);
inline constexpr std::byte LowBitsInHalvesByte = std::byte(0x33);

inline constexpr std::byte HighBitInByte = std::byte(0x80);
inline constexpr std::byte LowBitInByte = std::byte(0x01);
/** @} */

}  // namespace data.

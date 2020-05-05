// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

// ////////////// DATA ENDIAN TYPE ////////////////
//
//  Little Endian Model.
//  |7______0|15______8|23______16|31______24|
//
//  Big Endian Model.
//  |31______24|23______16|15______8|7______0|
//
//  Reverse Big Endian Model.
//  |24______31|16______23|8______15|0______7|
//
//  Endian Independent Model.
//  |0______7|8______15|16______23|24______31|
//
//
//  Another endian models (not supported).
//
//  Middle Endian Big Model. (PDP-11)
//  |23______16|31______24|7______0|15______8|
//
//  Middle Endian Little Model. (Honeywell 316)
//  |15______8|7______0|31______24|23______16|
//
// ////////////////////////////////////////////////


namespace pdl::common::data
{

/**
 * @defgroup BYTE_CONSTANTS   Byte defines.
 * @brief This group of constants defines all bytes which are used in BinaryData class.
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

/**
 * @enum DATA_ENDIAN_TYPE
 * @brief Endian type of data in BinaryData class.
 *
 * @note Default initial type of internal data in BinaryDataEngine class the same as system type.
 */
enum class DATA_ENDIAN_TYPE
{
    DATA_BIG_ENDIAN         = 0x01,  // First byte of the multibyte data-type is stored first.
    DATA_LITTLE_ENDIAN      = 0x02,  // Last byte of the multibyte data-type is stored first.
    DATA_REVERSE_BIG_ENDIAN = 0x03,  // First byte of the multibyte data-type is stored first in reverse bit sequence.
    DATA_SYSTEM_ENDIAN      = 0xFE,  // This endian type determine the system endian type and using only in constructors.
    DATA_NO_ENDIAN          = 0xFF   // This endian type means that endian value does not set.
};



}  // namespace data.

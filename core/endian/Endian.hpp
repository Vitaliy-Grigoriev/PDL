// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

// /////////////// ENDIAN TYPES /////////////////
//
//  Little Endian Model.
//  |7______0|15______8|23______16|31______24|
//
//  Big Endian Model.
//  |31______24|23______16|15______8|7______0|
//
//  Middle Endian Big Model. (PDP-11)
//  |23______16|31______24|7______0|15______8|
//
//  Middle Endian Little Model. (Honeywell 316)
//  |15______8|7______0|31______24|23______16|
//
//
//  Reverse Big Endian Model.
//  |24______31|16______23|8______15|0______7|
//
//  Reverse Little (Independent) Endian Model.
//  |0______7|8______15|16______23|24______31|
//
//  Reverse Middle Endian Big Model.
//  |16______23|24______31|0______7|8______15|
//
//  Reverse Middle Endian Little Model.
//  |8______15|0______7|24______31|16______23|
//
// //////////////////////////////////////////////

#include <cstdint>  // std::uint16_t.


namespace pdl::core::endian {

/**
 * @enum Endian
 * @brief Endian types.
 */
enum class Endian : uint16_t {
    big                   = 0x01,  // First byte of the 32-bit data type is stored first.
    middle_big            = 0x02,  // Second byte of the 32-bit data type is stored first.
    middle_little         = 0x03,  // Third byte of the 32-bit data type is stored first.
    little                = 0x04,  // Last byte of the 32-bit data type is stored first.
    reverse_little        = 0x20,  // Last byte of the 32-bit data type is stored first with reverse bit sequence.
    reverse_middle_big    = 0x40,  // Second byte of the 32-bit data type is stored first with reverse bit sequence.
    reverse_big           = 0x80,  // First byte of the 32-bit data type is stored first with reverse bit sequence.
    reverse_middle_little = 0xC0,  // Third byte of the 32-bit data type is stored first with reverse bit sequence.
    independent           = reverse_little,
    system                = 0xFF   // System endian type.
};

}  // namespace endian.

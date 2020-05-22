// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Endian.hpp"


namespace pdl::common::data::endian
{

std::byte reverseBits(std::byte byte) noexcept
{
    byte = (byte & std::byte(0xF0)) >> 4U | (byte & std::byte(0x0F)) << 4U;
    byte = (byte & std::byte(0xCC)) >> 2U | (byte & std::byte(0x33)) << 2U;
    byte = (byte & std::byte(0xAA)) >> 1U | (byte & std::byte(0x55)) << 1U;
    return byte;
}

}  // namespace endian.


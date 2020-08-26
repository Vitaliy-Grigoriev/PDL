// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Endian.hpp"


namespace pdl::common::data::endian {

std::byte reverseBits (std::byte _byte) noexcept
{
    _byte = (_byte & std::byte(0xF0)) >> 4U | (_byte & std::byte(0x0F)) << 4U;
    _byte = (_byte & std::byte(0xCC)) >> 2U | (_byte & std::byte(0x33)) << 2U;
    _byte = (_byte & std::byte(0xAA)) >> 1U | (_byte & std::byte(0x55)) << 1U;
    return _byte;
}

}  // namespace endian.

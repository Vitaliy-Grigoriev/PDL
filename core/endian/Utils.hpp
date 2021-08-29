// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Endian.hpp"

#include <string>


namespace pdl::core::endian {

/**
 * @brief Function that calculates system endian type.
 * @return System endian type.
 */
constexpr inline Endian getSystemEndian() noexcept
{
    constexpr uint32_t value = 0x01020304;
    return static_cast<Endian>(static_cast<const uint8_t &>(value));
}

/**
 * @brief Function that returns endian name in string representation.
 * @param [in] _endian - EngineInterface's endian type.
 * @return Endian name in string representation.
 */
std::string toString(Endian _endian);

}  // namespace endian.

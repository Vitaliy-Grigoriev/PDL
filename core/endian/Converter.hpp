// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Engines.hpp"

#include <core/Declaration.hpp>


namespace pdl::core::endian {

/**
 * @class Converter   Converter.hpp   "core/endian/Converter.hpp"
 * @brief Class needs to convert RawData presents in one endian to selected Endian type.
 */
class Converter final : public Declaration<Converter>
{
public:
    /**
     * @brief Constructor of Converter class.
     * @param [in] _engine - Reference to current engine.
     */
    explicit Converter(EngineInterface & _engine) noexcept;

    /**
     * @brief Method that converts data to selected endian type.
     * @param [in] _endian - EngineInterface's endian type.
     * @return Pointer to EngineInterface class with selected endian type.
     */
    EngineInterface::UniquePtr convert(Endian _endian) const noexcept;

private:
    EngineInterface & engine;
};


/**
 * @brief Function that reverses bits in byte.
 * @param [in] _byte - inputted byte.
 * @return Byte with reverse bits.
 *
 * Example: 10100011  ->  11000101.
 */
std::byte reverseBits(std::byte _byte) noexcept;

}  // namespace endian.

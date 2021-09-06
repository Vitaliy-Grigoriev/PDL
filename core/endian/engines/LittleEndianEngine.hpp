// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "core/endian/EngineInterface.hpp"


namespace pdl::core::endian {

/**
 * @class LittleEndianEngine   LittleEndianEngine.hpp   "core/endian/engines/LittleEndianEngine.hpp"
 * @brief Derived class for work with data using Little Endian Engine.
 */
class LittleEndianEngine final : public EngineInterface
{
public:
    /**
     * @brief Constructor of LittleEndianEngine derived class.
     * @param [in] _data - Reference to data.
     */
    explicit LittleEndianEngine(data::RawData & _data) noexcept;

    data::RawData::Byte get(std::size_t _index) const override;

    EngineInterface & shiftLeft(std::size_t _shift,
                                std::optional<data::RawData::Byte> _fill) noexcept override;
    EngineInterface & shiftRight(std::size_t _shift,
                                 std::optional<data::RawData::Byte> _fill) noexcept override;

    EngineInterface & rotateLeft(std::size_t _shift) noexcept override;
    EngineInterface & rotateRight(std::size_t _shift) noexcept override;

    EngineInterface & reverse() noexcept override;

    EngineInterface::UniquePtr convert(Endian _endian) noexcept override;
};

}  // namespace endian.

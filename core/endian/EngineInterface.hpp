// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Endian.hpp"

#include <core/Declaration.hpp>
#include <core/data/RawData.hpp>

#include <optional>


namespace pdl::core::endian {

/**
 * @class EngineInterface   EngineInterface.hpp   "core/endian/EngineInterface.hpp"
 * @brief Base interface for work with data by selected Endian type.
 */
class EngineInterface : public Declaration<EngineInterface>
{
public:
    /**
     * @brief Constructor of EngineInterface interface class.
     * @param [in] _endian - EngineInterface's endian type.
     * @param [in] _data - Reference to data.
     */
    EngineInterface(Endian _endian, data::RawData & _data);

    /**
     * @brief Method that returns current endian type.
     * @return Current endian type.
     */
    Endian getEndianType() const noexcept;

    /**
     * @brief Method that returns length of data in bytes.
     * @return Length of data in bytes.
     */
    std::size_t size() const noexcept;

    /**
     * @brief Method that returns constant reference of data.
     * @return Constant reference of data.
     */
    const data::RawData & getData() const noexcept;

    /**
     * @brief Method that returns reference of data.
     * @return Reference of data.
     */
    data::RawData & getData() noexcept;

    /**
     * @brief Method that returns byte value under the specified endian-oriented byte index.
     * @param [in] _index - Index of byte.
     * @return Return byte value under the specified index.
     *
     * @note This method considers the endian type in which data are presented.
     */
    virtual data::RawData::Byte get(std::size_t _index) const = 0;

    /**
     * @brief Method that performs direct left shift by a specified offset.
     * @param [in] _shift - Byte offset for direct left shift.
     * @param [in] _fill - New value of shifted byte.
     * @return Reference of EngineInterface class.
     */
    virtual EngineInterface & shiftLeft(std::size_t _shift,
                                        std::optional<data::RawData::Byte> _fill) noexcept = 0;

    /**
     * @brief Method that performs direct right shift by a specified offset.
     * @param [in] _shift - Byte offset for direct right shift.
     * @param [in] _fill - New value of shifted byte.
     * @return Reference of EngineInterface class.
     */
    virtual EngineInterface & shiftRight(std::size_t _shift,
                                         std::optional<data::RawData::Byte> _fill) noexcept = 0;

    /**
     * @brief Method that performs round left shift by a specified offset.
     * @param [in] _shift - Byte offset for round left shift.
     * @return Reference of EngineInterface class.
     */
    virtual EngineInterface & rotateLeft(std::size_t _shift) noexcept = 0;

    /**
     * @brief Method that performs round right shift by a specified offset.
     * @param [in] _shift - Byte offset for round right shift.
     * @return Reference of EngineInterface class.
     */
    virtual EngineInterface & rotateRight(std::size_t _shift) noexcept = 0;

    /**
     * @brief Method that reverses blocks of data.
     * @return Reference of EngineInterface class.
     */
    virtual EngineInterface & reverse() noexcept = 0;

    /**
     * @brief Method that converts data to selected endian type.
     * @param [in] _endian - EngineInterface's endian type.
     * @return Pointer to EngineInterface class with selected endian type.
     */
    virtual EngineInterface::UniquePtr convert(Endian _endian) noexcept = 0;

    /**
     * @brief Destructor of EngineInterface class.
     */
    virtual ~EngineInterface() = default;

protected:
    Endian endian;
    data::RawData & data;
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

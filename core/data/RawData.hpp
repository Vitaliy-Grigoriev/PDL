// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <core/Declaration.hpp>

#include <cstddef>  // std::byte.
#include <cstdint>
#include <limits>   // std::numeric_limits.


namespace pdl::core::data {

/**
 * @class RawData   RawData.hpp   "core/data/RawData.hpp"
 * @brief Class implements raw binary data container and gives an interface to work with it.
 */
class RawData : public Declaration<RawData>
{
public:
    using Byte                 = std::byte;
    using MemoryPointer        = Byte *;
    using MemoryConstPointer   = const Byte *;
    using MemoryReference      = Byte &;
    using MemoryConstReference = const Byte &;

    /**
     * @brief Default constructor.
     */
    RawData() noexcept;

    /**
     * @brief Constructor that allocates specified count of bytes.
     *
     * @param [in] _count - Number of bytes for allocate.
     */
    explicit RawData(std::size_t _count);

    /**
     * @brief Constructor that accepts a pointer to allocated (or static) data.
     *
     * @param [in] _data - Pointer to allocated (or static) data.
     * @param [in] _size - Number of bytes in data.
     */
    RawData(void * _data, std::size_t _size) noexcept;

    /**
     * @brief Copy assignment constructor.
     *
     * @param [in] _other - Reference of copied RawData class.
     */
    explicit RawData(const RawData & _other);

    /**
     * @brief Move assignment constructor.
     *
     * @param [in] _other - Reference of moved RawData class.
     */
    explicit RawData(RawData && _other) noexcept;

    /**
     * @brief Method that appends specified count of bytes at the end.
     * @param [in] _size - Number of addition bytes for allocation to stored data.
     * @return Pointer to the beginning of the appended block.
     */
    MemoryPointer append(std::size_t _size);

    /**
     * @brief Method that returns the size of stored data in bytes.
     *
     * @return Size of stored data in bytes.
     */
    std::size_t size() const noexcept;

    /**
     * @brief Operator that returns a byte of stored data under specified index.
     * @param [in] _index - Index of byte in stored data.
     * @return Return a byte of data under selected index.
     */
    Byte operator[](std::size_t _index) const;

    /**
     * @brief Method that returns a pointer to byte of data under specified index.
     * @param [in] _index - Index of byte. Default: 0.
     * @return Pointer to byte of data under specified index.
     */
    [[nodiscard]]
    MemoryPointer get(std::size_t _index = 0) noexcept;

    /**
     * @brief Method that returns a pointer to const byte of data under specified index.
     * @param [in] _index - Index of byte. Default: 0.
     * @return Pointer to const byte of data under specified index.
     */
    [[nodiscard]]
    MemoryConstPointer get(std::size_t _index = 0) const noexcept;

    /**
     * @brief Operator that returns internal state of RawData class.
     *
     * @return TRUE - if RawData class initialized, otherwise - FALSE.
     */
    operator bool() const noexcept;

    /**
     * @brief Method that fills stored data using selected byte.
     * @param [in] _byte  - New value of byte for filling.
     * @param [in] _first - Start position for filling. Default: 0.
     * @param [in] _last  - Last position for filling. Default: RawData::NPOS.
     */
    void fill(Byte _byte, std::size_t _first = 0, std::size_t _last = NPOS);

    /**
     * @brief Method that fills stored data using selected byte.
     * @param [in] _index - Index of byte.
     * @param [in] _byte  - New value of byte.
     */
    void fill(std::size_t _index, Byte _byte);

    /**
     * @brief Method that destroys stored data.
     */
    void destroy() noexcept;

    /**
     * @brief Destructor.
     */
    ~RawData();

    /**
     * @brief Variable that indicates the end of sequence.
     */
    static constexpr std::size_t NPOS = std::numeric_limits<std::size_t>::max();

protected:
    /**
     * @brief Method that returns a pointer to byte of data under specified index.
     * @param [in] _index - Index of byte.
     * @return Pointer to byte of data under specified index.
     */
    [[nodiscard]]
    MemoryPointer _get(std::size_t _index) noexcept;

    /**
     * @brief Method that returns a pointer to const byte of data under specified index.
     * @param [in] _index - Index of byte. Default: 0.
     * @return Pointer to const byte of data under specified index.
     */
    [[nodiscard]]
    MemoryConstPointer _get(std::size_t _index) const noexcept;

private:
    // Internal variable that contains binary data.
    std::unique_ptr<Byte[]> memory = nullptr;
    // Length of stored data in bytes.
    std::size_t length = 0;
};

}  // namespace data.

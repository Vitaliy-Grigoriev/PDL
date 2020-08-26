// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Declaration.hpp"  // Declaration.

#include <cstddef>
#include <cstdint>
#include <memory>


namespace pdl::common::data {

/**
 * @class RawData   RawData.hpp   "common/RawData.hpp"
 * @brief Class implements raw binary data container and gives an interface to work with it.
 */
class RawData : public Declaration<RawData>
{
public:
    using Byte           = std::byte;
    using Pointer        = Byte *;
    using ConstPointer   = const Byte *;
    using Reference      = Byte &;
    using ConstReference = const Byte &;

    /**
     * @brief Default constructor.
     */
    RawData() noexcept;

    /**
     * @brief Constructor that allocates specified count of bytes.
     *
     * @param [in] _count - Number of bytes for allocate.
     */
    explicit RawData (std::size_t _count);

    /**
     * @brief Constructor that accepts a pointer to allocated (or static) data.
     *
     * @param [in] _data - Pointer to allocated (or static) data.
     * @param [in] _size - Number of bytes in data.
     */
    RawData (void * _data, std::size_t _size) noexcept;

    /**
     * @brief Copy assignment constructor.
     *
     * @param [in] _other - Reference of copied RawData class.
     */
    explicit RawData (const RawData & _other);

    /**
     * @brief Move assignment constructor.
     *
     * @param [in] _other - Reference of moved RawData class.
     */
    explicit RawData (RawData && _other) noexcept;

    /**
     * @brief Method that appends specified count of bytes at the end.
     *
     * @param [in] _size - Number of addition bytes for allocation to stored data.
     *
     * @return Pointer to the beginning of the appended block.
     */
    Pointer append (std::size_t _size);

    /**
     * @brief Method that returns the size of stored data in bytes.
     *
     * @return Size of stored data in bytes.
     */
    std::size_t size() const noexcept;

    /**
     * @brief Operator that returns a byte of stored data under specified index.
     *
     * @param [in] _index - Index of byte in stored data.
     *
     * @return Return a byte of data under selected index.
     */
    Byte operator[] (std::size_t _index) const;

    /**
     * @brief Method that returns a pointer to byte of stored data under specified index.
     *
     * @param [in] _index - Index of byte in stored data. Default: 0.
     *
     * @return Pointer to byte of stored data under specified index or nullptr if index out of range.
     */
    [[nodiscard]]
    Pointer get (std::size_t _index = 0) noexcept;

    /**
     * @brief Method that returns a pointer to const byte of stored data under specified index.
     *
     * @param [in] _index - Index of byte in stored data. Default: 0.
     *
     * @return Pointer to const byte of stored data under specified index or nullptr if index out of range.
     */
    [[nodiscard]]
    ConstPointer get (std::size_t _index = 0) const noexcept;

    /**
     * @brief Operator that returns internal state of RawData class.
     *
     * @return TRUE - if RawData class initialized, otherwise - FALSE.
     */
    operator bool() const noexcept;

    /**
     * @brief Method that destroys stored data.
     */
    void destroy() noexcept;

    /**
     * @brief Destructor.
     */
    ~RawData();

private:
    /**
     * @brief Storage that contains raw data.
     */
    std::unique_ptr<Byte[]> memory = nullptr;
    /**
     * @brief Length of stored data in bytes.
     */
    std::size_t length = 0;
};

}  // namespace data.

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
 * @class BinaryData   BinaryData.hpp   "common/BinaryData.hpp"
 * @brief This class implements the binary data container and gives an interface to work with it.
 */
class BinaryData : public Declaration<BinaryData>
{
public:
    using ValueType      = std::byte;
    using Pointer        = ValueType *;
    using ConstPointer   = const ValueType *;
    using Reference      = ValueType &;
    using ConstReference = const ValueType &;

    /**
     * @brief Default constructor.
     */
    BinaryData() noexcept;

    /**
     * @brief Constructor that allocates specified count of bytes.
     *
     * @param [in] count - Number of bytes for allocate.
     */
    explicit BinaryData (std::size_t _count);

    /**
     * @brief Constructor that accepts a pointer to allocated (or static) data.
     *
     * @param [in] data - Pointer to allocated (or static) data.
     * @param [in] _size - Number of bytes in data.
     */
    BinaryData (void * _data, std::size_t _size) noexcept;

    /**
     * @brief Copy assignment constructor.
     *
     * @param [in] other - Reference of copied BinaryData class.
     */
    explicit BinaryData (const BinaryData & _other);

    /**
     * @brief Move assignment constructor.
     *
     * @param [in] other - Reference of moved BinaryData class.
     */
    explicit BinaryData (BinaryData && _other) noexcept;

    /**
     * @brief Method that appends specified bytes at the end.
     *
     * @param [in] size - Number of addition bytes for allocation to stored data.
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
     * @param [in] index - Index of byte in stored data.
     *
     * @return Return a byte of data under selected index.
     */
    ValueType operator[] (std::size_t _index) const;

    /**
     * @brief Method that returns a pointer to byte of stored data under specified index.
     *
     * @param [in] index - Index of byte in stored data. Default: 0.
     *
     * @return Pointer to byte of stored data under specified index or nullptr if index out of range.
     */
    [[nodiscard]]
    Pointer get (std::size_t _index = 0) noexcept;

    /**
     * @brief Method that returns a pointer to const byte of stored data under specified index.
     *
     * @param [in] index - Index of byte in stored data. Default: 0.
     *
     * @return Pointer to const byte of stored data under specified index or nullptr if index out of range.
     */
    [[nodiscard]]
    ConstPointer get (std::size_t _index = 0) const noexcept;

    /**
     * @brief Operator that returns internal state of BinaryData class.
     *
     * @return TRUE - if BinaryData class initialized, otherwise - FALSE.
     */
    operator bool() const noexcept;

    /**
     * @brief Method that destroys stored data.
     */
    void destroy() noexcept;

    /**
     * @brief Destructor.
     */
    ~BinaryData();

private:
    /**
     * @brief Storage that contains binary data.
     */
    std::unique_ptr<ValueType[]> memory = nullptr;
    /**
     * @brief Length of stored data in bytes.
     */
    std::size_t length = 0;
};

}  // namespace data.

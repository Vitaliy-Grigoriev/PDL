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
    /**
     * @brief Default constructor.
     */
    BinaryData() = default;

    /**
     * @brief Constructor that allocates specified count of bytes.
     *
     * @param [in] count - Number of bytes for allocate.
     */
    explicit BinaryData (std::size_t count);

    /**
     * @brief Constructor that accepts a pointer to allocated (or static) data.
     *
     * @param [in] data - Pointer to allocated (or static) data.
     * @param [in] size - Number of bytes in data.
     */
    BinaryData (void * data, std::size_t size) noexcept;

    /**
     * @brief Copy assignment constructor.
     *
     * @param [in] other - Reference of copied BinaryData class.
     */
    explicit BinaryData (const BinaryData & other);

    /**
     * @brief Move assignment constructor.
     *
     * @param [in] other - Reference of moved BinaryData class.
     */
    explicit BinaryData (BinaryData && other) noexcept;

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
    std::byte operator[] (std::size_t index) const;

    /**
     * @brief Method that returns a pointer to byte of stored data under specified index.
     *
     * @param [in] index - Index of byte in stored data. Default: 0.
     *
     * @return Pointer to byte of stored data under specified index or nullptr if index out of range.
     */
    [[nodiscard]]
    std::byte * get (std::size_t index = 0) noexcept;

    /**
     * @brief Method that returns a pointer to const byte of stored data under specified index.
     *
     * @param [in] index - Index of byte in stored data. Default: 0.
     *
     * @return Pointer to const byte of stored data under specified index or nullptr if index out of range.
     */
    [[nodiscard]]
    const std::byte * get (std::size_t index = 0) const noexcept;

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
    std::unique_ptr<std::byte[]> memory = nullptr;
    /**
     * @brief Length of stored data in bytes.
     */
    std::size_t length = 0;
    /**
     * @brief Flag indicates that stored data
     */
    bool allocated = false;
};

}  // namespace data.

// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Declaration.hpp"
#include "Endian.hpp"

#include <memory>   // std::unique_ptr.


namespace pdl::common::data
{

/**
 * @class BinaryData   BinaryData.hpp   "common/BinaryData.hpp"
 * @brief This class implements the container of binary data and gives an interface to work with it.
 */
class BinaryData : Declaration<BinaryData>
{
public:
    /**
     * @brief Default constructor.
     */
    BinaryData() = default;

    /**
     * @brief Copy assignment constructor.
     *
     * @param [in] other - Constant lvalue reference of copied BinaryData class.
     */
    BinaryData (const BinaryData & other);

    /**
     * @brief Move assignment constructor.
     *
     * @param [in] other - Rvalue reference of moved BinaryData class.
     */
    BinaryData (BinaryData && other) noexcept;

    /**
     * @brief Method that returns the size of stored data.
     *
     * @return Size of stored data in bytes.
     */
    std::size_t Size() const noexcept;

    /**
     * @brief Method that returns the pointer to the const internal data.
     *
     * @return Pointer to the const internal data.
     *
     * @note This method does not consider the type of endian in which stored data are presented.
     */
    const std::byte * Data() const noexcept;

    /**
     * @brief Method that returns the state of stored binary data in BinaryDataEngine class.
     *
     * @return TRUE - if stored data is empty, otherwise - FALSE.
     */
    bool IsEmpty() const noexcept;

    /**
     * @brief Operator that returns the internal state of BinaryDataEngine class.
     *
     * @return TRUE - if BinaryDataEngine class is not empty, otherwise - FALSE.
     */
    operator bool() const noexcept;

    /**
     * @brief Operator that returns a byte of data under selected index.
     *
     * @param [in] index - Index of byte in byte sequence of stored data.
     * @return Return a byte of data under selected index.
     *
     * @note This method does not consider the type of endian in which data are presented.
     */
    std::byte operator[] (std::size_t /*index*/) const noexcept;

    /**
     * @brief Method that returns a pointer to an element by selected index.
     *
     * @param [in] index - Index of byte in byte sequence of stored data.
     * @return Pointer to an element by selected index or nullptr in an error occurred.
     *
     * @note This method DOES NOT consider the endian type in which stored data are presented.
     */
    [[nodiscard]]
    std::byte * GetAt (std::size_t /*index*/) const noexcept;

    /**
     * @brief Method that destroys stored data.
     */
    void Destroy() noexcept;

    ~BinaryData();

private:
    /**
     * @brief Storage that contains binary data.
     */
    std::unique_ptr<std::byte[]> data = nullptr;
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

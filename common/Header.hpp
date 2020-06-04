// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "BinaryData.hpp"
#include "Field.hpp"


namespace pdl::common::data {

class Constructor;

/**
 * @class Header   Header.hpp   "common/Header.hpp"
 * @brief This class implements .
 */
class Header : public Declaration<Header>
{
public:
    /**
     * @brief Default constructor.
     */
    Header() noexcept;

private:
    friend class Constructor;

    struct FieldInfo
    {
        std::string name;
        endian::Endian endian;
        uint16_t length;
    };

    BinaryData memory;
};


class Constructor : public Declaration<Constructor>
{
public:
    explicit Constructor (Header & _header) noexcept;

private:
    Header & header;
};

}  // namespace data.

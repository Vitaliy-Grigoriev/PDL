// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Field.hpp"

#include <core/data/RawData.hpp>


namespace pdl::core::data {

class Constructor;

/**
 * @class Header   Header.hpp   "core/Header.hpp"
 * @brief Class implements .
 */
class Header : public Declaration<Header>
{
    friend class Constructor;

public:
    /**
     * @brief Default constructor.
     */
    Header() noexcept;

private:
    RawData data;
};


class Constructor : public Declaration<Constructor>
{
public:
    explicit Constructor (Header & _header) noexcept;

private:
    Header & header;
};

}  // namespace data.

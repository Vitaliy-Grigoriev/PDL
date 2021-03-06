// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Field.hpp"
#include "RawData.hpp"


namespace pdl::common::data {

class Constructor;

/**
 * @class Header   Header.hpp   "common/Header.hpp"
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

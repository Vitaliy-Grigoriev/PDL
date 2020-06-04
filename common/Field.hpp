// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include "Declaration.hpp"  // Declaration.
#include "Endian.hpp"       // endian::Endian.

#include <optional>
#include <string>
#include <string_view>
#include <vector>


namespace pdl::common::data {

class Field;


class Subfield : public Declaration<Subfield>
{
public:
    Subfield (std::string _name, uint16_t _offset, uint16_t _bits, Field & _field) noexcept;

    uint16_t size() const noexcept;
    uint16_t offset() const noexcept;
    std::string_view name() const noexcept;

private:
    std::string fieldName;
    uint16_t fieldOffset;
    uint16_t bits;
    Field & field;
};


class Field : public Declaration<Field>
{
    friend class Subfield;

public:
    Field (std::string _name, endian::Endian _endian, uint16_t _bytes) noexcept;

    Field & appendSubfield (std::string _name, uint16_t _bits);
    Subfield & getSubfield (const std::string & _name);
    const Subfield & getSubfield (const std::string & _name) const;

    Field & setOffset (void * _offset) noexcept;
    void * getOffset() const noexcept;

    uint16_t size() const noexcept;
    endian::Endian endian() const noexcept;
    std::string_view name() const noexcept;

protected:
    [[nodiscard]]
    Subfield * findSubfield (const std::string & _name) noexcept;
    [[nodiscard]]
    const Subfield * findSubfield (const std::string & _name) const noexcept;

    uint16_t calculateFullBitOffsetOfSubfield() const noexcept;

private:
    std::string fieldName;
    endian::Endian fieldEndian;
    uint16_t bytes;
    void * offset = nullptr;
    std::vector<Subfield> fields;
};

}  // namespace data.

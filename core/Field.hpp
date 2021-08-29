// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#pragma once

#include <core/Declaration.hpp>

#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include <core/endian/EngineInterface.hpp>


namespace pdl::core::data {

class Field;


class Subfield : public Declaration<Subfield>
{
public:
    Subfield (std::string _name, uint16_t _offset, uint16_t _count, Field & _field) noexcept;

    uint16_t size() const noexcept;
    uint16_t offset() const noexcept;
    std::string_view name() const noexcept;

private:
    std::string fieldName;
    uint16_t fieldOffset;
    uint16_t count;
    Field & field;
};


class Field : public Declaration<Field>
{
    friend class Subfield;

public:
    Field (std::string _name, endian::Endian _endian, uint16_t _bytes) noexcept;

    Field & append (std::string _name, uint16_t _bits);

    Subfield & subfield (const std::string & _name);
    const Subfield & subfield (const std::string & _name) const;

    Field & setOffset (void * _offset) noexcept;
    void * getOffset() const noexcept;

    uint16_t size() const noexcept;
    endian::Endian endian() const noexcept;
    std::string_view name() const noexcept;

protected:
    [[nodiscard]]
    Subfield * find (const std::string & _name) noexcept;
    [[nodiscard]]
    const Subfield * find (const std::string & _name) const noexcept;

    uint16_t calculateFullBitOffsetOfSubfield() const noexcept;

private:
    std::string fieldName;
    endian::Endian fieldEndian;
    uint16_t bytes;
    void * offset = nullptr;
    std::vector<Subfield> fields;
};

}  // namespace data.

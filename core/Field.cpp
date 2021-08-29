// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "Field.hpp"

#include <error/Error.hpp>

#include <algorithm>
#include <numeric>


namespace pdl::core::data {
namespace {

template <typename Type>
Type value()
{
    return Type{};
}

}

Subfield::Subfield(std::string _name, const uint16_t _offset, const uint16_t _count, Field& _field) noexcept :
    Declaration{ this },
    fieldName{ std::move(_name) },
    fieldOffset{ _offset },
    count{ _count },
    field{ _field }
{ }

uint16_t Subfield::size() const noexcept
{
    return count;
}

uint16_t Subfield::offset() const noexcept
{
    return fieldOffset;
}

std::string_view Subfield::name() const noexcept
{
    return fieldName;
}


Field::Field(std::string _name, const endian::Endian _endian, const uint16_t _bytes) noexcept :
    Declaration{ this },
    fieldName{ std::move(_name) },
    fieldEndian{ _endian },
    bytes{ _bytes }
{ }

Field& Field::append(std::string _name, const uint16_t _bits)
{
    fields.emplace_back(std::move(_name), calculateFullBitOffsetOfSubfield(), _bits, *this);
    return *this;
}

Subfield& Field::subfield(const std::string& _name)
{
    if (auto field = find (_name)) {
        return *field;
    }
    panic(error::Module::Subfield, error::Code::ObjectNotFound, "Subfield '" + _name + "' not found");
}

const Subfield& Field::subfield (const std::string& _name) const
{
    if (const auto field = find (_name)) {
        return *field;
    }
    panic(error::Module::Subfield, error::Code::ObjectNotFound, "Subfield '" + _name + "' not found");
}

Field& Field::setOffset (void* const _offset) noexcept
{
    offset = _offset;
    return *this;
}

void* Field::getOffset() const noexcept
{
    return offset;
}

Subfield* Field::find (const std::string& _name) noexcept
{
    auto it = std::find_if(fields.begin(), fields.end(),
                           [&_name] (const Subfield& _subfield) -> bool {
                               return _subfield.name() == _name;
                           });
    return it != fields.end() ? it->ptr() : nullptr;
}

const Subfield* Field::find (const std::string& _name) const noexcept
{
    auto it = std::find_if(fields.cbegin(), fields.cend(),
                           [&_name] (const Subfield& _subfield) -> bool {
                               return _subfield.name() == _name;
                           });
    return it != fields.cend() ? it->ptr() : nullptr;
}

uint16_t Field::calculateFullBitOffsetOfSubfield() const noexcept
{
    return std::accumulate(fields.cbegin(), fields.cend(), 0,
                           [] (const uint16_t _value, const Subfield& _subfield) -> uint16_t {
                               return _value + _subfield.size();
                           });
}

}  // namespace data.

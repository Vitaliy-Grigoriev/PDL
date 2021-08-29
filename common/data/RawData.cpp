// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "RawData.hpp"
#include "Memory.hpp"  // memory::allocArray.


namespace pdl::common::data {
namespace {

[[noreturn]]
void throwIndexOutOfRange()
{
    panic(error::Module::RawData,
           error::Code::IndexOutOfRange,
           "Index out of range");
}

}

// Default constructor.
RawData::RawData() noexcept :
    Declaration{ this }
{ }

// Constructor that allocates specified count of bytes.
RawData::RawData(const std::size_t _count) :
    Declaration{ this },
    memory{ memory::allocArray<Byte>(_count) },
    length{ _count }
{ }

// Constructor that accepts a pointer to allocated (or static) data.
RawData::RawData(void* const _data, const std::size_t _size) noexcept :
    Declaration{ this },
    memory{ memory::allocArray<Byte>(_size, _data, _size) },
    length{ _size }
{ }

// Copy assignment constructor.
RawData::RawData(const RawData& _other) :
    Declaration{ this }
{
    if (_other) {
        memory = memory::allocArray<Byte>(_other.length, _other.memory.get(), _other.length);
        length = _other.length;
    }
}

// Move assignment constructor.
RawData::RawData(RawData&& _other) noexcept :
    Declaration{ this }
{
    std::swap(memory, _other.memory);
    std::swap(length, _other.length);
    _other.destroy();
}

// Method that appends specified count of bytes at the end.
auto RawData::append(const std::size_t _size) -> MemoryPointer
{
    if (_size) {
        memory = memory::allocArray<Byte>(length + _size, memory.get(), length);
        length += _size;
        return get(length - _size);
    }
    panic(error::Module::RawData, error::Code::ZeroMemoryAllocation, "Specified 0 bytes for appending");
}

// Method that returns the size of data in bytes.
std::size_t RawData::size() const noexcept
{
    return length;
}

// Operator that returns a byte of data under specified index.
auto RawData::operator[](const std::size_t _index) const -> Byte
{
    if (_index < length) {
        return memory[_index];
    }

    throwIndexOutOfRange();
}

// Method that returns a pointer to byte of data under specified index.
auto RawData::get(const std::size_t _index) noexcept -> MemoryPointer
{
    if (_index < length) {
        return _get(_index);
    }

    throwIndexOutOfRange();
}

// Method that returns a pointer to const byte of data under specified index.
auto RawData::get(const std::size_t _index) const noexcept -> MemoryConstPointer
{
    if (_index < length) {
        return _get(_index);
    }

    throwIndexOutOfRange();
}

// Operator that returns internal state of RawData class.
RawData::operator bool() const noexcept
{
    return memory && length;
}

// Method that fills stored data using selected byte.
void RawData::fill(const Byte _byte, const std::size_t _first, const std::size_t _last)
{
    const std::size_t last = _last == NPOS ? length - 1 : _last;

    if (_first <= last && last < length) {
        memset(_get(_first), static_cast<int32_t>(_byte), last - _first + 1);
    }

    throwIndexOutOfRange();
}

void RawData::fill(const std::size_t _index, const Byte _byte)
{
    *get(_index) = _byte;
}

// Method that destroys stored data.
void RawData::destroy() noexcept
{
    length = 0;
    memory.reset(nullptr);
}

RawData::~RawData()
{
    destroy();
}

// Method that returns a pointer to byte of data under specified index.
auto RawData::_get(const std::size_t _index) noexcept -> MemoryPointer
{
    return &memory[_index];
}

// Method that returns a pointer to const byte of data under specified index.
auto RawData::_get(const std::size_t _index) const noexcept -> MemoryConstPointer
{
    return &memory[_index];
}

}  // namespace data.

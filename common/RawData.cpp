// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "RawData.hpp"
#include "Error.hpp"   // panic.
#include "Memory.hpp"  // memory::allocArray.


namespace pdl::common::data {

// Default constructor.
RawData::RawData() noexcept :
    Declaration{ this }
{ }

// Constructor that allocates specified count of bytes.
RawData::RawData (const std::size_t _count) :
    Declaration{ this },
    memory{ memory::allocArray<Byte>(_count) },
    length{ _count }
{ }

// Constructor that accepts a pointer to allocated (or static) data.
RawData::RawData (void* const _data, const std::size_t _size) noexcept :
    Declaration{ this },
    memory{ memory::allocArray<Byte>(_size, _data, _size) },
    length{ _size }
{ }

// Copy assignment constructor.
RawData::RawData (const RawData& _other) :
    Declaration{ this }
{
    if (_other) {
        memory = memory::allocArray<Byte>(_other.length, _other.memory.get(), _other.length);
        length = _other.length;
    }
}

// Move assignment constructor.
RawData::RawData (RawData&& _other) noexcept :
    Declaration{ this }
{
    std::swap(memory, _other.memory);
    std::swap(length, _other.length);
    _other.destroy();
}

// Method that appends specified count of bytes at the end.
auto RawData::append (const std::size_t _size) -> Pointer
{
    if (_size) {
        memory = memory::allocArray<Byte>(length + _size, memory.get(), length);
        length += _size;
        return get(length - _size);
    }
    panic(Module::RawData, Code::ZeroMemoryAllocation, "Specified 0 bytes for appending");
}

// Method that returns the size of stored data in bytes.
std::size_t RawData::size() const noexcept
{
    return length;
}

// Operator that returns a byte of stored data under specified index.
auto RawData::operator[] (const std::size_t _index) const -> Byte
{
    if (_index < length) {
        return memory[_index];
    }
    panic(Module::RawData, Code::IndexOutOfRange, "Index of byte out of range");
}

// Method that returns a pointer to byte of stored data under specified index.
auto RawData::get (const std::size_t _index) noexcept -> Pointer
{
    return _index < length ? &memory[_index] : nullptr;
}

// Method that returns a pointer to const byte of stored data under specified index.
auto RawData::get (const std::size_t _index) const noexcept -> ConstPointer
{
    return _index < length ? &memory[_index] : nullptr;
}

// Operator that returns internal state of RawData class.
RawData::operator bool() const noexcept
{
    return memory && length;
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

}  // namespace data.

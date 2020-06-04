// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "BinaryData.hpp"
#include "Error.hpp"   // panic.
#include "Memory.hpp"  // memory::allocArray.


namespace pdl::common::data {

// Default constructor.
BinaryData::BinaryData() noexcept :
    Declaration(this)
{ }

// Constructor that allocates specified count of bytes.
BinaryData::BinaryData (const std::size_t _count) :
    Declaration(this),
    memory{memory::allocArray<ValueType>(_count)},
    length{_count}
{ }

// Constructor that accepts a pointer to allocated (or static) data.
BinaryData::BinaryData (void* const _data, const std::size_t _size) noexcept :
    Declaration(this),
    memory{memory::allocArray<ValueType>(_size, _data, _size)},
    length{_size}
{ }

// Copy assignment constructor.
BinaryData::BinaryData (const BinaryData& _other) :
    Declaration(this)
{
    if (_other) {
        memory = memory::allocArray<ValueType>(_other.length, _other.memory.get(), _other.length);
        length = _other.length;
    }
}

// Move assignment constructor.
BinaryData::BinaryData (BinaryData&& _other) noexcept :
    Declaration(this)
{
    std::swap(memory, _other.memory);
    std::swap(length, _other.length);
    _other.destroy();
}

// Method that appends specified bytes at the end.
auto BinaryData::append (const std::size_t _size) -> Pointer
{
    if (_size) {
        memory = memory::allocArray<ValueType>(length + _size, memory.get(), length);
        length += _size;
        return get(length - _size);
    }
    panic(Module::binary_data, Code::zero_memory_allocation, "Specified 0 bytes for appending");
}

// Method that returns the size of stored data in bytes.
std::size_t BinaryData::size() const noexcept
{
    return length;
}

// Operator that returns a byte of stored data under specified index.
auto BinaryData::operator[] (const std::size_t _index) const -> ValueType
{
    if (_index < length) {
        return memory[_index];
    }
    panic(Module::binary_data, Code::index_out_of_range, "Index of byte out of range");
}

// Method that returns a pointer to byte of stored data under specified index.
auto BinaryData::get (const std::size_t _index) noexcept -> Pointer
{
    return _index < length ? &memory[_index] : nullptr;
}

// Method that returns a pointer to const byte of stored data under specified index.
auto BinaryData::get (const std::size_t _index) const noexcept -> ConstPointer
{
    return _index < length ? &memory[_index] : nullptr;
}

// Operator that returns internal state of BinaryData class.
BinaryData::operator bool() const noexcept
{
    return memory && length;
}

// Method that destroys stored data.
void BinaryData::destroy() noexcept
{
    length = 0;
    memory.reset(nullptr);
}

BinaryData::~BinaryData()
{
    destroy();
}

}  // namespace data.

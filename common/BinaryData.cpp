// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "BinaryData.hpp"
#include "Error.hpp"   // panic.
#include "Memory.hpp"  // memory::allocArray.


namespace pdl::common::data {

// Constructor that allocates specified count of bytes.
BinaryData::BinaryData (const std::size_t count) :
    memory{memory::allocArray<std::byte>(count)},
    length{count},
    allocated{true}
{ }

// Constructor that accepts a pointer to allocated (or static) data.
BinaryData::BinaryData (void* const data, const std::size_t size) noexcept :
    memory{static_cast<std::byte*>(data)},
    length{size},
    allocated{false}
{ }

// Copy assignment constructor.
BinaryData::BinaryData (const BinaryData& other)
{
    if (other) {
        memory = memory::allocArray<std::byte>(other.length, other.memory.get(), other.length);
        length = other.length;
        allocated = true;
    }
}

// Move assignment constructor.
BinaryData::BinaryData (BinaryData&& other) noexcept
{
    std::swap(memory, other.memory);
    std::swap(length, other.length);
    std::swap(allocated, other.allocated);
    other.destroy();
}

// Method that returns the size of stored data in bytes.
std::size_t BinaryData::size() const noexcept
{
    return length;
}

// Operator that returns a byte of stored data under specified index.
std::byte BinaryData::operator[] (const std::size_t index) const
{
    if (index < length) {
        return memory[index];
    }
    panic(Module::binary_data, Code::index_out_of_range, "Index of byte out of range");
}

// Method that returns a pointer to byte of stored data under specified index.
std::byte* BinaryData::get (const std::size_t index) noexcept
{
    return index < length ? &memory[index] : nullptr;
}

// Method that returns a pointer to const byte of stored data under specified index.
const std::byte* BinaryData::get (const std::size_t index) const noexcept
{
    return index < length ? &memory[index] : nullptr;
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
    if (allocated) {
        memory.reset(nullptr);
    }
    else {
        memory.release();
    }
    allocated = false;
}

BinaryData::~BinaryData()
{
    destroy();
}

}  // namespace data.

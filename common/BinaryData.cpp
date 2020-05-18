// ============================================================================
// Copyright (c) 2017-2020, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "BinaryData.hpp"
#include "Memory.hpp"


namespace pdl::common::data
{

// Copy assignment constructor.
BinaryData::BinaryData (const BinaryData& other)
{
    if (other) {
        data = memory::allocArray<std::byte>(other.length, other.data.get(), other.length);
        length = other.length;
        allocated = true;
    }
}

// Move assignment constructor.
BinaryData::BinaryData (BinaryData&& other) noexcept
{
    if (other) {
        data = std::move(other.data);
        length = other.length;
        allocated = other.allocated;
        other.Destroy();
    }
}

// Method that destroys stored data.
void BinaryData::Destroy() noexcept
{
    length = 0;
    if (allocated) {
        data.reset(nullptr);
    }
    else {
        data.release();
    }
    allocated = false;
}

BinaryData::~BinaryData()
{
    Destroy();
}

}  // namespace data.

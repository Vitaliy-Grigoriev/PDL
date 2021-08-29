// ============================================================================
// Copyright (c) 2017-2021, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of PdlFramework open source project under MIT License.
// ============================================================================

#include "EngineInterface.hpp"

#include <error/Error.hpp>


namespace pdl::common::endian {
namespace {

[[nodiscard]]
bool isSizeCorrect(const std::size_t size) noexcept
{
    return (size & (size - 1)) == 0U;
}

}

EngineInterface::EngineInterface(const Endian _endian, data::RawData& _data) :
    Declaration{ this },
    endian{ _endian },
    data{ _data }
{
    if (!isSizeCorrect(data.size())) {
        error::panic(error::Module::RawData, error::Code::InvalidInputData, "Size of data is not power of two");
    }
}

Endian EngineInterface::getEndianType() const noexcept
{
    return endian;
}

std::size_t EngineInterface::size() const noexcept
{
    return data.size();
}

std::byte reverseBits(std::byte _byte) noexcept
{
    _byte = (_byte & std::byte(0xF0)) >> 4U | (_byte & std::byte(0x0F)) << 4U;
    _byte = (_byte & std::byte(0xCC)) >> 2U | (_byte & std::byte(0x33)) << 2U;
    _byte = (_byte & std::byte(0xAA)) >> 1U | (_byte & std::byte(0x55)) << 1U;
    return _byte;
}

}  // namespace endian.

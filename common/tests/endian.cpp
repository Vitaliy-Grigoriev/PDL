#include <common/Endian.hpp>
#include <gtest/gtest.h>


TEST(pdl_common_endian, checkCorrectBitsReverse)
{
    using namespace pdl::common::data::endian;

    ASSERT_EQ(ReverseBits(std::byte(0x01)), std::byte(0x80));
    ASSERT_EQ(ReverseBits(std::byte(0x0C)), std::byte(0x30));
    ASSERT_EQ(ReverseBits(std::byte(0x30)), std::byte(0x0C));
    ASSERT_EQ(ReverseBits(std::byte(0xAA)), std::byte(0x55));
    ASSERT_EQ(ReverseBits(std::byte(0xFF)), std::byte(0xFF));
}

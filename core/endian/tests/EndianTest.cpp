#include <core/endian/EngineInterface.hpp>
#include <gtest/gtest.h>


TEST(pdl_core_endian, checkCorrectBitsReverse)
{
    using namespace pdl::core::endian;

    ASSERT_EQ(reverseBits(std::byte(0x01)), std::byte(0x80));
    ASSERT_EQ(reverseBits(std::byte(0x0C)), std::byte(0x30));
    ASSERT_EQ(reverseBits(std::byte(0x30)), std::byte(0x0C));
    ASSERT_EQ(reverseBits(std::byte(0xAA)), std::byte(0x55));
    ASSERT_EQ(reverseBits(std::byte(0xFF)), std::byte(0xFF));
}

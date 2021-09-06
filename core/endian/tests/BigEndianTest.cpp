#include <core/data/PredefinedBytes.hpp>
#include <core/data/RawData.hpp>
#include <core/endian/Engines.hpp>
#include <gtest/gtest.h>


TEST(pdl_big_endian, checkCorrectBytePosition)
{
    using namespace pdl::core::data;
    using namespace pdl::core::endian;

    RawData data{ 4 };
    data.fill(0, std::byte(0xA0));
    data.fill(1, std::byte(0xB3));
    data.fill(2, std::byte(0xC5));
    data.fill(3, std::byte(0xDF));

    EngineInterface::UniquePtr engine = getEngine(Endian::big, data);

    ASSERT_EQ(engine->get(0), std::byte(0xDF));
    ASSERT_EQ(engine->get(1), std::byte(0xC5));
    ASSERT_EQ(engine->get(2), std::byte(0xB3));
    ASSERT_EQ(engine->get(3), std::byte(0xA0));
}

TEST(pdl_big_endian, checkCorrectLeftShift)
{
    using namespace pdl::core::data;
    using namespace pdl::core::endian;

    RawData data{ 4 };
    data.fill(0, std::byte(0xA0));
    data.fill(1, std::byte(0xB3));
    data.fill(2, std::byte(0xC5));
    data.fill(3, std::byte(0xDF));

    uint32_t integer = *reinterpret_cast<uint32_t *>(data.get());
    EngineInterface::UniquePtr engine = getEngine(Endian::big, data);

    engine->shiftLeft(1, std::nullopt);

    ASSERT_EQ(engine->get(0), LowByte);
    ASSERT_EQ(engine->get(1), std::byte(0xDF));
    ASSERT_EQ(engine->get(2), std::byte(0xC5));
    ASSERT_EQ(engine->get(3), std::byte(0xB3));

    integer >>= 8;
    const uint32_t integer_1 = *reinterpret_cast<const uint32_t *>(data.get());
    ASSERT_EQ(integer, integer_1);

    engine->shiftLeft(1, std::nullopt);

    ASSERT_EQ(engine->get(0), LowByte);
    ASSERT_EQ(engine->get(1), LowByte);
    ASSERT_EQ(engine->get(2), std::byte(0xDF));
    ASSERT_EQ(engine->get(3), std::byte(0xC5));

    integer >>= 8;
    const uint32_t integer_2 = *reinterpret_cast<const uint32_t *>(data.get());
    ASSERT_EQ(integer, integer_2);

    engine->shiftLeft(2, HighByte);

    ASSERT_EQ(engine->get(0), HighByte);
    ASSERT_EQ(engine->get(1), HighByte);
    ASSERT_EQ(engine->get(2), LowByte);
    ASSERT_EQ(engine->get(3), LowByte);
}

TEST(pdl_big_endian, checkCorrectRightShift)
{
    using namespace pdl::core::data;
    using namespace pdl::core::endian;

    RawData data{ 4 };
    data.fill(0, std::byte(0xA0));
    data.fill(1, std::byte(0xB3));
    data.fill(2, std::byte(0xC5));
    data.fill(3, std::byte(0xDF));

    uint32_t integer = *reinterpret_cast<uint32_t *>(data.get());
    EngineInterface::UniquePtr engine = getEngine(Endian::big, data);

    engine->shiftRight(1, std::nullopt);

    ASSERT_EQ(engine->get(0), std::byte(0xC5));
    ASSERT_EQ(engine->get(1), std::byte(0xB3));
    ASSERT_EQ(engine->get(2), std::byte(0xA0));
    ASSERT_EQ(engine->get(3), LowByte);

    integer <<= 8;
    const uint32_t integer_1 = *reinterpret_cast<const uint32_t *>(data.get());
    ASSERT_EQ(integer, integer_1);

    engine->shiftRight(1, std::nullopt);

    ASSERT_EQ(engine->get(0), std::byte(0xB3));
    ASSERT_EQ(engine->get(1), std::byte(0xA0));
    ASSERT_EQ(engine->get(2), LowByte);
    ASSERT_EQ(engine->get(3), LowByte);

    integer <<= 8;
    const uint32_t integer_2 = *reinterpret_cast<const uint32_t *>(data.get());
    ASSERT_EQ(integer, integer_2);

    engine->shiftRight(2, HighByte);

    ASSERT_EQ(engine->get(0), LowByte);
    ASSERT_EQ(engine->get(1), LowByte);
    ASSERT_EQ(engine->get(2), HighByte);
    ASSERT_EQ(engine->get(3), HighByte);
}

TEST(pdl_big_endian, checkCorrectLeftRotate)
{
    using namespace pdl::core::data;
    using namespace pdl::core::endian;

    RawData data{ 4 };
    data.fill(0, std::byte(0xA0));
    data.fill(1, std::byte(0xB3));
    data.fill(2, std::byte(0xC5));
    data.fill(3, std::byte(0xDF));

    EngineInterface::UniquePtr engine = getEngine(Endian::big, data);

    engine->rotateLeft(1);

    ASSERT_EQ(engine->get(0), std::byte(0xA0));
    ASSERT_EQ(engine->get(1), std::byte(0xDF));
    ASSERT_EQ(engine->get(2), std::byte(0xC5));
    ASSERT_EQ(engine->get(3), std::byte(0xB3));

    engine->rotateLeft(1);

    ASSERT_EQ(engine->get(0), std::byte(0xB3));
    ASSERT_EQ(engine->get(1), std::byte(0xA0));
    ASSERT_EQ(engine->get(2), std::byte(0xDF));
    ASSERT_EQ(engine->get(3), std::byte(0xC5));

    engine->rotateLeft(6);

    ASSERT_EQ(engine->get(0), std::byte(0xDF));
    ASSERT_EQ(engine->get(1), std::byte(0xC5));
    ASSERT_EQ(engine->get(2), std::byte(0xB3));
    ASSERT_EQ(engine->get(3), std::byte(0xA0));
}

TEST(pdl_big_endian, checkCorrectRightRotate)
{
    using namespace pdl::core::data;
    using namespace pdl::core::endian;

    RawData data{ 4 };
    data.fill(0, std::byte(0xA0));
    data.fill(1, std::byte(0xB3));
    data.fill(2, std::byte(0xC5));
    data.fill(3, std::byte(0xDF));

    EngineInterface::UniquePtr engine = getEngine(Endian::big, data);

    engine->rotateRight(1);

    ASSERT_EQ(engine->get(0), std::byte(0xC5));
    ASSERT_EQ(engine->get(1), std::byte(0xB3));
    ASSERT_EQ(engine->get(2), std::byte(0xA0));
    ASSERT_EQ(engine->get(3), std::byte(0xDF));

    engine->rotateRight(1);

    ASSERT_EQ(engine->get(0), std::byte(0xB3));
    ASSERT_EQ(engine->get(1), std::byte(0xA0));
    ASSERT_EQ(engine->get(2), std::byte(0xDF));
    ASSERT_EQ(engine->get(3), std::byte(0xC5));

    engine->rotateRight(6);

    ASSERT_EQ(engine->get(0), std::byte(0xDF));
    ASSERT_EQ(engine->get(1), std::byte(0xC5));
    ASSERT_EQ(engine->get(2), std::byte(0xB3));
    ASSERT_EQ(engine->get(3), std::byte(0xA0));
}

TEST(pdl_big_endian, checkCorrectReverse)
{
    using namespace pdl::core::data;
    using namespace pdl::core::endian;

    RawData data{ 4 };
    data.fill(0, std::byte(0xA0));
    data.fill(1, std::byte(0xB3));
    data.fill(2, std::byte(0xC5));
    data.fill(3, std::byte(0xDF));

    EngineInterface::UniquePtr engine = getEngine(Endian::big, data);
    engine->reverse();

    ASSERT_EQ(engine->get(0), std::byte(0xA0));
    ASSERT_EQ(engine->get(1), std::byte(0xB3));
    ASSERT_EQ(engine->get(2), std::byte(0xC5));
    ASSERT_EQ(engine->get(3), std::byte(0xDF));
}

TEST(pdl_big_endian, checkCorrectConvertToLittleEndian)
{
    using namespace pdl::core::data;
    using namespace pdl::core::endian;

    RawData data{ 4 };
    data.fill(0, std::byte(0xA0));
    data.fill(1, std::byte(0xB3));
    data.fill(2, std::byte(0xC5));
    data.fill(3, std::byte(0xDF));

    EngineInterface::UniquePtr beEngine = getEngine(Endian::big, data);

    ASSERT_EQ(beEngine->get(0), std::byte(0xDF));
    ASSERT_EQ(beEngine->get(1), std::byte(0xC5));
    ASSERT_EQ(beEngine->get(2), std::byte(0xB3));
    ASSERT_EQ(beEngine->get(3), std::byte(0xA0));

    EngineInterface::UniquePtr leEngine = beEngine->convert(Endian::little);
    ASSERT_EQ(leEngine->getEndianType(), Endian::little);

    ASSERT_EQ(leEngine->get(0), std::byte(0xDF));
    ASSERT_EQ(leEngine->get(1), std::byte(0xC5));
    ASSERT_EQ(leEngine->get(2), std::byte(0xB3));
    ASSERT_EQ(leEngine->get(3), std::byte(0xA0));

    ASSERT_EQ(beEngine->get(0), std::byte(0xA0));
    ASSERT_EQ(beEngine->get(1), std::byte(0xB3));
    ASSERT_EQ(beEngine->get(2), std::byte(0xC5));
    ASSERT_EQ(beEngine->get(3), std::byte(0xDF));
}

#include <common/data/RawData.hpp>
#include <gtest/gtest.h>


TEST(RawData, checkCorrectAppendWithoutAllocatedData)
{
    using namespace pdl::common::data;

    RawData data;
    ASSERT_FALSE(data);

    const auto memory = data.append(4);
    ASSERT_TRUE(data);
    ASSERT_NE(memory, nullptr);
    ASSERT_EQ(memory, data.get());
    ASSERT_EQ(data.size(), 4);
}

TEST(RawData, checkCorrectAppendWithAllocatedData)
{
    using namespace pdl::common::data;

    RawData data{4};
    ASSERT_TRUE(data);
    ASSERT_EQ(data.size(), 4);

    const auto memory = data.append(2);
    ASSERT_TRUE(data);
    ASSERT_NE(memory, nullptr);
    ASSERT_EQ(memory, data.get(4));
    ASSERT_EQ(data.size(), 6);
}

TEST(RawData, checkCorrectDestroy)
{
    using namespace pdl::common::data;

    RawData data{4};
    ASSERT_TRUE(data);
    ASSERT_EQ(data.size(), 4);

    data.destroy();
    ASSERT_FALSE(data);
}

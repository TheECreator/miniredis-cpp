#include "miniredis/database.hpp"

#include <gtest/gtest.h>

TEST(KeyValueStoreTest, SetAndGetValue)
{
    miniredis::KeyValueStore db;

    db.set("name", "Erik");

    auto value = db.get("name");

    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "Erik");
}

TEST(KeyValueStoreTest, MissingKeyReturnsNullopt)
{
    miniredis::KeyValueStore db;

    auto value = db.get("missing");

    EXPECT_FALSE(value.has_value());
}

TEST(KeyValueStoreTest, RemoveExistingKey)
{
    miniredis::KeyValueStore db;

    db.set("name", "Erik");

    EXPECT_TRUE(db.remove("name"));
    EXPECT_FALSE(db.exists("name"));
}

TEST(KeyValueStoreTest, RemoveMissingKey)
{
    miniredis::KeyValueStore db;

    EXPECT_FALSE(db.remove("missing"));
}

TEST(KeyValueStoreTest, SizeTracksNumberOfKeys)
{
    miniredis::KeyValueStore db;

    EXPECT_EQ(db.size(), 0);

    db.set("a", "1");
    db.set("b", "2");

    EXPECT_EQ(db.size(), 2);
}

TEST(KeyValueStoreTest, ClearRemovesEverything)
{
    miniredis::KeyValueStore db;

    db.set("a", "1");
    db.set("b", "2");

    db.clear();

    EXPECT_EQ(db.size(), 0);
}
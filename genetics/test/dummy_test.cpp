#include <gtest/gtest.h> 

class DummyTest : public ::testing::Test {};

TEST_F(DummyTest, initializationTest) {
    SUCCEED();
}


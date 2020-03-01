#include <gtest/gtest.h>

#include <evolution/map.hpp>

struct map_test : public ::testing::Test {
    std::ofstream configuration_file;
    static constexpr auto configuration_file_path = "config.map";

    void SetUp() override {
        configuration_file.open(configuration_file_path);
        configuration_file << "Cracow Warsaw 50" << std::endl;
        configuration_file << "Warsaw Wroclove 150" << std::endl;
        configuration_file << "Wroclove Cracow 900" << std::endl;
    }

    void TearDown() override {
        remove(configuration_file_path);
    }
};

TEST_F(map_test, calculate_absolute_distance) {

    //given
    auto map = std::make_shared<evolution::map>(configuration_file_path);

    //when
    auto absolute_distance = map->get_absolute_distance({1, 2, 0});

    //then
    ASSERT_EQ(1100, absolute_distance);
}
#include <gtest/gtest.h>
#include <graph/node.hpp>
#include <fstream>
#include <graph/graph.hpp>

struct adjacency_matrix_test : public ::testing::Test {

    std::ofstream configuration_file;
    static constexpr auto configuration_file_path = "config.map";

    void SetUp() override {
        configuration_file.open(configuration_file_path);
        configuration_file << "Cracow Warsaw 50" << std::endl;
        configuration_file << "Wroclove Warsaw 150" << std::endl;
        configuration_file << "Wroclove Cracow 900" << std::endl;
        configuration_file << "Katowice Cracow 70" << std::endl;
        configuration_file << "Katowice Warsaw 93" << std::endl;
        configuration_file << "Katowice Wroclove 82" << std::endl;
        configuration_file << "Cairo Lodz 900" << std::endl;
        configuration_file << "Katowice Lodz 70" << std::endl;
        configuration_file << "New_Mexico Warsaw 93" << std::endl;
        configuration_file << "Cairo Wroclove 82" << std::endl;
        configuration_file << "Wroclove New_Mexico 900" << std::endl;
        configuration_file << "Tarnow Cracow 70" << std::endl;
        configuration_file << "Katowice Tarnow 93" << std::endl;
        configuration_file << "Tarnow Wroclove 82" << std::endl;
        configuration_file << "Bilgoraj Cracow 900" << std::endl;
        configuration_file << "Katowice Bilgoraj 70" << std::endl;
        configuration_file << "Rzeszow Warsaw 93" << std::endl;
        configuration_file << "Rzeszow Wroclove 82" << std::endl;
        configuration_file.close();
    }

    void TearDown() override {
        remove(configuration_file_path);
    }

};



TEST_F(adjacency_matrix_test, configuration_file_reading) {

    //given

    //when
    auto graph = std::make_shared<graph::graph>(configuration_file_path);

    //then
    ASSERT_EQ(graph->get_weight("Cracow", "Warsaw"), 50);
    ASSERT_EQ(graph->get_weight("Katowice", "Warsaw"), 93);
    ASSERT_EQ(graph->get_weight("Cairo", "Wroclove"), 82);
    ASSERT_EQ(graph->get_nodes_count(), 10);

}


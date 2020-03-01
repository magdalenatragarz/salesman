#include <graph/graph.hpp>

namespace graph {

graph::graph(std::string const& configuration_file){
    adjacency_matrix = std::make_shared<matrix>();
    from_file(configuration_file);
}


int graph::get_weight(int source, int destination) const {
    return adjacency_matrix->get(source, destination);
}


int graph::get_nodes_count() const {
    return adjacency_matrix->get_dimension();
}


void graph::from_file(std::string const& path) {
    auto recipe = read_from_file(path);
    auto edges = deserialize(recipe);
    for (auto & edge : edges) {
        add_node(edge->get_source());
        add_node(edge->get_destination());
        add_edge(edge);
    }
}


std::string graph::read_from_file(std::string const& path) {
    auto file = std::ifstream(path);
    if (!file)
        throw std::logic_error("File does not exist");

    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}


std::vector<std::shared_ptr<edge>> graph::deserialize(std::string content) {
    auto content_stream = std::istringstream(content);
    auto line = std::string();
    auto edges = std::vector<std::shared_ptr<edge>>();

    while (std::getline(content_stream, line)) {
        if (is_comment(line) || line.empty())
            continue;
        edges.push_back(create_edge(line));
    }
    return edges;
}


std::shared_ptr<edge> graph::create_edge(std::string line) {
    auto [source, destination, weight] = parse_edge_components(line);
    return std::make_shared<edge>(source, destination, weight);
}


std::tuple<std::shared_ptr<node>, std::shared_ptr<node>, int> graph::parse_edge_components(std::string line) {
    auto edges_stream = std::istringstream(line);
    auto edge_component = std::string();
    auto edge_component_vector = std::vector<std::string>();

    while( edges_stream >> edge_component )
        edge_component_vector.push_back(edge_component);

    auto source = std::make_shared<node>(edge_component_vector[0]);
    auto destination = std::make_shared<node>(edge_component_vector[1]);
    auto weight = std::stoi(edge_component_vector[2]);

    return std::make_tuple<std::shared_ptr<node>,
            std::shared_ptr<node>, int>(std::move(source), std::move(destination), std::move(weight));
}


void graph::add_node(std::shared_ptr<node> node) {
    if (!node_exists(node)) {
        nodes_names.push_back(node->get_name());
    }
}


void graph::add_edge(std::shared_ptr<edge> edge) {
    auto x = get_position(edge->get_source()->get_name());
    auto y = get_position(edge->get_destination()->get_name());
    adjacency_matrix->set(x, y, edge->get_weight());
}

bool graph::node_exists(std::shared_ptr<node> node) {
    return std::find(nodes_names.begin(), nodes_names.end(), node->get_name()) != nodes_names.end();
}


bool graph::is_comment(std::string const& line) {
    auto constexpr comment_marker = "//";
    auto constexpr position = 0;

    return (line.rfind(comment_marker, position) == 0);
}


int graph::get_position(std::string const& node_name) {
    auto it = std::find(nodes_names.begin(), nodes_names.end(), node_name);
    return std::distance(nodes_names.begin(), it);
}

}
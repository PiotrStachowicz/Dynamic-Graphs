#include "DynamicGraph.hpp"

/// @brief Creates MST for dynamic graph
/// @param start name of the starting node
/// @return DynamicGraph in form of a MST tree
DynamicGraph DynamicGraph::MST(const std::string &start) {
    {
        using namespace std;
        DynamicGraph result{};
        unordered_map<string, bool> visited{};
        priority_queue<tuple<string, string, double>, vector<tuple<string, string, double>>, CompareEdge> PQ{};
        if(E.contains(start)){
            result.addNode(start);
            visited[start] = true;
            for(const auto& edge : E[start]) PQ.emplace(start, edge.first, edge.second);
        }
        while (!PQ.empty()){
            const auto [from, to, weight] = PQ.top();
            PQ.pop();
            if(visited[to]) continue;
            result.addNode(to);
            visited[to] = true;
            result.addEdge(from, to, weight);
            for(const auto& edge : E[to]){
                PQ.emplace(to, edge.first, edge.second);
            }
        }
        return result;
    }
}

/// @brief Used to show the graph
std::ostream &operator<<(std::ostream &os, const DynamicGraph &graph) {
    for(const auto& V : graph.E){
        os << V.first << " ";
        for(const auto& edge : V.second){
            os << edge.first << "(" << edge.second << ") | ";
        }
        os << std::endl;
    }
    return os;
}

/// @brief Used to change weight of a edge in a graph
/// @param from name of the start of edge
/// @param to name of the end of edge
/// @param weight new weight of the edge
void DynamicGraph::changeWeight(const std::string &from, const std::string &to, double weight) {
    if(E.contains(from))
        std::find_if(E[from].begin(), E[from].end(),
                     [=](std::pair<std::string, double>& element) { return element.first == to; }
            )->second = weight;
}

/// @brief Used to remove edge from the graph
/// @param from name of the start of edge
/// @param to name of the end of edge
void DynamicGraph::removeEdge(const std::string &from, const std::string &to) {
    if(E.contains(from) && E.contains(to))
        E[from].remove_if(
                [=] (std::pair<std::string, double>& element) {
                    return element.first == to;
                });
}

/// @brief Used to remove the node from the graph
/// @param name of the node
void DynamicGraph::removeNode(const std::string &symbol) {
    if(E.contains(symbol)){
        for(const auto& V : E){
            removeEdge(V.first, symbol);

        }
        erase_if(E,
                        [=] (std::pair<const std::basic_string<char>, std::forward_list<std::pair<std::basic_string<char>, double>>>& element) {
                            return element.first == symbol; }
        );
    }
}


/// @brief Used to add node to the graph
/// @param symbol name of the new node
void DynamicGraph::addNode(const std::string &symbol) {
    if(!E.contains(symbol)) E[symbol] = {};
}

/// @brief Used to add edge to the graph
/// @param from name of the start of edge
/// @param to name of the end of edge
/// @param weight weight of the edge
void DynamicGraph::addEdge(const std::string &from, const std::string &to, double weight) {
    if(E.contains(from) && E.contains(to)) E[from].emplace_front(to,weight);
}

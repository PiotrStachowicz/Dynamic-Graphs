//Piotr Stachowicz
#ifndef UNTITLED1_GRAPHS_HPP
#define UNTITLED1_GRAPHS_HPP
#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <forward_list>

using EdgeMap = std::unordered_map<std::string, std::forward_list<std::pair<std::string, double>>>;

struct CompareEdge{
    bool operator()(const std::tuple<std::string, std::string, double>& elem1, const std::tuple<std::string, std::string, double>& elem2) const {
        return get<2>(elem1) >= get<2>(elem2);
    }
};

class DynamicGraph{
private:
    EdgeMap E{};
public:
    void addEdge(const std::string& from, const std::string& to, double weight);
    void removeEdge(const std::string& from, const std::string& to);
    void addNode(const std::string& symbol);
    void removeNode(const std::string& symbol);
    void changeWeight(const std::string& from, const std::string& to, double weight);
    friend std::ostream& operator<<(std::ostream& os, const DynamicGraph& graph);
    DynamicGraph MST(const std::string& start);
};

#endif //UNTITLED1_GRAPHS_HPP


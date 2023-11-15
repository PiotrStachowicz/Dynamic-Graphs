#include "DynamicGraph.hpp"

int main() {
    using namespace std;
    DynamicGraph dynamicGraph{};
    dynamicGraph.addNode("A");
    dynamicGraph.addNode("B");
    dynamicGraph.addNode("C");
    dynamicGraph.addNode("D");
    dynamicGraph.addNode("E");
    dynamicGraph.addNode("F");
    dynamicGraph.addEdge("A", "B", 3.0);
    dynamicGraph.addEdge("A", "C", 4.0);
    dynamicGraph.addEdge("B", "C", 2.0);
    dynamicGraph.addEdge("C", "D", 5.0);
    dynamicGraph.addEdge("D", "E", 3.5);
    dynamicGraph.addEdge("D", "F", 18.0);
    dynamicGraph.addEdge("B", "E", 8.0);
    dynamicGraph.addEdge("E", "F", 3.0);
    cout << dynamicGraph << endl;
    DynamicGraph MST = dynamicGraph.MST("A");
    cout << MST << endl;
    MST.removeNode("A");
    MST.changeWeight("D", "E", 3);
    MST.removeEdge("E", "F");
    cout << MST << endl;
    return 0;
}

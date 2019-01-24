#include <iostream>
#include "Graph.h"

int main() {
    Graph* graph = new Graph();
    for (int i = 0; i < 100; i++) {
        graph->addVertex(i);
    }
    for (int i = 1; i < 100; i++) {
        int a[] = {(rand() % i),(rand() % i),(rand() % i)};
        graph->connect((rand() % i), a, 3);
    }
    graph->print();
    cout << endl << endl;
    graph->depthCrawl(2);


    return 0;
}
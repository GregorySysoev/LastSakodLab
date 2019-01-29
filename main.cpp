#include <iostream>
#include "Graph.h"

int main() {
    Graph* g = new Graph();

    for (int i = 1; i < 10; i++) {
        g ->addVertex(i);
    }
    int a4[] = {1,5,6};
    g->connect(4,a4,3);
    int a5[] = {3,4,6};
    g->connect(5,a5,3);
    int a6[] = {2,3,4,5};
    g->connect(6,a6,4);
    int a7[] = {2,8};
    g->connect(7,a7,2);
    int a8[] = {1,2,7};
    g->connect(8,a8,3);
    int a9[] = {2,3};
    g->connect(9,a9,2);  int a1[] = {4,7,8};
    g->connect(1,a1,3);
    int a2[] = {6,7,8,9};
    g->connect(2,a2,4);
    int a3[] = {5,6,9};
    g->connect(3,a3,3);

    g->print();
    for (int i = 1; i < 10; i++) {
        g->RobertsFloresAlgoritml(i);
        cout << endl;
    }

    cout << endl << endl;
    for (int i = 1; i < 10; i++) {
        g->delVertex(2*i-1);
    }
    g->print();


    g->RobertsFloresAlgoritml(6);


    return 0;
}
#include <iostream>
#include "Graph.h"

int main() {
    Graph* g = new Graph();
    /*for (int i = 0; i < 10; i++) {
        g->addVertex(i);
    }
    for (int i = 1; i < 10; i++) {
        int a[] = {(rand() % i),(rand() % i),(rand() % i)};
        g->connect((rand() % i), a, 3);
    }
*/

    /*g->addVertex(0);
    g->addVertex(1);
    g->addVertex(2);
    g->addVertex(3);
    g->addVertex(4);
    g->addVertex(5);

    int a[] = {0, 1, 2, 3};
    g->connect(0, a, 4);
    g->connect(1, a, 4);
    g->connect(2, a, 4);
    g->connect(3, a, 4);

    g->connect(5,a,4);
    g->connect(4,a,4);
    g->print();
    cout << endl << endl;
    g->RobertsFloresAlgoritml(5);*/


    /*g->addVertex(0);
    g->addVertex(1);
    g->addVertex(2);
    g->addVertex(3);
    g->addVertex(4);
    g->addVertex(5);

    int b[] = {1};
    g->connect(0, b, 1);
    int c[] = {2};
    g->connect(1, c, 1);
    int q[] = {3};
    g->connect(2, q, 1);
    int e[] = {4};
    g->connect(3, e, 1);
    int w[] = {5};
    g->connect(4, w, 1);
    int t[] = {0};
    g->connect(5, t, 1);
    g->RobertsFloresAlgoritml(0);*/

    for (int i = 1; i < 10; i++) {
        g ->addVertex(i);
    }
    int a1[] = {4,7,8};
    g->connect(1,a1,3);
    int a2[] = {6,7,8,9};
    g->connect(2,a2,4);
    int a3[] = {5,6,9};
    g->connect(3,a3,3);
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
    g->connect(9,a9,2);
    g->print();

    g->RobertsFloresAlgoritml(3);
    cout << endl << endl;
    for (int i = 1; i < 10; i++) {
        g->delVertex(2*i);
    }
    g->print();
    g->RobertsFloresAlgoritml(3);

    return 0;
}
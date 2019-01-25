//
// Created by User on 22.12.2018.
//

#ifndef LASTSAKODLAB_HEADER_H
#define LASTSAKODLAB_HEADER_H

#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include <set>

using namespace std;

class ListBig;
class listSmall {
private:
    int index;
    listSmall* right;
    ListBig* self;
public:
    friend class ListBig;
    friend class Graph;
    explicit listSmall(int idx);
    ~listSmall();
};

class ListBig {
private:
    bool check = false;
    int index;
    listSmall* right;
    ListBig* down;
public:
    friend class Graph;
    friend class listSmall;
    explicit ListBig(int idx);
    void connectVertex(ListBig* s);
    void disconnectVertex(ListBig* s);
    listSmall* findRight(int idx);
    ~ListBig();
};

class Graph {
private:
    ListBig* root;
    ListBig* search(int idx);
public:
    Graph();
    void addVertex(int idx);
    void print();
    void connect(int idx, int adjacent[], int sizeAdj);
    void disconnect(int idx, int adjacent[], int sizeAdj);
    void delVertex(int idx);
    int countVertex();
    void depthCrawl(int idx);
    void errors(int idx);
    void flagsOFF();
    void RobertsFloresAlgoritml(int idx);
};

#endif //LASTSAKODLAB_HEADER_H

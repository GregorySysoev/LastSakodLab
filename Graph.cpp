//
// Created by User on 22.12.2018.
//

#include <algorithm>
#include "Graph.h"

//listSmall

listSmall::listSmall(int idx) {
    index = idx;
    right = nullptr;
    self = nullptr;
}

listSmall::~listSmall() {
    right = nullptr;
    self = nullptr;
}

//ListBig

ListBig::ListBig(int idx) {
    index = idx;
    right = nullptr;
    down = nullptr;
}

ListBig* Graph::search(int idx) {
    ListBig* cur = root;
    while (nullptr != cur) {
        if (cur->index == idx) return cur;
        cur=cur->down;
    }
    errors(2);
    return nullptr;
}

void ListBig::connectVertex(ListBig* s) {
    listSmall* proverka = this->right;
    while (proverka != nullptr) {
        if (proverka->index == s->index) return;
        proverka=proverka->right;
    }
    listSmall* curListSmall = new listSmall(s->index);
    listSmall* a = this->right;
    this->right = curListSmall;
    curListSmall->right = a;
    curListSmall->self = s;
}

listSmall* ListBig::findRight(int idx) {
    listSmall* res = nullptr;
    listSmall* cur = this->right;
    while (cur != nullptr) {
        if (cur->index == idx) {
            res = cur;
            break;
        }
        cur = cur->right;
    }
    return res;
}

ListBig::~ListBig(){
    this->down = nullptr;
    listSmall* del1 = this->right;
    listSmall* del2 = this->right;
    while (del1 != nullptr) {
        del2 = del1;
        del1=del1->right;
        delete del2;
    }
}

void ListBig::disconnectVertex(ListBig *s) {
    listSmall* find = this->findRight(s->index);
    if (find != nullptr) {
        listSmall* before = this->right;
        if (find != before) {
            while ((before->right != nullptr) && (before->right->index != s->index)) {
                before = before->right;
            }
            before->right=find->right;
        } else this->right = find->right;
//        delete find; TODO Тут может сломаться!!
    }
}
// GRAPH

Graph::Graph() {
    root = nullptr;
}

void Graph::addVertex(int idx) {
    ListBig* next = root;
    ListBig* cur = root;
    while (cur != nullptr) {
        if (cur->index == idx) { errors(1); return; }
        cur = cur->down;
    }
    root = new ListBig(idx);
    root->down = next;
}

void Graph::print() {
    cout << endl;
    ListBig* cur = root;
    while (cur != nullptr) {
        listSmall* a = cur->right;
        cout << cur->index;
        while (a != nullptr) {
            cout<< " - " << a->index;
            a = a->right;
        }
        cout << endl;
        cur = cur->down;
    }
}

void Graph::connect(int idx, int adjacent[], int sizeAdj) {
    ListBig* cur = search(idx);
    if (cur != nullptr) {
        for (int i = 0; i < sizeAdj; i++) {
            ListBig* adjVert = search(adjacent[i]);
            if ((adjVert != nullptr) && (adjacent[i] != idx)) {
                if (cur->findRight(adjacent[i]) == nullptr) {
                    cur->connectVertex(adjVert);
                    adjVert->connectVertex(cur);
                }
                else errors(3);
            }
        }
    }
}

int Graph::countVertex() {
    int count = 0;
    ListBig* cur = nullptr;
    cur=this->root;
    while (cur != nullptr) {
        count++;
        cur=cur->down;
    }
    return count;
}

void Graph::errors(int idx) {
    switch (idx)
    {
        case 1:
            cout << "ERROR1 :: error adding vertex : Such vertices are in the graph" << endl;
            break;
        case 2:
            cout << "ERROR2 :: vertex : not found" << endl;
            break;
        case 3:
            cout << "ERROR3 :: vertex : has already connected" << endl;
            break;
        default:
            cout << endl << "ERROR" << endl;
            break;
    }
}

void Graph::disconnect(int idx, int *adjacent, int sizeAdj) {
    ListBig* cur = search(idx);
    if (cur != nullptr) {
        for (int i = 0; i < sizeAdj; i++) {
            ListBig* adjVer = search(adjacent[i]);
            if ((adjVer != nullptr)&&(adjacent[i] != idx)) {
                listSmall* a = cur->findRight(adjacent[i]);
                if (a != nullptr) {
                    cur->disconnectVertex(adjVer);
                    adjVer->disconnectVertex(cur);
                }
            }
        }
    }
}

void Graph::delVertex(int idx) {
    ListBig* delElem = search(idx);
    if (delElem != nullptr) {

        int a[] = {delElem->index};
        listSmall* i = delElem->right;
        while (i != nullptr) {
            this->disconnect(i->index, a, 1);
            i = i->right;
        }

        ListBig* cur = root;
        if (cur->index == idx) {
            root = cur->down;
        }
        else {
            while (cur->down->index != idx) {
                cur= cur->down;
            }
            cur->down = delElem->down;
        }


        delete delElem;
    }
}

void Graph::depthCrawl(int idx) {
    flagsOFF();
    int size = countVertex();
    if (size != 0) {

        vector<int>* checked = new vector<int>;
        stack<ListBig*>* queueListBig = new stack<ListBig*>;

        ListBig* cur = this->root;
        ListBig* primeList = nullptr;
        primeList = search(idx);
        ListBig* obhod = nullptr;
        listSmall *rightOfVertex = nullptr;

        if (primeList == nullptr) {
            primeList = this->root;
            idx = root->index;
        }

        if (primeList != nullptr) {
            cout << idx << " ";
            checked->push_back(idx);
            primeList->check = true;
            rightOfVertex = primeList->right;
            while (rightOfVertex != nullptr) {
                queueListBig->push(rightOfVertex->self);
                rightOfVertex = rightOfVertex->right;
            }
        }

        while (checked->size() != size) {
//            берём вершину из стека

            if (!queueListBig->empty()) {
                obhod = queueListBig->top();
                queueListBig->pop();
                if (obhod->check == true) continue;
            } else
            {
                if (cur == nullptr){
                    exit;
                }
                else {
                    while ((cur != nullptr) && (cur->check == true)) {
                        cur=cur->down;
                    }
                    if (cur != nullptr) {
                        obhod = cur; // если стек пуст, берём следующий элемент из списка
                        cur = cur->down;
                    }
                    else {
                        exit;
                    }
                }
            }

            rightOfVertex = obhod->right;
            while (rightOfVertex != nullptr) {
                if (rightOfVertex->self->check != true) {
                    queueListBig->push(rightOfVertex->self);
                }
                rightOfVertex = rightOfVertex->right;
            }

            checked->push_back(primeList->index); // помечаем вершину
            obhod->check = true;
            cout << obhod->index << " ";
        }

    }


}

void Graph::flagsOFF() {
    ListBig* cur = root;
    while (cur != nullptr) {
        cur->check = false;
        cur = cur->down;
    }
}

void Graph::RobertsFloresAlgoritml(int idx) {
    flagsOFF();
    ListBig* soughtFor = search(idx);

    if (soughtFor != nullptr) { // если вершина найдена
        int n = countVertex();
        stack<ListBig*>* S = new stack<ListBig*>;
        if (soughtFor->right == nullptr) {
            cout << "Graph has no hamilton cycle";
            return;
        } else {
            S->push(soughtFor);
            soughtFor->check = true;
        }
        ListBig* ListBigWhile = nullptr;
        listSmall* listSmallWhile = nullptr;
        int notThat = 0;
        bool wasReturn = false;

        while (S->size() != 0) {
            if (wasReturn) {
                wasReturn = false;
                // получаем предыдущую вершину
                if (S->empty() != true) ListBigWhile = S->top();
                listSmallWhile = ListBigWhile->findRight(notThat)->right; // получаем след элемент в lists
                goto back;
            } else {
                ListBigWhile = S->top(); // получаем добавленную ранее вершину
                listSmallWhile = ListBigWhile->right;
                goto front;
            }
            ;
            front:
            while ((listSmallWhile != nullptr) && (listSmallWhile->self->check)) {
                listSmallWhile = listSmallWhile->right;
            }
            if (listSmallWhile == nullptr) {
                if ((S->size() == n) && (ListBigWhile->findRight(idx) != nullptr)) {
                    while (S->size() != 0) { // Печать
                        cout << S->top()->index << " ";
                        S->pop();
                    }
                    return;
                } else {
                    notThat = ListBigWhile->index;
                    ListBigWhile->check = false;
                    S->pop();
                    wasReturn = true;
                    continue;
                }
            } else {
                listSmallWhile->self->check = true;
                S->push(listSmallWhile->self);
                continue;
            }
            back:
                while ((listSmallWhile != nullptr) && (listSmallWhile->self->check)) {
                    listSmallWhile = listSmallWhile->right;
                }
                if (listSmallWhile == nullptr) {
                    notThat = ListBigWhile->index;
                    ListBigWhile->check = false;
                    S->pop();
                    wasReturn = true;
                    continue;
                } else {
                    listSmallWhile->self->check = true;
                    S->push(listSmallWhile->self);
                    continue;
                }
            ;
        }
        cout << "Graph has no hamilton cycle";
    }
}

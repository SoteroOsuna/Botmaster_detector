//
//  Grafo.hpp
//  ActividadIntegradora4v2
//
//  Created by Sotero Osuna on 23/11/20.
//

#ifndef Grafo_hpp
#define Grafo_hpp

#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <queue>
using namespace std;


template <class T>
struct Node {
  T content;
  string label;
};

struct Edgep {
    int node;
    time_t tiempo;
    string razon;
    int weight;
};


template <class T>
class Graph{
  public:
      Graph(int nodes, int edges, int init);
      Graph(int nodes, int edges);
      ~Graph();
        void add(int n1, int n2, int weight);
        void add(int n1, int n2, time_t tiempo, string razón);
        int getIndex(T content);
        void add_content(int, T);
        void show();
        void showNodes();
        void DFS();
        void DFS(int, vector<bool>&);
        void BFS();
        void BFS(int s,vector<bool>& flags);
        void maxFanOut();

  private:
    
    vector<list<Edgep>> adyList;
    vector<Node<T>> nodes;
    int n2;
    int init;
};

#endif /* Grafo_hpp */

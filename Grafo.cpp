//
//  Grafo.cpp
//  ActividadIntegradora4v2
//
//

#include "Grafo.hpp"
#include <iostream>
#include <string>
#include "string.h"
#include "stdio.h"


template <class T>
Graph<T>::Graph(int n1, int n2, int init) {
  this->init = init;
  nodes = vector<Node<T>>(n1+init);
  adyList = vector<list<Edgep>>(n1+init);
  
}

template <class T>
Graph<T>::~Graph() {
    
}

template <class T>
void Graph<T>::add(int n1, int n2, int weight) {
    Edgep newEdge;
    newEdge.node = n2;
    newEdge.weight = weight;
    adyList[n1].push_back(newEdge);

}

template <class T>
void Graph<T>::add(int n1, int n2, time_t tiempo, string razon) {
    Edgep newEdge;
    newEdge.node = n2;
    newEdge.tiempo = tiempo;
    newEdge.razon = razon;
    adyList[n1].push_back(newEdge);

}

//Complejidad O(n), ya que itera por los nodos uno por uno hasta llegar al que tiene el contenido que se busca
template <class T>
int Graph<T>::getIndex(T content) {
    int currentIndex = 0;
    for(int i = 0; ; i++) {
        if(nodes[i].content == content) {
            currentIndex = i;
            break;
        }
    }
    return currentIndex;
}

template <class T>
void Graph<T>::add_content(int n, T content) {
    nodes[n].content = content;
}

//Complejidad O(V+E) V son nodos y E son aristas, ya que pasa por cada nodo y su propia lista de aristas
template <class T>
void Graph<T>::show() {
    for(int i = init; i < int(nodes.size()); i++) {
        cout << i;
        for (auto x : adyList[i]) {
            cout << " -> " << x.node;
        }
    cout << endl;
  }
}

//Complejidad O(n), pasa por cada nodo
template <class T>
void Graph<T>::showNodes() {
    for(int i = 0; i < int(nodes.size()); i++) {
        cout << nodes[i].content << ": " << adyList[i].size() << endl;
    }
}

//Complejidad O(V+E) V son nodos y E son aristas, ya que pasa por cada nodo y su propia lista de aristas
template <class T>
void Graph<T>::DFS() {
    vector<bool> mark(nodes.size(), false);
    
    DFS(init, mark);
}

template <class T>
void Graph<T>::DFS(int n , vector<bool>& flags) {
    
    cout << n << " ";

    flags[n] = true;
    
    list<Edgep> currAdyList = adyList[n];
    
    for (auto x : currAdyList) {
        if (!flags[x.node]) {
            DFS(x.node, flags);
        }
    }
    
}

//Complejidad O(V+E) V son nodos y E son aristas, ya que pasa por cada nodo y su propia lista de aristas
template <class T>
void Graph<T>::BFS() {
  vector<bool> mark(nodes.size(), false);
  BFS(init,mark);
  cout<<endl;

}
template <class T>
void Graph<T>::BFS(int s,vector<bool>& flags) {


  
    queue<int> q;
    
    flags[s]=true;
    q.push(s);
    while(!q.empty())
    {
        
        s = q.front();
        cout << s << " ";
        q.pop();
        list<Edgep> currAdyList = adyList[s];
        for (auto i = currAdyList.begin(); i != currAdyList.end(); ++i) {
        if (!flags[i->node]) {
          flags[i->node]=true;
          q.push(i->node);
           
        }
    }
  
        
        
    }
    
}

//Complejidad O(n), explora cada nodo para almacenar los valores máximos en un vector de indices 
template <class T>
void Graph<T>::maxFanOut() {
    int currentMax = 0;
    vector<int> indices;
    for(int i = 1; i < int(nodes.size()); i++) {
       
        if(int(adyList[i].size()) > int(adyList[currentMax].size())) {
            indices.clear();
            currentMax = i;
            indices.push_back(i);
        }
        if(int(adyList[i].size()) == int(adyList[currentMax].size())) {
            indices.push_back(i);
        }
    }
    cout << adyList[currentMax].size() << ": "<< endl;
    for(int i = 1; i < indices.size(); i++) {
      int index = indices[i];
      cout << nodes[index].content << endl;
    }
}

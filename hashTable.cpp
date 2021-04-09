//
//  hashTable.cpp
//  ActividadIntegradora5
//
//  Created by Sotero Osuna on 30/11/20.
//

#include "hashTable.hpp"

Hash::Hash() {
    for(int i = 0; i < size; i++) {
        hashTable[i] = new node;
        hashTable[i]->ip = "0.0.0.0";
        hashTable[i]->index = 0;
        hashTable[i]-> next = NULL;
    }
}

int Hash::hashFunction(string key) {
    int sum = 0;
    for(int i = 0; i < key.size(); i++) {
        sum += (int)key[i];
    }
    return sum % size;
}

// Complejidad aproximada de O(1), ya que se basa en claves para añadir contenido en vez de explorar el contenedor
void Hash::add(string ip, int index) {
    int hashIndex = hashFunction(ip);
    
    if(hashTable[hashIndex]->ip == "0.0.0.0") {
        hashTable[hashIndex]->ip = ip;
        hashTable[hashIndex]->index = index;
    } else {
        
        node* ptr = hashTable[hashIndex];
        node* newPtr = new node;
        newPtr->ip = ip;
        newPtr->index = index;
        newPtr->next = NULL;
        
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        
        ptr->next = newPtr;
        
    }
    
}

// Complejidad aproximada de O(1), ya que se basa en claves para buscar el contenido en vez de hacer una busqueda secuencial
int Hash::getIndex(string ip) {
    int hashIndex = hashFunction(ip);
    bool foundIP = false;
    
    node* ptr = hashTable[hashIndex];
    while (ptr != NULL) {
        if(ptr->ip == ip) {
            foundIP = true;
            return ptr->index;
        }
        ptr = ptr->next;
    }
    return 0;
}

//
//  hashTable.hpp
//  ActividadIntegradora5
//
//  Created by Sotero Osuna on 30/11/20.
//

#ifndef hashTable_hpp
#define hashTable_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Hash {
    private:
        static const int size = 15000;
    
        struct node {
            string ip;
            int index;
            node* next;
        };
        
        node* hashTable[size];
    

    public:
        Hash();
        int hashFunction(string key);
        void add(string ip, int index);
        int getIndex(string ip);
    
    
};

#endif /* hashTable_hpp */

//
//  utlierias.cpp
//  ActividadIntegradora4v2
//
//  Created by Sotero Osuna on 23/11/20.
//

#include "utlierias.hpp"
#include "hashTable.hpp"

time_t convierte(string mes, string dia, string tiempo) {
    tm ts;
    memset(&ts, 0, sizeof(struct tm));
    ts.tm_isdst = 1;
    string tss = "2019 " + mes + " " + dia + " " + tiempo;
    strptime(tss.c_str(),"%Y %b %d %H:%M:%S", &ts);
    //ts.tm_year = 119;
    time_t fechaHora = mktime(&ts);
    
    return fechaHora;
}

Graph<string> cargaBitacora4(string archivo) {
    
    ifstream f;
    
    f.open(archivo);
    
    string nodes, edges;
    if(f.is_open()) {

        getline(f, nodes, ' ');
        f >> edges;
        
        Graph<string> grafo = Graph<string>(stoi(nodes), stoi(edges), 0);
        Hash hashGrafoIP = Hash();
    //    n <= stoi(nodes)
        for(int n = 0; n < stoi(nodes); n++) {
            string contenido;
            f >> contenido;
            grafo.add_content(n, contenido);
            hashGrafoIP.add(contenido, n);
        }
        
        for(int e = 0; e < stoi(edges); e++) {
            string mes, dia, tiempo, ip1, ip2, razon, t;
            getline(f, mes, ' ');
            getline(f, dia, ' ');
            getline(f, tiempo, ' ');
            time_t fechaHora = convierte(mes, dia, tiempo);
            getline(f, ip1, ':');
            getline(f, t, ' ');
            getline(f, ip2, ':');
            getline(f, t, ' ');
            getline(f, razon);
            
           // cout << mes << " "<< dia << " " << tiempo << " " << ip1 << " " << ip2  << " " << razon << endl;
            int ip1Integer = hashGrafoIP.getIndex(ip1);
            int ip2Integer = hashGrafoIP.getIndex(ip2);
            Edgep newEdge;
            grafo.add(ip1Integer, ip2Integer, fechaHora, razon);
        }
        f.close();
        

        return grafo;

    } else {
        cout << "error al abrir el archivo" << endl;
    }
    return Graph<string>(0,0,0);
}

#pragma once
#include "Estructuras.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class Archivo {

    string texto;
    string titulo;




};



class Repositorio
{
private:
    

    ListaDoble<Archivo> lista;
    
    char main[256]; //directorio principal

public:



    Repositorio() {
        
    }
    ~Repositorio();

};


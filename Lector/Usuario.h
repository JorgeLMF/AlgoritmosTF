#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class usuario
{
	string nombre;
	string correo;
	
public:

	usuario(string nombre, string correo) {}

	void ingreso_datos()
	{
		cout << "Usuario: ";
		cin >> nombre;

		cout << "Correo electronico: ";
		cin >> correo;
	}

	string get_name() { return nombre; }

	string get_correo() { return correo; }

};
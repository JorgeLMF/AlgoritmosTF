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

	usuario(string nombre, string correo) {
		this->nombre = nombre;
		this->correo = correo;

	}
	// mensaje sobre edicion del documento
	string get_datos()
	{
		return nombre + " edito parte del documento " + correo;
	}

	void set_name(string nombre) { this->nombre = nombre; }

	void set_correo(string correo) { this->correo = correo; }

	string get_name() { return nombre; }

	string get_correo() { return correo; }

};
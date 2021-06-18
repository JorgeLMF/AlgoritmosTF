#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include<msclr\marshal_cppstd.h>

using namespace std;
using namespace System::Windows::Forms;
using namespace System;
//using namespace System::IO;

public ref class Editor
{
private:
	fstream *archivo= new fstream;
	TextBox^ textbox= gcnew TextBox();
	string* file_name = new string;
	string* s = new string;
	string* line = new string; //strings totales
	String^ str;
	char* arr;
public:
	Editor(string *file, TextBox^ box) {
		textbox = box;
		file_name = file;
	}
	~Editor() {};
	void abrir() {
		textbox->Text="";
		archivo->open(file_name->c_str(), ios::in);
		if (archivo->is_open()) {
			while (getline(*archivo, *line)) {
				/**s += *line + "\n";*/
				str = gcnew String(line->c_str());
				textbox->AppendText(str);
				textbox->AppendText(Environment::NewLine);
			}
			/*getline(*archivo, *s);*/
			cout << "Se leyo el archivo\n";
			cout << *s;
			archivo->close();
		}
		else {
			cout << "Error al abrir el archivo" << endl;
		}
		///*getline(*archivo, *s);*/
		//cout << "Se leyo el archivo\n";
		//cout << *s;
		//String^ str = gcnew String(s->c_str());
		//textbox->Text=str;
		//archivo->close();
	}
	void guardar() {
		archivo->open(file_name->c_str(), ios::out);
		if (archivo->is_open()) {
			msclr::interop::marshal_context context;
			str = gcnew String(textbox->Text);
			*archivo << context.marshal_as<string>(str);
			cout << "Se guardo el archivo\n";
			archivo->close();
		}
		else {
			cout << "Error al guardar" << endl;
		}
	}
};


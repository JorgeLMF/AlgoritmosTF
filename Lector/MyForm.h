#pragma once
#include "Editor.h"
namespace Lector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			nombre = new string("texto.txt");
			editor = gcnew Editor(nombre, textBox1);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Button^ Load;
	private: System::Windows::Forms::Button^ Guardar;

		   Editor^ editor;

		   string* nombre;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Load = (gcnew System::Windows::Forms::Button());
			this->Guardar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(1292, 620);
			this->textBox1->TabIndex = 0;
			this->textBox1->WordWrap = false;
			// 
			// Load
			// 
			this->Load->Location = System::Drawing::Point(1321, 26);
			this->Load->Name = L"Load";
			this->Load->Size = System::Drawing::Size(75, 23);
			this->Load->TabIndex = 1;
			this->Load->Text = L"Abrir";
			this->Load->UseCompatibleTextRendering = true;
			this->Load->UseVisualStyleBackColor = true;
			this->Load->Click += gcnew System::EventHandler(this, &MyForm::Load_Click);
			// 
			// Guardar
			// 
			this->Guardar->Location = System::Drawing::Point(1321, 72);
			this->Guardar->Name = L"Guardar";
			this->Guardar->Size = System::Drawing::Size(75, 23);
			this->Guardar->TabIndex = 2;
			this->Guardar->Text = L"Guardar";
			this->Guardar->UseVisualStyleBackColor = true;
			this->Guardar->Click += gcnew System::EventHandler(this, &MyForm::Guardar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1443, 644);
			this->Controls->Add(this->Guardar);
			this->Controls->Add(this->Load);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Deactivate += gcnew System::EventHandler(this, &MyForm::MyForm_Deactivate);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Load_Click(System::Object^ sender, System::EventArgs^ e) {
		editor->abrir();
	}
	private: System::Void Guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		editor->guardar();
	}
private: System::Void MyForm_Deactivate(System::Object^ sender, System::EventArgs^ e) {
	std::string key;
	cout << "Para pausar la consola ingrese 'pause'\n";
	do
	{
		cout << ">> ";
		cin >> key;
		if (key != "pause") {
			*nombre = key;
		}
	} while (key != "pause");
	/*while (key != "pause") {
		cout << ">> ";
		cin >> key;
		if (key != "pause") {
			*nombre = key;
		}
	}*/
}
};
}

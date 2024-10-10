#pragma once
#include "Kasier.h"
#include "TicketList.h"
#include "Tournament.h"
#include "Match.h"
#include "Financial.h"
#include "Account.h"
#include "Organization.h"
#include <msclr\marshal_cppstd.h>

namespace KursovaInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(179, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(161, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(179, 142);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(161, 21);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(65, 212);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Касир\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(345, 212);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 34);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Організатор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(179, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Логін";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(179, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 15);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Пароль";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 301);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MyForm";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ login = textBox1->Text;
		String^ password = textBox2->Text;
		Account account("tournament.db");

		// Перевірка логіну та паролю
		if (account.login(marshal_as<std::string>(login), marshal_as<std::string>(password))) 
		{
			std::string userType = account.getUserType(marshal_as<std::string>(login));
			if (userType == "Kasier") 
			{
				// Відкриття вікна для касира
				Kasier^ f2 = gcnew Kasier();
				f2->Show();
				MyForm::Hide();
			}
			else 
			{
				MessageBox::Show("Unknown user type.", "Error");
			}
		}
		else 
		{
			MessageBox::Show("Incorrect login or password.", "Error");
		}
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ login = textBox1->Text;
	String^ password = textBox2->Text;
	Account account("tournament.db");

	// Перевірка логіну та паролю
	if (account.login(marshal_as<std::string>(login), marshal_as<std::string>(password))) 
	{
		// Отримання типу користувача
		std::string userType = account.getUserType(marshal_as<std::string>(login));

		if (userType == "Organization") 
		{
			Organization^ f2 = gcnew Organization();
			f2->Show();
			MyForm::Hide();
		}
		else 
		{
			// Помилка: невідомий тип користувача
			MessageBox::Show("Unknown user type.", "Error");
		}
	}
	else 
	{
		// Помилка: невірний логін або пароль
		MessageBox::Show("Incorrect login or password.", "Error");
	}
}
};
}

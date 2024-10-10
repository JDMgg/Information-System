#pragma once
#include "Tournament.h"
#include "Match.h"
#include "Financial.h"
#include "Account.h"
#include <msclr\marshal_cppstd.h>
#include <sqlite3.h>
#include "Financial.h"


extern std::string utf8summ;

namespace KursovaInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для StartSales
	/// </summary>
	public ref class StartSales : public System::Windows::Forms::Form
	{
	public:
		StartSales(void)
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
		~StartSales()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ SummBox;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ AddToTable;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;


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
			this->SummBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->AddToTable = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SummBox
			// 
			this->SummBox->Location = System::Drawing::Point(12, 36);
			this->SummBox->Name = L"SummBox";
			this->SummBox->Size = System::Drawing::Size(231, 20);
			this->SummBox->TabIndex = 0;
			this->SummBox->TextChanged += gcnew System::EventHandler(this, &StartSales::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 86);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(231, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &StartSales::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 133);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(231, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &StartSales::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Сума ( доступний формат 100.00 )";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Дата транзакції (рр-мм-дд)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Тип транзакції (Refund, Paid)";
			// 
			// AddToTable
			// 
			this->AddToTable->Location = System::Drawing::Point(12, 226);
			this->AddToTable->Name = L"AddToTable";
			this->AddToTable->Size = System::Drawing::Size(231, 23);
			this->AddToTable->TabIndex = 7;
			this->AddToTable->Text = L"Зберігти";
			this->AddToTable->UseVisualStyleBackColor = true;
			this->AddToTable->Click += gcnew System::EventHandler(this, &StartSales::AddToTable_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 181);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(231, 20);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &StartSales::textBox1_TextChanged_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Напишіть ID турніру";
			// 
			// StartSales
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(257, 261);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->AddToTable);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->SummBox);
			this->Name = L"StartSales";
			this->Text = L"StartSales";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void AddToTable_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ tournamentIdStr = textBox1->Text;
		String^ amountStr = SummBox->Text;
		String^ date = textBox2->Text;
		String^ type = textBox3->Text;

		int tournamentId;
		if (Int32::TryParse(tournamentIdStr, tournamentId)) 
		{
			double amount;
			if (Double::TryParse(amountStr, amount)) 
			{
				std::string stdDate = marshal_as<std::string>(date);
				std::string stdType = marshal_as<std::string>(type);

				Transaction transaction;
				transaction.amount = amount;
				transaction.transactionType = stdType;
				transaction.date = stdDate;
				transaction.tournamentId = tournamentId;

				Financial financial("tournament.db");
				if (financial.addTransaction(transaction)) 
				{
					MessageBox::Show("Transaction Added Successfully!");
				}
				else 
				{
					MessageBox::Show("Failed to Add Transaction.");
				}
			}
			else 
			{
				MessageBox::Show("Invalid amount format. Please enter a valid number.");
			}
		}
		else 
		{
			MessageBox::Show("Invalid tournament ID format. Please enter a valid integer.");
		}
		
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}

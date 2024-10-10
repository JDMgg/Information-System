#pragma once
#include "Tournament.h"
#include "Match.h"
#include "Financial.h"
#include "Account.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include <vector>
#include <string>
#include "Financial.h"



namespace KursovaInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;


	/// <summary>
	/// Сводка для TicketList
	/// </summary>
	public ref class TicketList : public System::Windows::Forms::Form
	{
	public:
		TicketList(void)
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
		~TicketList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ SumHigh;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ Comment;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ Diapazon;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button2;



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
			this->SumHigh = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->Comment = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->Diapazon = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(252, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &TicketList::textBox1_TextChanged);
			// 
			// SumHigh
			// 
			this->SumHigh->Location = System::Drawing::Point(324, 26);
			this->SumHigh->Name = L"SumHigh";
			this->SumHigh->Size = System::Drawing::Size(75, 23);
			this->SumHigh->TabIndex = 1;
			this->SumHigh->Text = L"Пошук";
			this->SumHigh->UseVisualStyleBackColor = true;
			this->SumHigh->Click += gcnew System::EventHandler(this, &TicketList::SumHigh_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 14);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Напишіть суму, для пошуку транзакцій, які більше";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 80);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(252, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &TicketList::textBox2_TextChanged);
			// 
			// Comment
			// 
			this->Comment->Location = System::Drawing::Point(324, 80);
			this->Comment->Name = L"Comment";
			this->Comment->Size = System::Drawing::Size(75, 23);
			this->Comment->TabIndex = 4;
			this->Comment->Text = L"Пошук";
			this->Comment->UseVisualStyleBackColor = true;
			this->Comment->Click += gcnew System::EventHandler(this, &TicketList::Comment_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(223, 28);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Напишіть примітку для пошуку транзакцій \r\n(Refund або Paid)";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 120);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(78, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"Початок";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &TicketList::textBox3_TextChanged);
			// 
			// Diapazon
			// 
			this->Diapazon->Location = System::Drawing::Point(324, 120);
			this->Diapazon->Name = L"Diapazon";
			this->Diapazon->Size = System::Drawing::Size(75, 23);
			this->Diapazon->TabIndex = 7;
			this->Diapazon->Text = L"Пошук";
			this->Diapazon->UseVisualStyleBackColor = true;
			this->Diapazon->Click += gcnew System::EventHandler(this, &TicketList::Diapazon_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(252, 14);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Впишіть дати для пошуку транзакцій (рр-мм-дд)";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(124, 120);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(78, 20);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"Кінець";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &TicketList::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 159);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(252, 20);
			this->textBox5->TabIndex = 10;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &TicketList::textBox5_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(324, 159);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Пошук";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TicketList::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(276, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Напишіть ID турніру для визначення макс. транзакції";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 199);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(252, 20);
			this->textBox6->TabIndex = 13;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &TicketList::textBox6_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 186);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(191, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Всі транзакції з заданим значенням";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(324, 197);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Пошук";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TicketList::button2_Click);
			// 
			// TicketList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Diapazon);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Comment);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SumHigh);
			this->Controls->Add(this->textBox1);
			this->Name = L"TicketList";
			this->Text = L"TicketList";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void SumHigh_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ findvalue = textBox1->Text;
	double amount;
	if (Double::TryParse(findvalue, amount))
	{
		Financial financial("tournament.db");
		std::vector<Transaction> transactions = financial.findTransactionForCashier(amount);

		if (!transactions.empty()) 
		{
			for (const auto& transaction : transactions) 
			{
				String^ transactionInfo = "Amount: " + transaction.amount + ", Type: " + gcnew String(transaction.transactionType.c_str()) + ", Date: " + gcnew String(transaction.date.c_str()) + ", Tournament ID: " + transaction.tournamentId;
				MessageBox::Show(transactionInfo);
			}
		}
		else 
		{
			MessageBox::Show("No transactions found for the given amount.");
		}
	}
	else
	{
		MessageBox::Show("Invalid amount format. Please enter a valid number.");
	}
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Comment_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ findType = textBox2->Text;

	Financial financial("tournament.db");
	std::string stdType = marshal_as<std::string>(findType);

	std::vector<Transaction> transactions = financial.findTransactionsByType(stdType);
	if (!transactions.empty()) 
	{
		String^ message = "";
		for (const auto& transaction : transactions) 
		{
			message += "Transaction ID: " + transaction.transactionId.ToString() + "\n";
			message += "Amount: " + transaction.amount.ToString() + "\n";
			message += "Date: " + gcnew String(transaction.date.c_str()) + "\n";
			message += "Transaction Type: " + gcnew String(transaction.transactionType.c_str()) + "\n";
			message += "Tournament ID: " + transaction.tournamentId.ToString() + "\n\n";
		}
		MessageBox::Show(message, "Transactions found!");
	}
	else 
	{
		MessageBox::Show("No transactions found.");
	}
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Diapazon_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ firstDate = textBox3->Text;
	String^ endDate = textBox4->Text;

	Financial financial("tournament.db");

	std::string stdfirstDate = marshal_as<std::string>(firstDate);
	std::string stdendDate = marshal_as<std::string>(endDate);

	std::vector<Transaction> transactions = financial.findTransactionsByDateRange(stdfirstDate, stdendDate);

	String^ message = "Transactions in the date range:\n";
	for (const auto& transaction : transactions) 
	{
		message += "Transaction ID: " + transaction.transactionId + "\n";
		message += "Amount: " + transaction.amount + "\n";
		message += "Date: " + gcnew String(transaction.date.c_str()) + "\n";
		message += "Transaction Type: " + gcnew String(transaction.transactionType.c_str()) + "\n";
		message += "Tournament ID: " + transaction.tournamentId + "\n\n";
	}

	MessageBox::Show(message, "Transactions in Date Range");


}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Financial financial("tournament.db");
	int tournamentId;

	String^ textBoxValue = textBox5->Text;
	std::cout << "TextBox Value: " << msclr::interop::marshal_as<std::string>(textBoxValue) << std::endl;

	if (!Int32::TryParse(textBoxValue, tournamentId)) 
	{
		MessageBox::Show("Invalid tournament ID. Please enter a valid integer.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	std::cout << "Parsed tournament ID: " << tournamentId << std::endl;
	int maxTransactionCount = financial.getMaxTransactionCountForTournament(tournamentId);
	String^ message = "Max Transaction Count for Tournament " + tournamentId + " is " + maxTransactionCount;
	MessageBox::Show(message, "Max Transaction Count", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{	
	String^ amountsStr = textBox6->Text;
	std::vector<double> amounts;

	std::istringstream stream(marshal_as<std::string>(amountsStr));
	std::string segment;
	while (std::getline(stream, segment, ',')) 
	{
		double amount;
		if (std::stringstream(segment) >> amount) 
		{
			amounts.push_back(amount);
		}
	}
	if (amounts.empty()) 
	{
		MessageBox::Show("Invalid amounts. Please enter valid numbers separated by commas.");
		return;
	}

	Financial financial("tournament.db");
	std::vector<Transaction> transactions = financial.findTransactionsByAmounts(amounts);

	System::Text::StringBuilder^ message = gcnew System::Text::StringBuilder();
	for (const auto& transaction : transactions) 
	{
		message->Append("Transaction ID: " + transaction.transactionId + "\n");
		message->Append("Amount: " + transaction.amount + "\n");
		message->Append("Date: " + gcnew System::String(transaction.date.c_str()) + "\n");
		message->Append("Transaction Type: " + gcnew System::String(transaction.transactionType.c_str()) + "\n");
		message->Append("Tournament ID: " + transaction.tournamentId + "\n");
		message->Append("Tournament Name: " + gcnew System::String(transaction.tournamentName.c_str()) + "\n");
		message->Append("Tournament Date: " + gcnew System::String(transaction.tournamentDate.c_str()) + "\n");
		message->Append("Venue: " + gcnew System::String(transaction.venue.c_str()) + "\n\n");
	}

	if (transactions.empty()) 
	{
		MessageBox::Show("No transactions found for the given amounts.");
	}
	else 
	{
		MessageBox::Show(message->ToString(), "Transactions");
	}
}
};
}

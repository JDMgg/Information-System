#pragma once
#include <sqlite3.h>
#include "CreateTournament2.h"
#include <msclr\marshal_cppstd.h>
#include "Tournament.h"
#include "Match.h"
#include "Financial.h"
#include "Account.h"



namespace KursovaInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для CreateTournament
	/// </summary>
	public ref class CreateTournament : public System::Windows::Forms::Form
	{
	public:
		CreateTournament(void)
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
		~CreateTournament()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ SaveTournament;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;


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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SaveTournament = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(201, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &CreateTournament::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 73);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(201, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &CreateTournament::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 112);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(201, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &CreateTournament::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 155);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(201, 20);
			this->textBox4->TabIndex = 3;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &CreateTournament::textBox4_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Напишіть назву турніру";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Дата початку турніру";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Формат гри (11 або 21 очок)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Кількість білетів";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 200);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(201, 20);
			this->textBox5->TabIndex = 8;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &CreateTournament::textBox5_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 184);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(214, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Категорія турніру (жіночий або чоловічий)";
			// 
			// SaveTournament
			// 
			this->SaveTournament->Location = System::Drawing::Point(12, 277);
			this->SaveTournament->Name = L"SaveTournament";
			this->SaveTournament->Size = System::Drawing::Size(201, 23);
			this->SaveTournament->TabIndex = 10;
			this->SaveTournament->Text = L"Зберегти";
			this->SaveTournament->UseVisualStyleBackColor = true;
			this->SaveTournament->Click += gcnew System::EventHandler(this, &CreateTournament::SaveTournament_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 239);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(201, 20);
			this->textBox6->TabIndex = 11;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &CreateTournament::textBox6_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 223);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"ID учасників (id, id ... )";
			// 
			// CreateTournament
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(230, 312);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->SaveTournament);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"CreateTournament";
			this->Text = L"CreateTournament";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SaveTournament_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ TournamentName = textBox1->Text;
		String^ DateTournament = textBox2->Text;
		String^ GameFormat = textBox3->Text;
		String^ TicketCount = textBox4->Text;
		String^ GameCategory = textBox5->Text;
		String^ ParticipantId = textBox6->Text;

		int TournamentTickets;
		if (Int32::TryParse(TicketCount, TournamentTickets))
		{
			std::string stdTournamentName = marshal_as<std::string>(TournamentName);
			std::string stdDateTournament = marshal_as<std::string>(DateTournament);
			std::string stdGameFormat = marshal_as<std::string>(GameFormat);
			std::string stdGameCategory = marshal_as<std::string>(GameCategory);
			std::string stdParticipantId = marshal_as<std::string>(ParticipantId);

			Tournament tournament("tournament.db");

			// Додаємо турнір до бази даних
			if (tournament.addTournament(stdTournamentName, stdDateTournament, stdGameFormat, TournamentTickets, stdGameCategory, stdParticipantId)) 
			{
				MessageBox::Show("Tournament added successfully!");
				CreateTournament2^ f2 = gcnew CreateTournament2();
				f2->Show();
				this->Hide(); 
			}
			else 
			{
				MessageBox::Show("Failed to add tournament.");
			}
		}
		else
		{
			MessageBox::Show("Invalid tickets count. Please enter a valid integer.");
		}
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

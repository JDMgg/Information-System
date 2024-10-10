#pragma once
#include "CreateTournament.h"
#include "AddParticipant.h"
#include "MatchAdd.h"
#include "Tournament.h"
#include "Match.h"
#include "Financial.h"
#include "Account.h"
#include "Players.h"
#include "MatchParticipant.h"
#include <tuple>	
#include <vector>

namespace KursovaInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Organization
	/// </summary>
	public ref class Organization : public System::Windows::Forms::Form
	{
	public:
		Organization(void)
		{
			InitializeComponent();
			tournament = new Tournament("tournament");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Organization()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Button^ button1;
		Tournament* tournament;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ addParticipant;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;







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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addParticipant = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(167, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Створити змагання";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Organization::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(100, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(253, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Меню організатора";
			// 
			// addParticipant
			// 
			this->addParticipant->Location = System::Drawing::Point(167, 111);
			this->addParticipant->Name = L"addParticipant";
			this->addParticipant->Size = System::Drawing::Size(120, 39);
			this->addParticipant->TabIndex = 2;
			this->addParticipant->Text = L"Додати учасника";
			this->addParticipant->UseVisualStyleBackColor = true;
			this->addParticipant->Click += gcnew System::EventHandler(this, &Organization::addParticipant_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(167, 156);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 39);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Додати результат матчу ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Organization::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 66);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 39);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Інші запити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Organization::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 111);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(120, 39);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Список гравців";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Organization::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(13, 156);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(119, 39);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Додати статус матча";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Organization::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(319, 66);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(120, 39);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Гравці які не грали матч";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Organization::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(319, 111);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(120, 39);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Отримати турніри та матчі";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Organization::button7_Click);
			// 
			// Organization
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 261);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->addParticipant);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Organization";
			this->Text = L"Organization";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		CreateTournament^ f2 = gcnew CreateTournament();
		f2->Show();
	}
	private: System::Void addParticipant_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		AddParticipant^ f2 = gcnew AddParticipant();
		f2->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MatchAdd^ f2 = gcnew MatchAdd();
		f2->Show();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Players^ f2 = gcnew Players();
	f2->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Tournament tournament("tournament.db");

	// Виклик методу для виведення інформації про гравців
	std::vector<std::string> playersInfo = tournament.displayAllPlayerInfo();
	System::Text::StringBuilder^ message = gcnew System::Text::StringBuilder();
	for each (std::string playerInfo in playersInfo) 
	{
		message->Append(gcnew System::String(playerInfo.c_str()));
		message->Append("\n\n");
	}

	MessageBox::Show(message->ToString(), "Player Information");
}
// відкрити форму з MatchParticipant
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MatchParticipant^ f2 = gcnew MatchParticipant();
	f2->Show();
}
// 8 запит використання exists гравці які не зіграли матч
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Tournament tournament("tournament.db");
	auto participants = tournament.findParticipantsNotPlayedInCompletedMatches();

	System::Text::StringBuilder^ message = gcnew System::Text::StringBuilder();
	for (const auto& participant : participants) 
	{
		int participantId;
		std::string firstName, lastName, clubName;
		std::tie(participantId, firstName, lastName, clubName) = participant;

		message->Append("Participant ID: " + participantId + "\n");
		message->Append("First Name: " + gcnew System::String(firstName.c_str()) + "\n");
		message->Append("Last Name: " + gcnew System::String(lastName.c_str()) + "\n");
		message->Append("Club Name: " + gcnew System::String(clubName.c_str()) + "\n\n");
	}

	if (participants.empty()) 
	{
		MessageBox::Show("No participants found who have not played in completed matches.");
	}
	else 
	{
		MessageBox::Show(message->ToString(), "Participants");
	}
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Tournament tournamentManager("tournament.db");

	std::vector<std::string> results = tournamentManager.unionTournamentsAndMatchesWithComments();
	System::Text::StringBuilder^ message = gcnew System::Text::StringBuilder();
	for (const auto& result : results) 
	{
		message->Append(gcnew System::String(result.c_str()));
		message->Append("\n\n");
	}
	if (results.empty()) 
	{
		MessageBox::Show("No data found.");
	}
	else 
	{
		MessageBox::Show(message->ToString(), "Tournaments and Matches");
	}
}
};
}

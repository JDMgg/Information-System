#pragma once
#include "Tournament.h"
#include "Match.h"
#include "Financial.h"
#include "Account.h"
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
	/// Сводка для Players
	/// </summary>
	public ref class Players : public System::Windows::Forms::Form
	{
	public:
		Players(void)
		{
			InitializeComponent();
			LoadComboBoxData();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Players()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(313, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Пошук";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Players::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Оберіть назву клубу";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(13, 31);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(231, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Players::comboBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(231, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Players::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Напишіть назву міста для пошуку";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(313, 80);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Пошук";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Players::button2_Click);
			// 
			// Players
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Players";
			this->Text = L"Players";
			this->Load += gcnew System::EventHandler(this, &Players::Players_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LoadComboBoxData()
	{
		comboBox1->Items->Clear();

		Tournament tournament("tournament.db");

		// Завантаження дат турнірів
		auto dates = tournament.getClubNames();
		for (const auto& date : dates) 
		{
			comboBox1->Items->Add(gcnew String(date.c_str()));
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ clubnamestr = comboBox1->SelectedItem->ToString();
		std::string clubName = msclr::interop::marshal_as<std::string>(clubnamestr);

		Tournament* tournament = new Tournament("tournament.db");

		std::vector<std::string> players = tournament->findPlayersWithSameClub(clubName);

		// Перевірка результатів і відображення повідомлення
		if (players.empty()) 
		{
			MessageBox::Show("No players found for the club.");
		}
		else 
		{
			System::Text::StringBuilder^ message = gcnew System::Text::StringBuilder();
			message->Append("Players not in ");
			message->Append(gcnew System::String(clubName.c_str()));
			message->AppendLine(":");
			for (const auto& player : players) 
			{
				message->Append(gcnew System::String(player.c_str()));
				message->AppendLine();
			}
			MessageBox::Show(message->ToString(), "Players for the Club");
		}

		delete tournament;
	}
	private: System::Void Players_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		LoadComboBoxData();
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ venue = textBox1->Text;

	Tournament tournamentManager("tournament.db");

	std::vector<std::vector<std::string>> tournaments = tournamentManager.findTournamentsNotHeldAtVenue(marshal_as<std::string>(venue));

	System::Text::StringBuilder^ message = gcnew System::Text::StringBuilder();
	for (const auto& tournament : tournaments) 
	{
		message->Append("Tournament ID: " + gcnew System::String(tournament[0].c_str()) + "\n");
		message->Append("Name: " + gcnew System::String(tournament[1].c_str()) + "\n");
		message->Append("Date: " + gcnew System::String(tournament[2].c_str()) + "\n");
		message->Append("Game Format: " + gcnew System::String(tournament[3].c_str()) + "\n");
		message->Append("Ticket Count: " + gcnew System::String(tournament[4].c_str()) + "\n");
		message->Append("Game Category: " + gcnew System::String(tournament[5].c_str()) + "\n\n");
	}

	if (tournaments.empty()) 
	{
		MessageBox::Show("No tournaments found for the given venue.");
	}
	else 
	{
		MessageBox::Show(message->ToString(), "Tournaments");
	}
}
};
}

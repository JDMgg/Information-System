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
	/// Сводка для MatchParticipant
	/// </summary>
	public ref class MatchParticipant : public System::Windows::Forms::Form
	{
	public:
		MatchParticipant(void)
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
		~MatchParticipant()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ID учасників(id, id ...)";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 117);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(206, 20);
			this->textBox3->TabIndex = 3;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MatchParticipant::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 165);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(206, 20);
			this->textBox4->TabIndex = 4;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MatchParticipant::textBox4_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"ID Матчу (ID)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(193, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Статус матчу(technical end, start, end)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 149);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(180, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Статус гравців (Played, not played )";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 256);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(206, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Зберегти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MatchParticipant::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 29);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(206, 21);
			this->comboBox1->TabIndex = 9;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MatchParticipant::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(12, 75);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(206, 21);
			this->comboBox2->TabIndex = 10;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MatchParticipant::comboBox2_SelectedIndexChanged);
			// 
			// MatchParticipant
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(230, 312);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Name = L"MatchParticipant";
			this->Text = L"MatchParticipant";
			this->Load += gcnew System::EventHandler(this, &MatchParticipant::MatchParticipant_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void LoadComboBoxData()
{
	Match match("tournament.db");

	auto participantIds = match.getParticipantIds();
	for (const auto& id : participantIds) 
	{
		comboBox1->Items->Add(gcnew String(id.c_str()));
	}

	auto matchIds = match.getMatchIds();
	for (const auto& id : matchIds) 
	{
		comboBox2->Items->Add(id.ToString());
	}
}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MatchParticipant_Load(System::Object^ sender, System::EventArgs^ e) 
{
	LoadComboBoxData();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ participantId = comboBox1->SelectedItem->ToString();
	String^ matchIdStr = comboBox2->SelectedItem->ToString();
	String^ matchStatus = textBox3->Text;
	String^ participantStatus = textBox4->Text;

	int matchId;
	int participantids;
	if (Int32::TryParse(matchIdStr, matchId)) 
	{
		std::string stdParticipantId = marshal_as<std::string>(participantId);
		std::string stdMatchStatus = marshal_as<std::string>(matchStatus);
		std::string stdParticipantStatus = marshal_as<std::string>(participantStatus);
		Int32::TryParse(participantId, participantids);

		ParticipantMatch participantMatch;
		participantMatch.participantId = participantids;
		participantMatch.matchId = matchId;
		participantMatch.matchStatus = stdMatchStatus;
		participantMatch.participantStatus = stdParticipantStatus;


		Match match("tournament.db");

		if (match.addParticipantMatch(participantMatch)) 
		{
			if (stdMatchStatus != "technical end") 
			{
				MessageBox::Show("Participant match added successfully.");
			}
			else 
			{
				MessageBox::Show("Match status is 'technical end'");
				MatchParticipant::Hide();
			}
		}
		else 
		{
			MessageBox::Show("Failed to add participant match.");
		}
	}
	else 
	{
		MessageBox::Show("Invalid match ID.");
	}
}
};
}

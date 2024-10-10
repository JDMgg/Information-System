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

	public ref class MatchAdd : public System::Windows::Forms::Form
	{
	public:
		MatchAdd(void)
		{
			InitializeComponent();
			// Додаємо виклик методу для завантаження даних у ComboBox
			LoadComboBoxData();
		}

	protected:
		~MatchAdd()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ button1;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(205, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(13, 180);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(205, 20);
			this->textBox4->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Результат формат(xx-xx)";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(13, 80);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(205, 21);
			this->comboBox1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Дата турніру";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"ID турніру";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 164);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(145, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Переможець (Назва клубу)";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(13, 130);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(205, 21);
			this->comboBox2->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 263);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(205, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Зберегти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MatchAdd::button1_Click);
			// 
			// MatchAdd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(230, 312);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox1);
			this->Name = L"MatchAdd";
			this->Text = L"MatchAdd";
			this->Load += gcnew System::EventHandler(this, &MatchAdd::MatchAdd_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ result = textBox1->Text;
		String^ date = comboBox1->SelectedItem->ToString();
		String^ tournamentIdStr = comboBox2->SelectedItem->ToString();
		String^ winner = textBox4->Text;

		int tournamentId;

		if (Int32::TryParse(tournamentIdStr, tournamentId)) 
		{
			std::string stdResult = marshal_as<std::string>(result);
			std::string stdDate = marshal_as<std::string>(date);
			std::string stdWinner = marshal_as<std::string>(winner);
			std::string stdTournamentId = marshal_as<std::string>(tournamentIdStr);

			MatchInfo matchInfo;
			matchInfo.result = stdResult;
			matchInfo.date = stdDate;
			matchInfo.tournamentId = tournamentId;
			matchInfo.winner = stdWinner;

			Match match("tournament.db");

			if (match.addMatchInfo(matchInfo)) 
			{
				MessageBox::Show("Match added successfully.");
			}
			else 
			{
				MessageBox::Show("Failed to add match.");
			}
		}
		else 
		{
			MessageBox::Show("Invalid tournament ID.");
		}
	}

	private: System::Void LoadComboBoxData()
	{
		comboBox1->Items->Clear();
		comboBox2->Items->Clear();

		Match match("tournament.db");

		// Завантаження дат турнірів
		auto dates = match.getTournamentDates();
		for (const auto& date : dates) 
		{
			comboBox1->Items->Add(gcnew String(date.c_str()));
		}

		// Завантаження ID турнірів
		auto ids = match.getTournamentIds();
		for (const auto& id : ids) 
		{
			comboBox2->Items->Add(gcnew String(std::to_string(id).c_str()));
		}
	}

	private: System::Void MatchAdd_Load(System::Object^ sender, System::EventArgs^ e)
	{
		LoadComboBoxData();
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		
	}

	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		
	}

	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		
	}
	};
}

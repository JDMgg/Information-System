#pragma once
#include <msclr\marshal_cppstd.h>
#include "Tournament.h"
#include "Match.h"
#include "Financial.h"
#include "Account.h"
#include "DataBaseHandler.h"

namespace KursovaInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для CreateTournament2
	/// </summary>
	public ref class CreateTournament2 : public System::Windows::Forms::Form
	{
	public:
		CreateTournament2(void)
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
		~CreateTournament2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ SaveButton;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 92);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(206, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &CreateTournament2::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 167);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(206, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &CreateTournament2::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Напишіть ID турніру";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(185, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Напишіть місто проведення турніру";
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(12, 246);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(206, 23);
			this->SaveButton->TabIndex = 8;
			this->SaveButton->Text = L"Зберегти";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &CreateTournament2::SaveButton_Click);
			// 
			// CreateTournament2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(230, 312);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"CreateTournament2";
			this->Text = L"CreateTournament2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ TournamentId = textBox1->Text;
	String^ Venue = textBox2->Text;

	int TournamentIdInt;

	if (Int32::TryParse(TournamentId, TournamentIdInt))
	{
		std::string stdVenue = marshal_as<std::string>(Venue);
		Tournament tournament("tournament.db");

		// Викликаємо метод addTournamentSchedule і перевіряємо, чи успішно він виконався
		if (tournament.addTournamentSchedule(TournamentIdInt, stdVenue)) 
		{
			String^ message = "Country added to tournament #" + TournamentId + " successfully";
			MessageBox::Show(message);
		}
		else 
		{
			MessageBox::Show("Country for this tournament already selected.");
		}
	}
	else
	{
		MessageBox::Show("Failed to add tournament schedule.");
	}

}
};
}

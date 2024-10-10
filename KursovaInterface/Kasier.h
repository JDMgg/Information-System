#pragma once
#include "TicketList.h"
#include "StartSales.h"

namespace KursovaInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Сводка для Kasier
	/// </summary>
	public ref class Kasier : public System::Windows::Forms::Form
	{
	public:
		Kasier(void)
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
		~Kasier()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ StartSale;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ TicketsList;
	private: System::Windows::Forms::Button^ FindTransaction;



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
			this->StartSale = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TicketsList = (gcnew System::Windows::Forms::Button());
			this->FindTransaction = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// StartSale
			// 
			this->StartSale->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StartSale->Location = System::Drawing::Point(167, 66);
			this->StartSale->Name = L"StartSale";
			this->StartSale->Size = System::Drawing::Size(120, 39);
			this->StartSale->TabIndex = 0;
			this->StartSale->Text = L"Відкрити продаж";
			this->StartSale->UseVisualStyleBackColor = true;
			this->StartSale->Click += gcnew System::EventHandler(this, &Kasier::StartSale_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Location = System::Drawing::Point(100, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(293, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Меню продажу білетів";
			// 
			// TicketsList
			// 
			this->TicketsList->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TicketsList->Location = System::Drawing::Point(167, 111);
			this->TicketsList->Name = L"TicketsList";
			this->TicketsList->Size = System::Drawing::Size(120, 39);
			this->TicketsList->TabIndex = 2;
			this->TicketsList->Text = L"Знайти транзакції";
			this->TicketsList->UseVisualStyleBackColor = true;
			this->TicketsList->Click += gcnew System::EventHandler(this, &Kasier::TicketsList_Click);
			// 
			// FindTransaction
			// 
			this->FindTransaction->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FindTransaction->Location = System::Drawing::Point(167, 156);
			this->FindTransaction->Name = L"FindTransaction";
			this->FindTransaction->Size = System::Drawing::Size(120, 38);
			this->FindTransaction->TabIndex = 3;
			this->FindTransaction->Text = L"Вихід";
			this->FindTransaction->UseVisualStyleBackColor = true;
			this->FindTransaction->Click += gcnew System::EventHandler(this, &Kasier::FindTransaction_Click);
			// 
			// Kasier
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 261);
			this->Controls->Add(this->FindTransaction);
			this->Controls->Add(this->TicketsList);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->StartSale);
			this->Name = L"Kasier";
			this->Text = L"Kasier";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TicketsList_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		TicketList^ f2 = gcnew TicketList();
		f2->Show();
	}
	private: System::Void StartSale_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		StartSales^ f2 = gcnew StartSales();
		f2->Show();
	}
private: System::Void FindTransaction_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}
};
}

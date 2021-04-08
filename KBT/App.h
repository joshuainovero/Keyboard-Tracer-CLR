#pragma once
#include <Windows.h>
#include <string>
#include <fstream>
#include <thread>
#include <conio.h>
#include <ctime>
#include <tlhelp32.h>

#include "Process.h"
#include "Date.h"
#include "Filehandling.h"

namespace KBT {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for App
	/// </summary>
	public ref class App : public System::Windows::Forms::Form
	{
	public:
		App(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		int SetXPosition(std::string xstr) {
			int n = 0;
			if (xstr.length() >= 3) {
				for (int i = 0; i <= xstr.length() - 3; ++i)
					n += 4;
				return n;
			}
			else return n;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~App()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ KeyboardTitle;
	protected:

	public: System::Windows::Forms::Label^ TracerTitle;

	public:


	public:




	private: System::Windows::Forms::Label^ Status;
	private: System::Windows::Forms::Label^ Running;
	private: System::Windows::Forms::Label^ Disabled;
	private: System::Windows::Forms::Button^ EnorDi;
	private: System::Windows::Forms::Button^ Refresh;
	private: System::Windows::Forms::Button^ Reset;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox3;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox4;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox5;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox6;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox7;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox8;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox9;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox10;
	private: System::Windows::Forms::Label^ Total;
	private: System::Windows::Forms::Label^ Today;
	private: System::Windows::Forms::Label^ Average;
	private: System::Windows::Forms::Label^ Highest;
	private: System::Windows::Forms::Label^ Lowest;
	private: System::Windows::Forms::Label^ TotalVal;
	private: System::Windows::Forms::Label^ TodayVal;
	private: System::Windows::Forms::Label^ AverageVal;
	private: System::Windows::Forms::Label^ HighestVal;
	private: System::Windows::Forms::Label^ LowestVal;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(App::typeid));
			this->KeyboardTitle = (gcnew System::Windows::Forms::Label());
			this->TracerTitle = (gcnew System::Windows::Forms::Label());
			this->Status = (gcnew System::Windows::Forms::Label());
			this->Running = (gcnew System::Windows::Forms::Label());
			this->Disabled = (gcnew System::Windows::Forms::Label());
			this->EnorDi = (gcnew System::Windows::Forms::Button());
			this->Refresh = (gcnew System::Windows::Forms::Button());
			this->Reset = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox5 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox6 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox7 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox8 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox9 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox10 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->Total = (gcnew System::Windows::Forms::Label());
			this->Today = (gcnew System::Windows::Forms::Label());
			this->Average = (gcnew System::Windows::Forms::Label());
			this->Highest = (gcnew System::Windows::Forms::Label());
			this->Lowest = (gcnew System::Windows::Forms::Label());
			this->TotalVal = (gcnew System::Windows::Forms::Label());
			this->TodayVal = (gcnew System::Windows::Forms::Label());
			this->AverageVal = (gcnew System::Windows::Forms::Label());
			this->HighestVal = (gcnew System::Windows::Forms::Label());
			this->LowestVal = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// KeyboardTitle
			// 
			this->KeyboardTitle->AutoSize = true;
			this->KeyboardTitle->Font = (gcnew System::Drawing::Font(L"Crossten ExtraBold", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KeyboardTitle->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->KeyboardTitle->Location = System::Drawing::Point(91, 19);
			this->KeyboardTitle->Name = L"KeyboardTitle";
			this->KeyboardTitle->Size = System::Drawing::Size(148, 38);
			this->KeyboardTitle->TabIndex = 0;
			this->KeyboardTitle->Text = L"Keyboard";
			this->KeyboardTitle->Click += gcnew System::EventHandler(this, &App::Title_Click);
			// 
			// TracerTitle
			// 
			this->TracerTitle->AutoSize = true;
			this->TracerTitle->Font = (gcnew System::Drawing::Font(L"Crossten ExtraBold", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TracerTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->TracerTitle->Location = System::Drawing::Point(232, 19);
			this->TracerTitle->Name = L"TracerTitle";
			this->TracerTitle->Size = System::Drawing::Size(103, 38);
			this->TracerTitle->TabIndex = 1;
			this->TracerTitle->Text = L"Tracer";
			// 
			// Status
			// 
			this->Status->AutoSize = true;
			this->Status->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Status->Font = (gcnew System::Drawing::Font(L"Crossten ExtraBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Status->ForeColor = System::Drawing::Color::White;
			this->Status->Location = System::Drawing::Point(139, 77);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(84, 25);
			this->Status->TabIndex = 4;
			this->Status->Text = L"Status : ";
			this->Status->Click += gcnew System::EventHandler(this, &App::label3_Click);
			// 
			// Running
			// 
			this->Running->AutoSize = true;
			this->Running->Font = (gcnew System::Drawing::Font(L"Crossten ExtraBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Running->ForeColor = System::Drawing::Color::Lime;
			this->Running->Location = System::Drawing::Point(211, 77);
			this->Running->Name = L"Running";
			this->Running->Size = System::Drawing::Size(83, 25);
			this->Running->TabIndex = 7;
			this->Running->Text = L"Running";
			this->Running->Click += gcnew System::EventHandler(this, &App::Running_Click);
			this->Running->Visible = false;
			// 
			// Disabled
			// 
			this->Disabled->AutoSize = true;
			this->Disabled->Font = (gcnew System::Drawing::Font(L"Crossten ExtraBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Disabled->ForeColor = System::Drawing::Color::Red;
			this->Disabled->Location = System::Drawing::Point(211, 77);
			this->Disabled->Name = L"Disabled";
			this->Disabled->Size = System::Drawing::Size(86, 25);
			this->Disabled->TabIndex = 8;
			this->Disabled->Text = L"Disabled";
			this->Disabled->Visible = false;

			//Set either the visiblity of running and disabled depending on the process
			if (FindProcessId("Logger.exe") != 0) this->Running->Visible = true;
			else this->Disabled->Visible = true;

			// 
			// Disable/Enable Button
			// 
			this->EnorDi->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->EnorDi->Cursor = System::Windows::Forms::Cursors::Default;
			this->EnorDi->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->EnorDi->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnorDi->ForeColor = System::Drawing::Color::White;
			this->EnorDi->Location = System::Drawing::Point(74, 143);
			this->EnorDi->Name = L"Enable";
			this->EnorDi->Size = System::Drawing::Size(75, 23);
			this->EnorDi->TabIndex = 9;
			if (FindProcessId("Logger.exe") == 0) this->EnorDi->Text = L"Enable";
			else this->EnorDi->Text = L"Disable";
			this->EnorDi->UseVisualStyleBackColor = false;
			this->EnorDi->Click += gcnew System::EventHandler(this, &App::EnorDi_Click);
			// 
			// Refresh
			// 
			this->Refresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Refresh->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Refresh->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Refresh->ForeColor = System::Drawing::Color::White;
			this->Refresh->Location = System::Drawing::Point(74, 187);
			this->Refresh->Name = L"Refresh";
			this->Refresh->Size = System::Drawing::Size(75, 23);
			this->Refresh->TabIndex = 10;
			this->Refresh->Text = L"Refresh";
			this->Refresh->UseVisualStyleBackColor = false;
			this->Refresh->Click += gcnew System::EventHandler(this, &App::Refresh_Click);
			// 
			// Reset
			// 
			this->Reset->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Reset->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Reset->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Reset->ForeColor = System::Drawing::Color::White;
			this->Reset->Location = System::Drawing::Point(74, 233);
			this->Reset->Name = L"Reset";
			this->Reset->Size = System::Drawing::Size(75, 23);
			this->Reset->TabIndex = 11;
			this->Reset->Text = L"Reset";
			this->Reset->UseVisualStyleBackColor = false;
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->AllowPromptAsInput = false;
			this->maskedTextBox1->BackColor = System::Drawing::Color::White;
			this->maskedTextBox1->Enabled = false;
			this->maskedTextBox1->Location = System::Drawing::Point(166, 146);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox1->TabIndex = 12;
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &App::maskedTextBox1_MaskInputRejected);
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->BackColor = System::Drawing::Color::White;
			this->maskedTextBox2->Enabled = false;
			this->maskedTextBox2->Location = System::Drawing::Point(259, 146);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox2->TabIndex = 13;
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->AllowPromptAsInput = false;
			this->maskedTextBox3->BackColor = System::Drawing::Color::White;
			this->maskedTextBox3->Enabled = false;
			this->maskedTextBox3->Location = System::Drawing::Point(166, 167);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox3->TabIndex = 14;
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->BackColor = System::Drawing::Color::White;
			this->maskedTextBox4->Enabled = false;
			this->maskedTextBox4->Location = System::Drawing::Point(259, 167);
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox4->TabIndex = 15;
			// 
			// maskedTextBox5
			// 
			this->maskedTextBox5->BackColor = System::Drawing::Color::White;
			this->maskedTextBox5->Enabled = false;
			this->maskedTextBox5->Location = System::Drawing::Point(166, 188);
			this->maskedTextBox5->Name = L"maskedTextBox5";
			this->maskedTextBox5->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox5->TabIndex = 16;
			// 
			// maskedTextBox6
			// 
			this->maskedTextBox6->BackColor = System::Drawing::Color::White;
			this->maskedTextBox6->Enabled = false;
			this->maskedTextBox6->Location = System::Drawing::Point(259, 188);
			this->maskedTextBox6->Name = L"maskedTextBox6";
			this->maskedTextBox6->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox6->TabIndex = 17;
			// 
			// maskedTextBox7
			// 
			this->maskedTextBox7->BackColor = System::Drawing::Color::White;
			this->maskedTextBox7->Enabled = false;
			this->maskedTextBox7->Location = System::Drawing::Point(166, 209);
			this->maskedTextBox7->Name = L"maskedTextBox7";
			this->maskedTextBox7->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox7->TabIndex = 18;
			// 
			// maskedTextBox8
			// 
			this->maskedTextBox8->BackColor = System::Drawing::Color::White;
			this->maskedTextBox8->Enabled = false;
			this->maskedTextBox8->Location = System::Drawing::Point(259, 209);
			this->maskedTextBox8->Name = L"maskedTextBox8";
			this->maskedTextBox8->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox8->TabIndex = 19;
			// 
			// maskedTextBox9
			// 
			this->maskedTextBox9->BackColor = System::Drawing::Color::White;
			this->maskedTextBox9->Enabled = false;
			this->maskedTextBox9->Location = System::Drawing::Point(166, 230);
			this->maskedTextBox9->Name = L"maskedTextBox9";
			this->maskedTextBox9->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox9->TabIndex = 20;
			// 
			// maskedTextBox10
			// 
			this->maskedTextBox10->BackColor = System::Drawing::Color::White;
			this->maskedTextBox10->Enabled = false;
			this->maskedTextBox10->Location = System::Drawing::Point(259, 230);
			this->maskedTextBox10->Name = L"maskedTextBox10";
			this->maskedTextBox10->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox10->TabIndex = 21;
			// 
			// Total
			// 
			this->Total->AutoSize = true;
			this->Total->BackColor = System::Drawing::Color::White;
			this->Total->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Total->Location = System::Drawing::Point(183, 148);
			this->Total->Name = L"Total";
			this->Total->Size = System::Drawing::Size(62, 16);
			this->Total->TabIndex = 22;
			this->Total->Text = L"Keystrokes";
			// 
			// Today
			// 
			this->Today->AutoSize = true;
			this->Today->BackColor = System::Drawing::Color::White;
			this->Today->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Today->Location = System::Drawing::Point(193, 169);
			this->Today->Name = L"Today";
			this->Today->Size = System::Drawing::Size(42, 16);
			this->Today->TabIndex = 23;
			this->Today->Text = L"Today";
			// 
			// Average
			// 
			this->Average->AutoSize = true;
			this->Average->BackColor = System::Drawing::Color::White;
			this->Average->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Average->Location = System::Drawing::Point(188, 190);
			this->Average->Name = L"Average";
			this->Average->Size = System::Drawing::Size(55, 16);
			this->Average->TabIndex = 24;
			this->Average->Text = L"Average";
			// 
			// Highest
			// 
			this->Highest->AutoSize = true;
			this->Highest->BackColor = System::Drawing::Color::White;
			this->Highest->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Highest->Location = System::Drawing::Point(191, 211);
			this->Highest->Name = L"Highest";
			this->Highest->Size = System::Drawing::Size(47, 16);
			this->Highest->TabIndex = 25;
			this->Highest->Text = L"Highest";
			// 
			// Lowest
			// 
			this->Lowest->AutoSize = true;
			this->Lowest->BackColor = System::Drawing::Color::White;
			this->Lowest->Cursor = System::Windows::Forms::Cursors::Default;
			this->Lowest->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lowest->Location = System::Drawing::Point(192, 232);
			this->Lowest->Name = L"Lowest";
			this->Lowest->Size = System::Drawing::Size(45, 16);
			this->Lowest->TabIndex = 26;
			this->Lowest->Text = L"Lowest";
			// 
			// TotalVal
			// 
			this->TotalVal->AutoSize = true;
			this->TotalVal->BackColor = System::Drawing::Color::White;
			this->TotalVal->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TotalVal->Location = System::Drawing::Point(302 - SetXPosition(FILEHANDLE::getTotalStrokes()), 148); //4
			this->TotalVal->Name = L"TotalVal";
			this->TotalVal->Size = System::Drawing::Size(14, 16);
			this->TotalVal->TabIndex = 27;
			this->TotalVal->Text = gcnew String(FILEHANDLE::getTotalStrokes().c_str());
			// 
			// TodayVal
			// 
			this->TodayVal->AutoSize = true;
			this->TodayVal->BackColor = System::Drawing::Color::White;
			this->TodayVal->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TodayVal->Location = System::Drawing::Point(302 - SetXPosition(FILEHANDLE::getCurrStrokes()), 169);
			this->TodayVal->Name = L"TodayVal";
			this->TodayVal->Size = System::Drawing::Size(14, 16);
			this->TodayVal->TabIndex = 28;
			Date::SetDate();
			if (Date::FullDateNow != FILEHANDLE::getLoggedDate()) {
				FILEHANDLE::resetCurrStrokes();
				FILEHANDLE::updateDateFiles(Date::FullDateNow);
			}

			this->TodayVal->Text = gcnew String(FILEHANDLE::getCurrStrokes().c_str());
			// 
			// AverageVal
			// 
			this->AverageVal->AutoSize = true;
			this->AverageVal->BackColor = System::Drawing::Color::White;
			this->AverageVal->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AverageVal->Location = System::Drawing::Point(302, 190);
			this->AverageVal->Name = L"AverageVal";
			this->AverageVal->Size = System::Drawing::Size(14, 16);
			this->AverageVal->TabIndex = 29;
			this->AverageVal->Text = L"0";
			// 
			// HighestVal
			// 
			this->HighestVal->AutoSize = true;
			this->HighestVal->BackColor = System::Drawing::Color::White;
			this->HighestVal->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HighestVal->Location = System::Drawing::Point(302, 211);
			this->HighestVal->Name = L"HighestVal";
			this->HighestVal->Size = System::Drawing::Size(14, 16);
			this->HighestVal->TabIndex = 30;
			this->HighestVal->Text = L"0";
			// 
			// LowestVal
			// 
			this->LowestVal->AutoSize = true;
			this->LowestVal->BackColor = System::Drawing::Color::White;
			this->LowestVal->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LowestVal->Location = System::Drawing::Point(302, 232);
			this->LowestVal->Name = L"LowestVal";
			this->LowestVal->Size = System::Drawing::Size(14, 16);
			this->LowestVal->TabIndex = 31;
			this->LowestVal->Text = L"0";
			// 
			// App
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(428, 326);
			this->Controls->Add(this->LowestVal);
			this->Controls->Add(this->HighestVal);
			this->Controls->Add(this->AverageVal);
			this->Controls->Add(this->TodayVal);
			this->Controls->Add(this->TotalVal);
			this->Controls->Add(this->Lowest);
			this->Controls->Add(this->Highest);
			this->Controls->Add(this->Average);
			this->Controls->Add(this->Today);
			this->Controls->Add(this->Total);
			this->Controls->Add(this->maskedTextBox10);
			this->Controls->Add(this->maskedTextBox9);
			this->Controls->Add(this->maskedTextBox8);
			this->Controls->Add(this->maskedTextBox7);
			this->Controls->Add(this->maskedTextBox6);
			this->Controls->Add(this->maskedTextBox5);
			this->Controls->Add(this->maskedTextBox4);
			this->Controls->Add(this->maskedTextBox3);
			this->Controls->Add(this->maskedTextBox2);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->Reset);
			this->Controls->Add(this->Refresh);
			this->Controls->Add(this->EnorDi);
			this->Controls->Add(this->Disabled);
			this->Controls->Add(this->Running);
			this->Controls->Add(this->Status);
			this->Controls->Add(this->TracerTitle);
			this->Controls->Add(this->KeyboardTitle);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(444, 365);
			this->MinimumSize = System::Drawing::Size(444, 365);
			this->Name = L"App";
			this->Text = L"Keyboard Tracer BETA";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &App::App_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	const int posxVal = 302;
	private: System::Void EnorDi_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (FILEHANDLE::CheckFileExist("Logger.exe") != 0) {
				if (FindProcessId("Logger.exe") == 0) {
					system("start Logger.exe");
					this->Running->Visible = true;
					this->Disabled->Visible = false;
					this->EnorDi->Text = L"Disable";
				}
				else {
					system("TASKKILL /F /IM Logger.exe 2>NULL");
					this->Running->Visible = false;
					this->Disabled->Visible = true;
					this->EnorDi->Text = L"Enable";
				}
			}
			else
				throw(FILEHANDLE::CheckFileExist("Logger.exe"));
		}
		catch (bool fileExist) {
			MessageBox::Show("Error: A required file is missing from your computer.\n\nTry reinstalling the program", "Keyboard Tracer", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}



	}
	private: System::Void Refresh_Click(System::Object^ sender, System::EventArgs^ e) {
		//Total strokes refresh
		this->TotalVal->Text = gcnew String(FILEHANDLE::getTotalStrokes().c_str());
		this->TotalVal->Location = System::Drawing::Point(302 - SetXPosition(FILEHANDLE::getTotalStrokes()), 148);
		
		//Current strokes refresh
		this->TodayVal->Text = gcnew String(FILEHANDLE::getCurrStrokes().c_str());
		this->TodayVal->Location = System::Drawing::Point(302 - SetXPosition(FILEHANDLE::getCurrStrokes()), 169);

	}
	private: System::Void Title_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Running_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	}
	private: System::Void App_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (FindProcessId("Logger.exe") != 0) {
			if (MessageBox::Show("Keylogger is still running as background process.\n\nDo you want to quit and disable key logs?", "Keyboard Tracer", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				system("TASKKILL /F /IM Logger.exe 2>NULL");
			}
		}

	}
	};
}


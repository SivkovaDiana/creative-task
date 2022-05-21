#pragma once
#include <math.h>

namespace Calculator1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ColorDialog^ colorDialog1;

	private: System::Windows::Forms::ColorDialog^ colorDialog2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;

	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;







	private: System::ComponentModel::IContainer^ components;





	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog2 = (gcnew System::Windows::Forms::ColorDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::OldLace;
			this->tabPage1->Controls->Add(this->button14);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->comboBox2);
			this->tabPage1->Controls->Add(this->button15);
			this->tabPage1->Controls->Add(this->comboBox3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->button13);
			this->tabPage1->Controls->Add(this->button11);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->button10);
			this->tabPage1->Controls->Add(this->button9);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabPage1->Location = System::Drawing::Point(4, 32);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(507, 394);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Калькулятор";
			// 
			// button14
			// 
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button14->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button14->Location = System::Drawing::Point(255, 113);
			this->button14->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(110, 58);
			this->button14->TabIndex = 26;
			this->button14->Text = L"Очистить";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(66, 35);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(37, 45);
			this->textBox2->TabIndex = 1;
			this->textBox2->Click += gcnew System::EventHandler(this, &MyForm::textBox2_Click);
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::OldLace;
			this->textBox3->Enabled = false;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(255, 259);
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(236, 53);
			this->textBox3->TabIndex = 29;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::OldLace;
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBox1->Location = System::Drawing::Point(257, 188);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 53);
			this->textBox1->TabIndex = 28;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(230, 35);
			this->textBox4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(37, 45);
			this->textBox4->TabIndex = 9;
			this->textBox4->Click += gcnew System::EventHandler(this, &MyForm::textBox4_Click);
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(385, 34);
			this->textBox5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(37, 45);
			this->textBox5->TabIndex = 11;
			this->textBox5->Click += gcnew System::EventHandler(this, &MyForm::textBox5_Click);
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"+", L"-" });
			this->comboBox1->Location = System::Drawing::Point(9, 35);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(44, 46);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"+", L"-" });
			this->comboBox2->Location = System::Drawing::Point(171, 35);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(44, 46);
			this->comboBox2->TabIndex = 6;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// button15
			// 
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button15->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button15->Location = System::Drawing::Point(385, 113);
			this->button15->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(110, 58);
			this->button15->TabIndex = 27;
			this->button15->Text = L"Начать выполнение";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"+", L"-" });
			this->comboBox3->Location = System::Drawing::Point(326, 35);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(44, 46);
			this->comboBox3->TabIndex = 7;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(114, 38);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 38);
			this->label2->TabIndex = 8;
			this->label2->Text = L"X²";
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::Bisque;
			this->button13->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button13->Location = System::Drawing::Point(159, 321);
			this->button13->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(59, 58);
			this->button13->TabIndex = 24;
			this->button13->Text = L",";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::Bisque;
			this->button11->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(9, 321);
			this->button11->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(132, 58);
			this->button11->TabIndex = 22;
			this->button11->Text = L"0";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(281, 38);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 38);
			this->label3->TabIndex = 10;
			this->label3->Text = L"X";
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::Bisque;
			this->button10->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(159, 254);
			this->button10->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(59, 58);
			this->button10->TabIndex = 21;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Bisque;
			this->button9->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(82, 254);
			this->button9->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(59, 58);
			this->button9->TabIndex = 20;
			this->button9->Text = L"8";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(431, 38);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 38);
			this->label4->TabIndex = 12;
			this->label4->Text = L"= 0";
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Bisque;
			this->button8->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(9, 254);
			this->button8->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(59, 58);
			this->button8->TabIndex = 19;
			this->button8->Text = L"7";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Bisque;
			this->button2->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(82, 113);
			this->button2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(59, 58);
			this->button2->TabIndex = 13;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Bisque;
			this->button7->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(159, 183);
			this->button7->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(59, 58);
			this->button7->TabIndex = 18;
			this->button7->Text = L"6";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Bisque;
			this->button3->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(159, 113);
			this->button3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(59, 58);
			this->button3->TabIndex = 14;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Bisque;
			this->button6->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(82, 183);
			this->button6->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(59, 58);
			this->button6->TabIndex = 17;
			this->button6->Text = L"5";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Bisque;
			this->button4->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(9, 113);
			this->button4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(59, 58);
			this->button4->TabIndex = 15;
			this->button4->Text = L"1";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Bisque;
			this->button5->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(9, 183);
			this->button5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(59, 58);
			this->button5->TabIndex = 16;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(515, 430);
			this->tabControl1->TabIndex = 31;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::OldLace;
			this->tabPage3->Controls->Add(this->pictureBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 32);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(507, 394);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Теория";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(512, 398);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PapayaWhip;
			this->ClientSize = System::Drawing::Size(540, 457);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Linux Libertine G", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Калькулятор квадратных уравнений";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

//поля ввода коэффициентов и вывода ответов
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

//поля для выбора знака коэффициентов
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}

//обеспечивает пока картинки с теорией
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}

//производит очистку полей
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Text = ""; textBox2->Text = ""; textBox5->Text = ""; textBox1->Text = ""; textBox3->Text = "";
}

//проверка вводимых символов на допустимость
	   bool check_input_textbox()
	   {
		   int k = 0;
		   if ((textBox5->Text->Length == 0) || (textBox2->Text->Length == 0) || (textBox4->Text->Length == 0)) { return false; }
		   for (int i = 0; i < textBox5->Text->Length; i++)
		   {
			   if (textBox5->Text[i] == ',') { k++; }
			   else if ((textBox5->Text[i] >= '1' && textBox5->Text[i]) <= '9' && (k == 0 || k == 1)) {}
			   else { return false; }
		   }
		   k = 0;
		   for (int i = 0; i < textBox4->Text->Length; i++)
		   {
			   if (textBox4->Text[i] == ',') { k++; }
			   else if ((textBox4->Text[i] >= '1' && textBox4->Text[i]) <= '9' && (k == 0 || k == 1)) {}
			   else { return false; }
		   }
		   k = 0;
		   for (int i = 0; i < textBox2->Text->Length; i++)
		   {
			   if (textBox2->Text[i] == ',') { k++; }
			   else if ((textBox2->Text[i] >= '1' && textBox2->Text[i]) <= '9' && (k == 0 || k == 1)) {}
			   else { return false; }
		   }
		   k = 0;
		   return true;
	   }

//позволяют вводить цифры и знак запятой нажатием мышки
	   int code = 0;
	   System::Void textBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		   code = 1;
	   }
	   System::Void textBox4_Click(System::Object^ sender, System::EventArgs^ e) {
		   code = 2;
	   }
	   System::Void textBox5_Click(System::Object^ sender, System::EventArgs^ e) {
		   code = 3;
	   }
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "1";
	}
	else if (code == 2) {
		textBox4->Text += "1";
	}
	else if (code == 3) {
		textBox5->Text += "1";
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "2";
	}
	else if (code == 2) {
		textBox4->Text += "2";
	}
	else if (code == 3) {
		textBox5->Text += "2";
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "3";
	}
	else if (code == 2) {
		textBox4->Text += "3";
	}
	else if (code == 3) {
		textBox5->Text += "3";
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "4";
	}
	else if (code == 2) {
		textBox4->Text += "4";
	}
	else if (code == 3) {
		textBox5->Text += "4";
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "5";
	}
	else if (code == 2) {
		textBox4->Text += "5";
	}
	else if (code == 3) {
		textBox5->Text += "5";
	}
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "6";
	}
	else if (code == 2) {
		textBox4->Text += "6";
	}
	else if (code == 3) {
		textBox5->Text += "6";
	}
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "7";
	}
	else if (code == 2) {
		textBox4->Text += "7";
	}
	else if (code == 3) {
		textBox5->Text += "7";
	}
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "8";
	}
	else if (code == 2) {
		textBox4->Text += "8";
	}
	else if (code == 3) {
		textBox5->Text += "8";
	}
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "9";
	}
	else if (code == 2) {
		textBox4->Text += "9";
	}
	else if (code == 3) {
		textBox5->Text += "9";
	}
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += "0";
	}
	else if (code == 2) {
		textBox4->Text += "0";
	}
	else if (code == 3) {
		textBox5->Text += "0";
	}
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	if (code == 0)
	{
		textBox1->Text = "Что-то не так";
	}
	else if (code == 1) {
		textBox2->Text += ",";
	}
	else if (code == 2) {
		textBox4->Text += ",";
	}
	else if (code == 3) {
		textBox5->Text += ",";
	}
}

//нахождение корней уравнения
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	if (check_input_textbox()) {
		double Num1, Num2, Num3, Result1, Result2, Dis, sDis, nDis;
		char Z1, Z2, Z3;
		Z1= System::Convert::ToChar(comboBox1->Text);
		Z2= System::Convert::ToChar(comboBox2->Text);
		Z3= System::Convert::ToChar(comboBox3->Text);

		Num1 = System::Convert::ToDouble(textBox2->Text);
		Num2 = System::Convert::ToDouble(textBox4->Text);
		Num3 = System::Convert::ToDouble(textBox5->Text);

		if (Z1 == '-') { Num1 = Num1 * (-1); }
		if (Z2 == '-') { Num2 = Num2 * (-1); }
		if (Z3 == '-') { Num3 = Num3 * (-1); }

		Dis = Num2 * Num2 - 4 * Num1 * Num3;

		if (Dis > 0)
		{
			sDis = sqrt(Dis);
			Result1 = ((-Num2) + sDis) / (2 * Num1);
			Result2 = ((-Num2) - sDis) / (2 * Num1);
			textBox1->Text = System::Convert::ToString(Result1);
			textBox3->Text = System::Convert::ToString(Result2);
		}
		else if (Dis == 0)
		{
			Result1 = (-Num2) / (2 * Num1);
			textBox1->Text = System::Convert::ToString(Result1);
		}
		else if (Dis < 0)
		{
			nDis = -Dis;
			sDis = sqrt(nDis);
			Result1 = -Num2/2;
			Result2 = sDis/2;
			textBox1->Text = System::Convert::ToString(Result1+"-"+Result2+"i");
			textBox3->Text = System::Convert::ToString(Result1 + "+" + Result2 + "i");
		}
	}
	else
	{
		MessageBox::Show("Недопустимый ввод!");
	}
}
};
}

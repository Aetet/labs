#pragma once
//#include "Form1.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Lab3 {

	/// <summary>
	/// ������ ��� Dialog1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Dialog1 : public System::Windows::Forms::Form
	{
	public:
		Dialog1()
		{
			InitializeComponent();
			dA=-1;dB=-1;dC=-1;dD=-1;
		}

	unsigned grafn;
	int dA;
	int dB;
	int dC;
	int dD;
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Dialog1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(166, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"����� ����, ���������� ����� ��� �������� �������:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 43);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(83, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(101, 43);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(77, 21);
			this->comboBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"� �������� �����:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(12, 83);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(83, 21);
			this->comboBox3->TabIndex = 4;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(101, 83);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(77, 21);
			this->comboBox4->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(69, 26);
			this->button1->TabIndex = 6;
			this->button1->Text = L"&Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Dialog1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(101, 134);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(77, 26);
			this->button2->TabIndex = 7;
			this->button2->Text = L"�&�����";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Dialog1::button2_Click);
			// 
			// Dialog1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(190, 172);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Dialog1";
			this->Opacity = 0.8;
			this->Text = L"�������";
			this->Shown += gcnew System::EventHandler(this, &Dialog1::Dialog1_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 dA=this->comboBox1->SelectedIndex;
				 dB=this->comboBox2->SelectedIndex;
				 dC=this->comboBox3->SelectedIndex;
				 dD=this->comboBox4->SelectedIndex;
				 this->Hide();
				 //this->Parent->Refresh();
			 }
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->Hide();
			}
private: System::Void Dialog1_Shown(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for(int j=0;j<grafn;j++)
			 {
				 this->comboBox1->Items->Add(Convert::ToString(j));
				 this->comboBox2->Items->Add(Convert::ToString(j));
				 this->comboBox3->Items->Add(Convert::ToString(j));
				 this->comboBox4->Items->Add(Convert::ToString(j));				 
			 }
		 }
};
}

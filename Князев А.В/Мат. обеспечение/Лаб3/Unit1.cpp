//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
sg1->Cells[0][0]="�������";
sg1->Cells[1][0]="�����";
sg1->Cells[2][0]="���";
sg2->Cells[0][0]="�������������";
sg2->Cells[1][0]="��������";

}
//---------------------------------------------------------------------------
#define TT(X) case X:\
        sg1->Cells[0][sg1->RowCount-1]=r.value;\
        sg1->Cells[1][sg1->RowCount-1]=#X;\
        sg1->Cells[2][sg1->RowCount-1]=AnsiString(X);\
        sg1->RowCount=sg1->RowCount+1;\
        break;


void __fastcall TForm1::N3Click(TObject *Sender)
{
        sg1->RowCount=2;
        sg2->RowCount=2;
        LexReader r(Memo1->Text.c_str());
        Token t;
        try {
        while(( t = r.nextToken()) != END)
        {
                switch(t)
                {
                TT(TYPE_ID)
                TT(TYPE_NUM)
                TT(PLUS)
                //TT(MINUS)
                TT(MUL)
                TT(MORE)
                TT(LESS)
                TT(EQUAL)
                TT(BRACKET_OPEN)
                TT(BRACKET_CLOSE)
                TT(SEMICOLON)
                TT(KEYWORD_IF)
                TT(KEYWORD_ELSE)
                TT(KEYWORD_ENDIF)
                TT(KEYWORD_WHILE)
                TT(KEYWORD_ENDLOOP)
                }
        }
        }
        catch(...)
        {
        MessageBoxA(0,"������", "������ ��� ����������",MB_OK);
        }
        for(ArrayMap::iterator i = r.identifiers.begin();i!=r.identifiers.end();++i)
        {
                char* t = *i;
                sg2->Cells[0][sg2->RowCount-1] = t;
                sg2->Cells[1][sg2->RowCount-1] = i.getval();
                sg2->RowCount = sg2->RowCount+1;
        }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
        try {
                Parser p(Memo1->Text.c_str());
                if(p.parse())MessageBoxA(0,"������� ���������","���������",MB_OK);
        }
        catch(LexReader::Error err)
        {
                MessageBoxA(0,
                (AnsiString("����������� ������\"")+AnsiString(err.message)+"\" � ������� "+AnsiString(err.position)).c_str(),
                "������",MB_OK);
        }
        catch(Parser::Error err)
        {
                MessageBoxA(0,"�������������� ������","������",MB_OK);
        }
}
//---------------------------------------------------------------------------


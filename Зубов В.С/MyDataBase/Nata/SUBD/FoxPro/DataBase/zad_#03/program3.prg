&& ������� ����������������:

&& ���������������� � ������
A="����"
? "&A ������!" 
? "&A ������!"
? "��-��-��, &A!"

&& ���������������� � ��������: 
&& � ������� USE, LIST, SET FILTER TO, ERASE
E="table_employee"					&& ���������������� ��� USE
O="otchestvo"						&& ���������������� ��� LIST
C="table_children"					&& ���������������� ��� USE
F="(childr->children_2!=' ')"		&& ���������������� ��� SET TO FILTER TO
FIL="1.txt"							&& ���������������� ��� ERASE
USE &E AGAIN
USE &C IN 2 AGAIN ALIAS childr
SELECT 2
INDEX ON association_child TO ass_childr
SELECT 1
SET RELATION TO association_child INTO childr
SET FILTER TO &F
LIST family_name,name_,&O
ERASE $FIL

&& ���������������� � ���������
SET DATE TO BRITISH
D="Date()+7"
? Dow(&D)				

&& �������� ����������������
nn="Date()"
mm="&nn+2"
? &mm
? "&mm"
&& ������������ ����� � ������� �� ����������� ���������
? " "
USE table_employee AGAIN
INDEX ON family_name TO f_name 			&& �������������� �� �����

&& ������� 1
key_="�����"		 					&& ���� ������
SEEK key_								&& �����
IF Found()
	 ?Recno(),family_name,name_,otchestvo
ELSE 
	?"  ���� c �������� �����"
ENDIF

&& ������� 2
SET EXACT OFF
key_="������"
SEEK key_								&& �����
DO WHILE (family_name=key_)
	 ?Recno(),family_name,name_,otchestvo
	 SKIP
ENDDO

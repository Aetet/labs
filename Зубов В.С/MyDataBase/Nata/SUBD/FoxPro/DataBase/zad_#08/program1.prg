&& ������� ������� ������ ����, ��������, ������� + ���� ��������
SET DATE BRITISH
USE table_employee AGAIN
INDEX ON Upper(family_name)+Dtoc(birthday) TO fdate
BROWSE TITLE "���������� ��������������� �� �������;
 �������+����(�����) ��������"
SET ORDER TO												&& ����� ����������

&& ��������� ������������ ��������
INDEX ON Upper(family_name) TO fam
INDEX ON Upper(name_) TO nam
INDEX ON Upper(otchestvo) TO otc
USE table_employee AGAIN INDEX fam,nam,otc
SET ORDER TO 1
? "������� ������ ��� �������������� �� �������",Recno(),family_name
BROWSE TITLE "���������� ������������������ �� �������"

SET ORDER TO 2
? "������� ������ ��� �������������� �� �����",Recno(),family_name
BROWSE TITLE "���������� ������������������ �� �����"

SET ORDER TO 3
? "������� ������ ��� �������������� �� ��������",Recno(),family_name
BROWSE TITLE "���������� ������������������ �� ��������"

&& �������� ������� ����� ���������� � ��������� ��������
key_=Upper("��������")
SEEK key_
IF Found()
	? family_name,name_,otchestvo
ELSE 
	? "� ��������� �������� ������ �� ����������"
ENDIF
BROWSE
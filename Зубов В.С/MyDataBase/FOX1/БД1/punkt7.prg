SET DEFA TO H:\FOX1\��1

CLEAR
SELECT 1

WAIT WINDOW '����������� �� ����� ��� � ����'
Use main AGAIN ALIAS toys
INDEX ON tip+STR(price) TO compos_indx

BROWSE TITLE "������ ������������� �� ���� � ����"

SET ORDER TO

WAIT WINDOW '��������� ������������ ��������'

INDEX ON tip TO type_indx
INDEX ON STR(price) TO price_indx
INDEX ON izdelie TO izd_indx
USE main AGAIN ALIAS toys INDEX type_indx,price_indx,izd_indx

WAIT WINDOW '��������� �� ����'
SET ORDER TO 1
? "������� ������ ��� �������������� �� ����",Recno(),izdelie
BROWSE TITLE "�������, ������������������ �� ����"

SET ORDER TO 2
? "������� ������ ��� �������������� �� ����",Recno(),izdelie
BROWSE TITLE "�������, ������������������ �� ����"

SET ORDER TO 3
? "������� ������ ��� �������������� �� ��������",Recno(),izdelie
BROWSE TITLE "�������, ������������������ �� ��������"

WAIT WINDOW '�������� ������� ����� ������� � ��������� �����-�����'
?
? "�������� ������� ����� ������ � ��������� �����-�����"
key_= "�����-�����"
SEEK key_
IF Found()
	? izdelie ,firm_name,tip
	WAIT WINDOW izdelie+firm_name
ELSE 
	? "����� �������  � ���� ���!"
	WAIT WINDOW '����� ������� � ���� ���!'
ENDIF
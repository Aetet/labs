SET DEFA TO H:\FOX1\��2

CLEAR
SELECT 1

WAIT WINDOW '����������� �� ����� ������������� � ����� �������'
Use main AGAIN ALIAS films
INDEX ON cinema+STR(god) TO compos_indx

BROWSE TITLE "������ ������������� �� ������������� � ����� �������"

SET ORDER TO

WAIT WINDOW '��������� ������������ ��������'

INDEX ON cinema TO cin_indx
INDEX ON STR(god) TO god_indx
INDEX ON nazvanie TO naz_indx
USE main AGAIN ALIAS films INDEX cin_indx,god_indx,naz_indx

WAIT WINDOW '��������� �� �������������'
SET ORDER TO 1
? "������� ������ ��� �������������� �� ������������",Recno(),nazvanie
BROWSE TITLE "������, ������������������ �� ������������"

SET ORDER TO 2
? "������� ������ ��� �������������� �� ���� �������",Recno(),nazvanie
BROWSE TITLE "������, ������������������ �� ���� �������"

SET ORDER TO 3
? "������� ������ ��� �������������� �� ��������",Recno(),nazvanie
BROWSE TITLE "������, ������������������ �� ��������"

WAIT WINDOW '�������� ������� ����� ������ � ��������� "�����"'
?
? "�������� ������� ����� ������ � ��������� �����"
key_= "�����"
SEEK key_
IF Found()
	? nazvanie ,regesser,cinema
	WAIT WINDOW nazvanie+regesser
ELSE 
	? "������ ������ � ���� ���!"
	WAIT WINDOW '������ ������ � ���� ���!'
ENDIF
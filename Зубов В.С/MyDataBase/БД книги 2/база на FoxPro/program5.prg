CLEAR
SET DEFA TO "D:\���� �� FoxPro"
SELECT 1

WAIT WINDOW '����������� �� ����� ��� ������� � ����� �����'
USE maintable Again
INDEX ON STR((imprintdat)+(copies) ) TO first_indx ASCENDING 
&&STR (<���N > [,<���N > [,<���-��>]]) 
&&INDEX ON STR(imprintdat)+copies TO first_indx
BROWSE TITLE "����� �������������� �� ���� ������� � ����� ����� "
SET ORDER TO

WAIT WINDOW '��������� ������������ ��������'

INDEX ON STR(imprintdat)TO printdat_indx
INDEX ON copies TO copi_indx
INDEX ON book_name TO name_indx
USE maintable AGAIN INDEX printdat_indx,copi_indx,name_indx

WAIT WINDOW '��������� �� ���� �������'
SET ORDER TO 1
?"������� ������ ��� ��������������� �� ���� �������",Recno(),book_name
BROWSE TITLE "�����, ��������������� �� ���� �������"

SET ORDER TO 2
?"������� ������ ��� ��������������� �� ����� �����",Recno(),book_name
BROWSE TITLE "�����, ��������������� �� ����� �����"

SET ORDER TO 3
?"������� ������ ��� ��������������� �� �������� �����",Recno(),book_name
BROWSE TITLE "�����, ��������������� �� �������� �����"


 
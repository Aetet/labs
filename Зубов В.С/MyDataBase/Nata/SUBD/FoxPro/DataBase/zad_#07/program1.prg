&& ����� ����������� ������ ������� � ������ �������
&& �.�. ����� � memo-���� curent_works �� ��������� "1-"?,
&& � ����� ���������� ��� ������������.
USE table_employee AGAIN

SET FILTER TO (sex="�")				&& ��������� ������� �������

&& �����
BROWSE TITLE "������� ������� � ������ �������";
FIELDS family_name:H="�������",name_:H="���",;
otchestvo:H="��������",birthday:H="���� ��������",;
missions:H="������������" FOR Like("*1-*",curent_works)
&& ������� � ������ �������
BROWSE

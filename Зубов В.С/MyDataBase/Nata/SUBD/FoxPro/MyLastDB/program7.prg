clear
*? "���� �����������, ������� ��������� ������������ � ������� ��������"
*? "�.�. ����� � memo-���� comments �� ��������� "STREET RAC"
*? "� ����� ����� ���� �����������."

Set DEFA TO c:\ALANsProgs\work\FoxPro\MyLastDB\
select 1
USE table1 AGAIN ALIAS main

&& �����
BROWSE NOEDIT TITLE "Undeground CARS";
FIELDS firm:H="�������������",title:H="�����",cena:H="����",;
massa:H="����� ����",;
comments:H="�������" FOR Like("*STREET RAC*",Upper(comments))
&& ������� � ������ �������
BROWSE

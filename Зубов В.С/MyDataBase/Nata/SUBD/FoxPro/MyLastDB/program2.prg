Set DEFA TO c:\ALANsProgs\work\FoxPro\MyLastDB\

U="table1"           && ���������������� ��� USE
L="car_firm"         && ���������������� ��� LIST
A1="car_param"
A2="&A1->motortype"  && �������� ����������������

clear
&& �������� 3 ������� �������, ������ ����� 1:1 � 1:N � ������ ����� LIST � BROUSE
select 1
use &U IN 1 AGAIN alias main                       && ���������������� ��� USE
SELECT 2
USE table4 IN 2 AGAIN alias car_firm
INDEX ON firm TO firm_ind
select 3
use table3 in 3 AGAIN alias car_param
INDEX ON number TO num_ind
select 1
SET RELATION TO firm INTO car_firm
SET RELATION TO number INTO car_param ADDITIVE

list title,Iif(Found("&L"),car_firm->firm,"Unknown") && ���������������� ��� LIST


BROWSE NOEDIT TITLE "������" PARTITION 45 LEDIT;
FIELDS title:H="��������",cena:H="����",;
&A2:H="��� ���������",car_firm->firm:H="�������������",; && ���������� �������� ���������������������
car_firm->phone:H="������� �������"
&& ���������������� � ���������
SET DATE TO BRITISH
D="Date()+7"
? Dow(&D)				
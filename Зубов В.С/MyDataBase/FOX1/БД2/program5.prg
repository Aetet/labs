clear
? "������� �������� �������, ������� �� ������ �� ���������� "
accept "a,b,c,d  - " to tb
use main IN a again 
use regeser_info IN b again 
use acter IN c again
use video IN d again
do case 
case tb=="a"
select a
case tb=="b"
select b
case tb=="c"
select c
case tb=="d"
select d
otherwise 
? "������������ ���� �������"
endcase
list all 
accept "������� �������� ������ � ������� �� �� ������ �������� ���������� :  " to naz
select b
LOCATE for nazvanie=naz
? "���������� � ������: "
? "�������� : ", regesser
? "������������ :", cinema 
? "����������������� :", vremya 
SELECT a
LOCATE FOR reg==d.reg
? "����� :",nazvanie

Set DEFA TO c:\ALANsProgs\work\FoxPro\MyLastDB\
&& ������ �������� ������������� FOX-����
DECLARE munu1[5]

munu1[1]=" ������� \<������������� ���������� "
munu1[2]=" ������� \<��������� "
munu1[3]=" ������� \<��� "
munu1[4]="\-"
munu1[5]=" �\<����"

@ 0,0 MENU munu1,5 TITLE "������������ ����" 

DO WHILE .T.
	READ MENU TO n SAVE
	DO CASE
		CASE n=1
			SELECT a.title AS "��������",a.firm AS "�����",b.country AS "������_�������������";
			FROM table1 a,table4 b WHERE ((a.firm=b.firm)and(Upper(b.country)="RUSSIA"));
			ORDER BY a.title
		CASE n=2
			SELECT a.title AS "��������",a.firm AS "�����",b.country AS "������_�������������";
			FROM table1 a,table4 b WHERE ((a.firm=b.firm)and(Upper(b.country)!="RUSSIA"));
			ORDER BY a.title
		CASE n=3
			SELECT a.title AS "��������",a.firm AS "�����",b.country AS "������_�������������";
			FROM table1 a,table4 b WHERE (a.firm=b.firm);
			ORDER BY a.title
		CASE n=5
			EXIT
	ENDCASE
ENDDO
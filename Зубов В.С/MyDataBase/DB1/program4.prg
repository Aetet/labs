SET DEFA TO D:\6sem\MyDataBase\lab1
&& ������� ����
DECLARE MainMenu[3,2]
MainMenu[1,1]="�������"
MainMenu[2,1]="�����"
MainMenu[3,1]="�����"
MainMenu[1,2]="����� ���������"
MainMenu[2,2]="����� ��������� �������� �����"
MainMenu[3,2]="�����"

&& "�������"
DECLARE Menu1[3], Menu2[3]
Menu1[1]="����� �����������"
Menu1[2]="����� ����������"
Menu1[3]="����� ����������� �������"
Menu2[1]="Sony"
Menu2[2]="Panasonic"
Menu2[3]="JVC"

MENU BAR MainMenu,3
MENU 1,Menu1,3
MENU 2,Menu2,3

DO WHILE .T.
	READ MENU BAR TO i,j SAVE
	DO CASE
		CASE i=1
			DO CASE
			  CASE j=1		
               SELECT mname AS "��������", tipe AS "���", quantity AS "����������", price AS "����", firm AS "�����", address AS "�����";
               FROM models, firms WHERE id_firm=f_id AND mname="���������";
               ORDER BY firm
			  CASE j=2
               SELECT mname AS "��������", tipe AS "���", quantity AS "����������", price AS "����", firm AS "�����", address AS "�����";
               FROM models, firms WHERE id_firm=f_id AND mname="�����������";
               ORDER BY firm
              CASE j=3
               SELECT mname AS "��������", tipe AS "���", quantity AS "����������", price AS "����", firm AS "�����", address AS "�����";
               FROM models, firms WHERE id_firm=f_id AND mname="����������� �����";
               ORDER BY firm
			ENDCASE
		
		CASE i=2
			DO CASE
			  CASE j=1		
			   SELECT mname AS "��������", tipe AS "���", quantity AS "����������", price AS "����";
               FROM models WHERE firm="Sony";
               ORDER BY mname
			  CASE j=2
			   SELECT mname AS "��������", tipe AS "���", quantity AS "����������", price AS "����";
               FROM models WHERE firm="Panasonic";
               ORDER BY mname
			  CASE j=3
			   SELECT mname AS "��������", tipe AS "���", quantity AS "����������", price AS "����";
               FROM models WHERE firm="JVC";
               ORDER BY mname
			ENDCASE
		CASE i=3			
			EXIT
	ENDCASE
ENDDO
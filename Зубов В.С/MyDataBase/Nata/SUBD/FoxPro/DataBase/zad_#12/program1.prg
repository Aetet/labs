&& ������ �������� ������������� FOX-���� (POPUP)
&& ������ ����
DECLARE puncts[5]
puncts[1]="������� \<���������"
puncts[2]="������� \<������ ������������(����� ���������)"
puncts[3]="������� \<����"
puncts[4]="\-"
puncts[5]="�\<����"

&& ��������� ����
@ 0,0 MENU puncts,5 TITLE "POPUP ����" 

&& ���� ����
DO WHILE .T.
	READ MENU TO n SAVE
	DO CASE
		CASE n=1
			SELECT family_name AS "�������",post AS "���������";
			FROM table_employee a WHERE Upper(a.post)="�������";
			ORDER BY family_name
		CASE n=2
			SELECT family_name AS "�������",post AS "���������";
			FROM table_employee a WHERE Upper(a.post)!="�������";
			ORDER BY family_name,post
		CASE n=3
			SELECT family_name AS "�������",post AS "���������";
			FROM table_employee ORDER BY family_name,post
		CASE n=5
			EXIT
	ENDCASE
ENDDO
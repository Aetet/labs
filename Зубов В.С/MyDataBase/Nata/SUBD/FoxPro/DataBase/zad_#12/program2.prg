&& ������ �������� ������������ FOX-���� (PULLDOWN)
&& ������ ����

&& ��������������
DECLARE g_punct[3,2]
g_punct[1,1]="�����"
g_punct[2,1]="����������"
g_punct[3,1]="�����"
g_punct[1,2]="����� ������� ��������������� �������"
g_punct[2,2]="���������� ������� �� ��������� ����"
g_punct[3,2]="�����"

&& ������������
DECLARE v_1[2],v_2[4]
v_1[1]="����� ������"
v_1[2]="����� ������"
v_2[1]="����������� �� �������"
v_2[2]="����������� �� ���� ��������"
v_2[3]="����������� �� ���������"
v_2[4]="����������� �� ��������"

&& ��������� ����
MENU BAR g_punct,3
MENU 1,v_1,2
MENU 2,v_2,4

&& ���� ����
DO WHILE .T.
	READ MENU BAR TO i,j SAVE
	DO CASE
		
		CASE i=1
			DO CASE
			  CASE j=1		
				SELECT family_name AS "�������",post AS "���������";
				FROM table_employee a WHERE Upper(a.sex)="�";
				ORDER BY family_name
			  CASE j=2
			 	SELECT family_name AS "�������",post AS "���������";
				FROM table_employee a WHERE Upper(a.sex)="�";
				ORDER BY family_name,post
			ENDCASE
		
		CASE i=2
			DO CASE
			  CASE j=1		
				SELECT * FROM table_employee ORDER BY family_name
			  CASE j=2
			 	SELECT * FROM table_employee ORDER BY birthday
			  CASE j=3		
				SELECT * FROM table_employee ORDER BY post
			  CASE j=4
			 	SELECT * FROM table_employee ORDER BY pay			
			ENDCASE

		CASE i=3			
			EXIT
	ENDCASE
ENDDO

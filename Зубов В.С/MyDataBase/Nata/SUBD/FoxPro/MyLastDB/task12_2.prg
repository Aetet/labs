&& ������ �������� ������������ FOX-����

&& ��������������
DECLARE g_menu[3,2]
g_menu[1,1]="�������"
g_menu[2,1]="��������� ��..."
g_menu[3,1]="�\<����"
g_menu[1,2]="����� ������� ��������������� �������"
g_menu[2,2]="���������� ������� �� ��������� ����"
g_menu[3,2]="�����"

&& ������������
DECLARE v_menu1[2],v_menu2[3]
v_menu1[1]="����� ������������� ����������"
v_menu1[2]="����� ���������"
v_menu2[1]="��������� �� ��������"
v_menu2[2]="��������� �� �����"
v_menu2[3]="��������� �� ����"
*v_2[4]="����������� �� ��������"

&& ��������� ����
MENU BAR g_menu,3
MENU 1,v_menu1,2
MENU 2,v_menu2,3

&& ���� ����
DO WHILE .T.
	READ MENU BAR TO i,j SAVE
	DO CASE
		
		CASE i=1
			DO CASE
			  CASE j=1		
               SELECT a.title AS "��������",a.firm AS "�����",b.country AS "������_�������������";
               FROM table1 a,table4 b WHERE ((a.firm=b.firm)and(Upper(b.country)="RUSSIA"));
               ORDER BY a.title
			  CASE j=2
               SELECT a.title AS "��������",a.firm AS "�����",b.country AS "������_�������������";
               FROM table1 a,table4 b WHERE ((a.firm=b.firm)and(Upper(b.country)!="RUSSIA"));
               ORDER BY a.title
			ENDCASE
		
		CASE i=2
			DO CASE
			  CASE j=1		
				SELECT * FROM table1 ORDER BY title
			  CASE j=2
			 	SELECT * FROM table1 ORDER BY firm
			  CASE j=3		
				SELECT * FROM table1 ORDER BY cena
			ENDCASE

		CASE i=3			
			EXIT
	ENDCASE
ENDDO

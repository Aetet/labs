SET DEFA TO D:\Downloads\����\MyBD

&& �������� ������������� ����

&& "��������������" ����
DECLARE MainMenu[3,2]
MainMenu[1,1]="�������"
MainMenu[2,1]="����������� ��..."
MainMenu[3,1]="�\<����"
MainMenu[1,2]="����� ������� ��������������� �������"
MainMenu[2,2]="���������� ������� �� ��������� ����"
MainMenu[3,2]="�����"

&& "������������ ����"
DECLARE Menu1[2], Menu2[3]
Menu1[1]="����� ���������� ����"
Menu1[2]="����� ���� ���������� �������"
Menu2[1]="����������� �� ��������"
Menu2[2]="����������� �� ������"
Menu2[3]="����������� �� ������������"

&& ��������� ����
MENU BAR MainMenu,3
MENU 1,Menu1,2
MENU 2,Menu2,3

&& ���� ����
DO WHILE .T.
	READ MENU BAR TO i,j SAVE
	DO CASE
		
		CASE i=1
			DO CASE
			  CASE j=1		
               SELECT a.title AS "��������",a.auth_surname AS "�����",b.country AS "������";
               FROM main a, authorinfo b WHERE ((a.author_id=b.author_id) AND (b.country="������"));
               ORDER BY a.title
			  CASE j=2
               SELECT a.title AS "��������",a.auth_surname AS "�����",b.country AS "������";
               FROM main a, authorinfo b WHERE ((a.author_id=b.author_id) AND NOT (b.country="������"));
               ORDER BY a.title
			ENDCASE
		
		CASE i=2
			DO CASE
			  CASE j=1		
				SELECT * FROM main ORDER BY title
			  CASE j=2
			 	SELECT * FROM main ORDER BY auth_surname
			  CASE j=3
			 	SELECT * FROM main ORDER BY publisher			 	
			ENDCASE

		CASE i=3			
			EXIT
	ENDCASE
ENDDO


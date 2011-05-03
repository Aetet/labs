SET DATE TO BRITISH 									 && ��������� ���� DD/MM/YY
&& ������ 4 �������: �������, ������, ����, �����
&& ������� ������� ���� ������� ����� � �����, �� 
&& ������ � ����� ���� ����� � ���� BROWSE
SELECT 2
USE table_address IN 2 AGAIN ALIAS addr          		 && ������� ������� ������� �� 2 ���.
INDEX ON association_adr TO ass_adr             		 && ������ �������������� ����. �������

SELECT 3
USE table_sadik IN 3 AGAIN ALIAS sadik			 		 && ������� ������� ����� � 3 ���.
INDEX ON association_sadik TO ass_sadik          		 && ������ �������������� ����. �����

SELECT 4
USE table_children IN 4 AGAIN ALIAS child        		 && ������� ������� ����� �� 4 ���.
INDEX ON association_child TO ass_child          		 && ������ �������������� ����. �����

SELECT 1										 		 && �������� � 1 ������� ���.
USE table_employee AGAIN					 		 	 && ������� ����. ������� � 1 ���.
SET RELATION TO association_adr INTO addr		         && ������ ����. ������� � ����. �������
SET RELATION TO association_child INTO child ADDITIVE	 && ������ ����. ������� � ����. �����
SET RELATION TO association_sadik INTO sadik ADDITIVE	 && ������ ����. ������� � ����. �����

SET FILTER TO (association_sadik!=0)

BROWSE TITLE "�������" FIELDS family_name:H="�������",;
name_:H="���",addr->cite=Iif(addr->cite!=" ",addr->cite,;
"�� ��������"):H="�����",addr->street:H="�����",;
addr->house:H="���",child->children_1=Iif(sadik->;
child_1_insert,child->children_1+" �����",;
"�������"):23:H="1-�� �������",child->children_2=;
Iif(sadik->child_2_insert,child->children_2;
+" �����","�������"):23:H="2-�� �������",child->;
children_3=Iif(sadik->child_3_insert,child->children_3;
+" �����","�������"):23:H="3-�� �������"


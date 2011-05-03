&& 1. ����� ������� ������ ������������� SELECT
&& ����� ����������� � ���������� ������ > 20000
SELECT family_name,name_,otchestvo,pay; 
FROM table_employee a WHERE a.pay>1500;
ORDER BY family_name,name_,otchestvo

&& 2. ���� ������� � �������������� ���������� �����(GROUP BY)
&& ���������� �� ���������� � ����� ��������� ���������� ����
SELECT post,Sum(pay) FROM table_employee GROUP BY post ORDER BY post

&& 3. � �������������� ���� ������ � �������� HAVING
&& (������� �������� ������ � ��������� GROUP BY).
&& ����� �����������: �.�.�., ����� ����� ������� ����������
SELECT family_name AS "�������",name_ AS "���",otchestvo AS "��������";
,Count(child_name) AS "����������_�����";
FROM table_employee a,table_children b GROUP BY a.birthday;
WHERE a.parent_=b.parent_ HAVING Count(child_name)>=2;
ORDER BY family_name,name_,otchestvo

&& 4. � �������������� �������� DISTINCT 
&& (���������������� ����� ���� ���������� �����)
&& ����� ����������� ������� ����� ��� ���������� ������� �����������
SELECT DISTINCT family_name AS "�������";
FROM table_employee a,table_children b WHERE a.parent_=b.parent_;
ORDER BY family_name

&& 5. � �������������� �������� UNION
&& ����������� ������� ����������� ������� ����� � �� ������� �����
&&  � ������� ����� "�� ���������" 
SELECT name_,birthday,Iif(parent_>0,"��������  ","����������");
FROM table_employee UNION SELECT child_name,child_date,"�������"; 
FROM table_children;
ORDER BY 3 DESC,2,1

&& 6. � ������� � ����� �������
&& ��� �� ������ 5
SELECT name_,birthday,Iif(parent_>0,"��������  ","����������") AS "������";
FROM table_employee UNION SELECT child_name,child_date,"�������"; 
FROM table_children INTO DBF table1;
ORDER BY 3 Desc,2,1
CLOSE DATABASES
SELECT * FROM table1 ORDER BY ������ DESC, birthday, name_

&& 7. ������ ������������� "��������������� �������"
&& ����� �., ���� ��������, ��������� � �������� �����������,
&& ������� �������� ���� �������� ��� ����� ���������.
SELECT family_name AS "�������",birthday AS "����_��������",post AS "���������",;
pay AS "��������" FROM table_employee a WHERE pay>(SELECT Avg(pay) ;
FROM table_employee b WHERE a.post=b.post);
ORDER BY post,pay,family_name,birthday

&& 8. ������ ������������� "�������� �������������"
&& ����� �. � ��� �������� ��������� �����������
SELECT family_name AS "�������",birthday AS "����_��������" ;
FROM table_employee a ORDER BY birthday,family_name ;
WHERE NOT EXISTS (SELECT * FROM table_children b WHERE a.parent_=b.parent_)

&& 9. ������ ������������� "����������� � ������������� �����������" (ALL)
&& ����� �. � ��� �������� ������ ����������� ���������� ������ �������
SELECT family_name AS "�������",birthday AS "����_��������" ;
FROM table_employee a ORDER BY birthday WHERE Upper(sex)="�" AND post="���������";
AND pay> ALL(SELECT pay FROM table_employee b WHERE Upper(sex)="�") 

&& 10. ������ ������������� "����������� � ������������� �����������" (ANY)
&& ��������� ���������� ����������� ������ �� ������� 9.
SELECT family_name AS "�������",birthday AS "����_��������" ;
FROM table_employee a ORDER BY birthday WHERE Upper(sex)="�" AND post="���������";
AND pay<= ANY(SELECT pay FROM table_employee b WHERE Upper(sex)="�") 

&& 11. ������ � �������������� "������� ������������" � SELECT
&& ������� �������� ����������� � ������� ������ 10% �� �.�.
SELECT family_name,birthday,pay,F(pay) AS "�_�_�_�������" FROM table_employee
FUNCTION F
	PARAM pay,pay_next
	pay_next=pay+0.1*pay
RETURN pay_next
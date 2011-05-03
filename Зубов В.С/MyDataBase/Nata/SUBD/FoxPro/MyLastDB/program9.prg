Set DEFA TO c:\ALANsProgs\work\FoxPro\MyLastDB\
clear

&& 1. ����� ������� ������ ������������� SELECT
&& ����� �����������, ���� ������� >100000$
SELECT firm AS "�������������",title AS "��������",cena AS "����"; 
FROM table1 a WHERE a.cena>100000;
ORDER BY cena,firm,title

&& 2. ���� ������� � �������������� ���������� �����(GROUP BY)
&& ���������� �� ������������� � ����� ��������� ���� �� ���������� ���� �����
SELECT table1.firm,Sum(table1.cena),table4.phone FROM table1,table4 GROUP BY table1.firm ORDER BY cena
SELECT firm AS "�������������",Sum(cena) AS "����_��_���" FROM table1 GROUP BY firm ORDER BY cena

&& 3. � �������������� ���� ������ � �������� HAVING
&& (������� �������� ������ � ��������� GROUP BY).
&& ����� ������ ������������� �����������.
SELECT a.firm AS "�������������",Sum(a.cena) AS "����_��_���",Count(a.title) AS "����������_�������";
,b.country AS "������_�������������" FROM table1 a,table4 b GROUP BY a.firm;
WHERE a.firm=b.firm HAVING b.country="Russia";
ORDER BY a.firm,b.country

&& 4. � �������������� �������� DISTINCT 
&& (���������������� ����� ���� ���������� �����)
&& ����� ����, ���� ������� ������������ � ��
SELECT DISTINCT a.firm AS "�������������_����";
FROM table1 a,table4 b WHERE a.firm=b.firm;
ORDER BY a.firm

&& 5. ����������� ������� ����������� ������� ����� � �� ������� �����
&&  � ������� ����� "�� ���������" 
*SELECT b.firm; 
*FROM table1 c,table4 b where empty(b.firm=c.firm)
*SELECT a.firm,a.title;
*FROM table1 a UNION ()
*ORDER BY a.firm

*UNION SELECT child_name,child_date,"�������"; 
*FROM table_children;

*SELECT title,firm FROM table1 UNION SELECT motortype FROM table3


&& 6. � ������� � ����� �������, ��������� ������ �� ���� ������
SELECT a.title,a.firm,a.cena,b.country;
FROM table1 a, table4 b where a.firm=b.firm INTO DBF table5;
ORDER BY cena
CLOSE DATABASES
SELECT * FROM table5 ORDER BY cena

&& 7. ������ ������������� "��������������� �������"
&& ����� �����������, ������� ����� ���� ��������
SELECT a.firm AS "�����",a.title AS "��������",a.cena AS "����";
FROM table1 a WHERE a.cena>(SELECT Avg(b.cena) FROM table1 b);
ORDER BY a.cena

&& 8. ������ ������������� "�������� �������������"
&& ����� ����, ���� ������� ��� � ��
SELECT a.firm AS "�����", a.phone AS "�������",a.country AS "������_�������������";
FROM table4 a ORDER BY a.firm ;
WHERE NOT EXISTS (SELECT * FROM table1 b WHERE a.firm=b.firm)

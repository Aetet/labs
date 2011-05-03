CLEAR
SET DEFA TO H:\FOX1\��1

&& 1 ������� �������, � ����� ����� 500 � 1800 �������
SELECT izdelie AS "�������",firm_name AS "�����", price AS "����" FROM main;
WHERE price BETWEEN 500 AND 1800 ORDER BY izdelie

&& 2 ������� ��� ����� � ���������� �� �������, ������������ �� ������ 
SELECT firm.firm_name, firm.firm_adr, Sum(firm.assortiment),;
tip.tip FROM firm, tip;
WHERE firm.izdelie_kl=firm.izdelie_kl AND firm.izdelie_kl=tip.izdelie_kl;
GROUP BY firm.firm_name;
ORDER BY firm.firm_name ASC


&& 3 ���������� ������� HAVING, ������� ���������� � ��������� ������
SELECT main.izdelie AS "�������", main.firm_name AS "�����",;
COUNT(main.assortiment) AS "���������� �������",  firm.firm_adr AS "�.���������" FROM main, firm;
WHERE main.izdelie_kl = firm.izdelie_kl;
GROUP BY  main.izdelie;
HAVING firm.firm_adr = "�.���������" 

 

&& 4 ���������� ������� DISTINCT
SELECT DISTINCT firm.firm_name AS "�����" FROM  firm, tip;
WHERE firm.izdelie_kl = tip.izdelie_kl ORDER BY firm.firm_name DESC

&& 5 ������� ������� ��������
SELECT firm.firm_name AS "�����",Sum(firm.assortiment) AS "����������";
FROM firm  WHERE firm.assortiment > (SELECT AVG(main.assortiment);
FROM main) ORDER BY firm.firm_name DESC

&& 6 ������� ������ � ����� �������
SELECT a.firm_name, b.izdelie, c.firm_adr FROM;
main a, izdelie b, firm c WHERE a.izdelie_kl = b.izdelie_kl;
AND b.izdelie_kl = c.izdelie_kl INTO DBF NewTable ORDER BY c.firm_adr DESC
CLOSE DATABASES
SELECT * FROM NewTable

&&�������� ����� ������� � �������� �� 
CREATE DBF TestBase( izdelie C(30), firm_name C(50),tip C(50))
INSERT INTO TestBase (izdelie, firm_name, tip);
VALUES ("����","Nikki","���������� ����")
INSERT INTO TestBase (izdelie, firm_name, tip);
VALUES ("�������","Hallmark","���������� ����")
INSERT INTO TestBase (izdelie, firm_name, tip);
VALUES ("�����","Sunny","�����")
INSERT INTO TestBase (izdelie, firm_name, tip);
VALUES ("����","Hallmark","������������")
CLOSE DATABASES
SELECT * FROM TestBase ORDER BY izdelie

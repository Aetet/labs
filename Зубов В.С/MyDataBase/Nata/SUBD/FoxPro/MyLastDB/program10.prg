&& �������� �.�. ���������� � ������ �����, ��������, ����, ��������, �����
CREATE DBF table_auto(firm C(10), title c(10), cena I(10), owner c(10), number c(6))

&& ������� ������ � ��������� �.�.
INSERT INTO table_auto(firm,title,cena,owner,number) VALUES("Mitsubisy","Land Rover",;
238456,"�����","mm001m")
INSERT INTO table_auto(firm,title,cena,owner,number) VALUES("Pejo","206",;
35000,"������","��254�")
INSERT INTO table_auto(firm,title,cena,owner,number) VALUES("������","21041",;
7000,"�������","�485��")
INSERT INTO table_auto(firm,title,cena,owner,number) VALUES("�����","��������",;
190000,"��������","��2323��")

CLOSE DATABASES
&& ������� �������
SELECT * FROM table_auto ORDER BY title
&& ����� 10
CLEAR
SET DEFA TO D:\6sem\MyDataBase\lab1\

USE models

CLEAR
DEFINE WINDOW Okno1 FROM 1,3 TO 50,110 TITLE "������ (Edit)" SYSTEM CLOSE FLOAT GROW MINIMIZE ZOOM
SHOW WINDOW Okno1
&&DEFINE WINDOW Okno2 FROM 1,3 TO 50,110 TITLE "������ (Browse)" SYSTEM CLOSE FLOAT GROW MINIMIZE ZOOM
&&SHOW WINDOW Okno2

EDIT FIELDS mname:20:H="������", firm:15:H="�����", tipe:15:H="���";
FOR mname="�����������";
FONT 'Courier New',10 TITLE "�����������" IN Okno1

BROWSE FIELDS mname:20:H="������", firm:15:H="�����", tipe:15:H="���";
FOR firm="Sony";
FONT 'Courier New',10 TITLE "������ ����� Sony" IN Okno1

BROWSE NOEDIT TITLE "�������" ;
PARTITION 60    LEDIT     FIELDS mname:20:H="������",;
firm:15:H="�����", tipe:15:H="���", quantity:H="���������� �� ������",;
price:H="����", opinion:H="������"

HIDE WINDOW Okno1
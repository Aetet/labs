USE table_employee AGAIN

DEFINE WINDOW Okno FROM 2,2 TO 40,100 SYSTEM CLOSE FLOAT GROW MINIMIZE ZOOM
SHOW WINDOW Okno

&& ��������� ������ ������������� EDIT
EDIT FIELDS family_name:10:R:H="�������",birthday:10:R:H="����_��������",;
sex=Iif(Upper(sex)="�","�������","�������"):10:H="���";
FOR Upper(post)="���������";
FONT 'Courier',16 STYLE 'I' PARTITION 33 LEDIT TITLE "�������" IN Okno

&& ��������� ������ ������������� BROWSE
BROWSE FIELDS name_:10:R:H="���",post:10:R:H="���������";
FOR Upper(post)="���������";
STYLE 'I' PARTITION 33 REDIT TITLE "�������" IN Okno

BROWSE


 
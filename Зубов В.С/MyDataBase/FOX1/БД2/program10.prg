SET DEFA TO C:\Documents and Settings\�����\������� ����\�����\FOX1\��2

CLEAR
SELECT 1

USE main AGAIN ALIAS films
DEFINE WINDOW New FROM 1,1 TO 30,100 SYSTEM CLOSE FLOAT GROW MINIMIZE ZOOM
SHOW WINDOW New

&& ������ ������������� EDIT
EDIT FIELDS nazvanie:20:R:H="��������",regesser:10:R:H="��������";
FOR regesser="������";
FONT 'Verdana',10 STYLE 'B' PARTITION 40 LEDIT TITLE "������ �������" IN New

&& ������ ������������� BROWSE
BROWSE FIELDS nazvanie:20:R:H="��������",god:10:R:H="���",;
regesser:10:R:H="��������" FOR god=2005;
STYLE 'B' Title "������ 2005 ����" IN New

HIDE WINDOW New
BROWSE

&& ����������� 1-��� ���� (����������������)
DEFINE WINDOW Ok1 FROM 1,2 TO 10,40 TITLE "���� 1" SYSTEM;
CLOSE FLOAT GROW MINIMIZE ZOOM

&& ����������� 2-��� ���� (����������������)
DEFINE WINDOW Ok2 FROM 5,70 TO 40,140 TITLE "���� 2" SYSTEM;
CLOSE FLOAT GROW MINIMIZE ZOOM 

&& ����������� 3-e�� ���� (���������� � ���� 2)
DEFINE WINDOW Ok3 FROM 0,0 TO 20,40 TITLE "���� 3" IN Ok2 SYSTEM;
CLOSE FLOAT GROW MINIMIZE ZOOM

WAIT WINDOW '������ �������� 1-�� ���� � �������� � ����(������� �������)'
&& ��������� 1-��� ���� 
ACTIVATE WINDOW Ok1
&& ������ � ������ ����
?"Print into first window"

WAIT WINDOW '������ �������� 2-�� ���� � �������� � ����(������� �������)'
&& ��������� 2-��� ���� 
ACTIVATE WINDOW Ok2
&& ������ �� ������ ����
?"Print into second window"

WAIT WINDOW '������ �������� 3-�� ���� ������������ �� 2-�� � �������� � ����(������� �������)'
&& ��������� 3-��� ���� � ���� 2
ACTIVATE WINDOW Ok3 IN Ok2
&& ������ � ������ ����
?"Print into third window"

WAIT WINDOW '�������� ���� 1 � ���������� ������ � ����(������� �������)'
&& ������ ���� 1 ������ ��� ����� ������ (����� ���� �������)
HIDE WINDOW Ok1
ACTIVATE WINDOW Ok1 NOSHOW
&& � �������� ������� ������ � ���� 1
?"Into first window Noshow"

WAIT WINDOW '���������� ���� 1(������� �������)' 
&& ���������� ���� 1 (1-�� ������)
ACTIVATE WINDOW Ok1
MOVE WINDOW Ok1 TO 5,6

WAIT WINDOW '���������� ���� 3(������� �������)'
&& ���������� ���� 3 (2-�� ������)
ACTIVATE WINDOW Ok3
MOVE WINDOW Ok3 BY 5,5

WAIT WINDOW '�������� ������� 2-��� ����(������� �������)'
&& ������� ������� 2-��� ����
ZOOM WINDOW Ok2 NORM FROM 5,70 TO 35,150

WAIT WINDOW '������������ 3-� ����(������� �������)'
&& ������� ������� 3-��� ����(������������)
ZOOM WINDOW Ok3 MIN
ACTIVATE WINDOW Ok2

WAIT WINDOW '������� ��� ����(������� �������)'
CLEAR WINDOWS
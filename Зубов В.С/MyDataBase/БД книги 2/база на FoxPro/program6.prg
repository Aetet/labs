CLEAR
SET DEFA TO "D:\���� �� FoxPro"
SELECT 1
USE maintable AGAIN 
INDEX ON UPPER(book_name) TO name_indx

&& ��������� ����� 
key_s= UPPER("sbornik zadach po matematicheskoi fizike")
SEEK key_s
IF Found()
? book_name,copies
&&WAIT WINDOW (book_name + copies)
ELSE
? "����� ���� ���"
 WAIT WINDOW '����� ����� � ���� ������ ���'
 ENDIF
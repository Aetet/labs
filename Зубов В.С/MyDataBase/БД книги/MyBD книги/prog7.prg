CLEAR
SET DEFA TO D:\Downloads\����\MyBD

SELECT 1
USE main AGAIN ALIAS Books
INDEX ON UPPER(Publisher) TO Publ_indx

&& �������� ����� �� ����������� �������������
key_s = UPPER("����������")
SEEK key_s
IF Found()
	? Title,auth_surname,Publisher
	WAIT WINDOW Publisher+title
ELSE 
	? "����� ����� � ���� ���!"
	WAIT WINDOW '����� ����� � ���� ���!'
ENDIF
CLEAR
SET DEFA TO H:\

SELECT 1
USE main AGAIN ALIAS films
INDEX ON UPPER(cinema) TO cin_indx


key_s =UPPER ("����������")
SEEK key_s
IF Found()
	? nazvanie,regesser,cinema
	WAIT WINDOW cinema+nazvanie
ELSE 
	? "������ ������ � ���� ���!"
	WAIT WINDOW '������ ������ � ���� ���!'
ENDIF

SET DEFA TO D:\Downloads\����\MyBD

USE main AGAIN ALIAS Books
SET TEXTMERGE ON TO Report_Books.txt WINDOW SHOW
INDEX ON Author_id TO B_Auth_ind
\     ����� ��������� �������
\
SCAN FOR Auth_surname="������"
\����� <<RTRIM(Title)>>, �������� <<publisher>>
ENDSCAN
SET TEXTMERGE TO 

CLOSE DATABASES
SET PATH TO('D\���� ������\lab1\')
OPEN DATABASE data1
USE table
CLEAR
P1="���������"
P2="������ &P1"+"a:"
SCAN FOR Mname="&P1"
  ? "&P2", tipe, firm
ENDSCAN
?
?
INDEX ON Tipe TO IndTipes
SEEK "GR"
DO WHILE tipe="GR"
  ? mname, tipe, firm
  SKIP
ENDDO
?

z=Padr("GR-D290 E", Len(tipe))
SEEK z
DO WHILE tipe==z
  ? mname, tipe, firm
  SKIP
ENDDO

INDEX ON Firm TO IndFirms
SET TEXTMERGE ON
SEEK "Sony"
\
\              ������� ����������!
\
\ �� ���� �������� ���, ��� � ����� ��������
\ ���������� ���������� � <<Date()>> �� ������
\ ����� <<Firm>>:
\
SCAN FOR FIRM="Sony"
\ ������������: <<mname>>
\ ������:            <<tipe>>
\ ����:                <<price>>
\
ENDSCAN

&&USE table
&&DO WHILE .Not.EOF()
&&  ACCEPT "������� ����� � ������"+Firm+Tipe TO S
&&  REPLACE Opinion WITH S ADDITIVE
&&  SKIP
&&ENDDO

BROWSE FIELDS mname :H='������������', tipe :H='���', firm :H='�����', opinion :H='������' 

SET DEFA TO H:\FOX1\��1

USE main AGAIN ALIAS toys
SET TEXTMERGE ON TO Report_toys.txt WINDOW SHOW
INDEX ON izdelie_kl TO B_rege_ind
\     ������� �����
\
SCAN FOR izdelie="����"
\����� <<RTRIM(firm_name)>>, ��� <<tip>>
ENDSCAN
SET TEXTMERGE TO 
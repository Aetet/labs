SET DEFA TO H:\FOX1\��1
&& �������� ������������ FOX-����

DECLARE MyMenu[5]
MyMenu[1] = " ������� �� ���������� ����� "
MyMenu[2] = " ������� ���������� ����� "
MyMenu[3] = " ������� ��� ����� "
MyMenu[4] = "\-"
MyMenu[5] = " �\<���� "

@ 0,0 MENU MyMenu,5 TITLE "������������ ����" 

DO WHILE .T.  && �.�. ���� �� ������ "�����"
	READ MENU TO n SAVE
	DO CASE
		CASE n=1
			SELECT a.izdelie AS "�������", a.tip AS "���",b.firm_name AS "�����";
			FROM main a, firm b WHERE ((a.izdelie_kl=b.izdelie_kl) AND NOT (b.firm_adr = "�.������"));
			ORDER BY a.izdelie 
		CASE n=2
			SELECT a.izdelie  AS "�������", a.tip AS "���", b.firm_name AS "�����";
			FROM main a, firm b WHERE ((a.izdelie_kl=b.izdelie_kl) AND (b.firm_adr = "�.������"));
			ORDER BY a.izdelie
		CASE n=3
			SELECT a.izdelie AS "�������",a.tip AS "���",b.firm_name AS "�����";
			FROM main a, firm b WHERE a.izdelie_kl=b.izdelie_kl;
			ORDER BY a.izdelie
		CASE n=5
			EXIT
	ENDCASE
ENDDO

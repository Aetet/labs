  CLEAR
  SET DEFA TO "D:\���� �� FoxPro"
  && ������� ����� �������� � 2000 �� 2007 ����
  SELECT book_name ,imprintdat  ;
  from maintable ;
  where imprintdat BETWEEN 2000 AND 2007 ORDER BY imprintdat
  &&AS"��� �������"AS "�������� �����"

  && ������� ��� ������������, � ����������� �� �������.
  SELECT writingtable.book_cod,writingtable.name1,writingtable.translat,genretable.genre,;
  authortable.author;
  FROM  writingtable,genretable,authortable;
  WHERE writingtable.genre_cod=genretable.genre_cod ;
  AND authortable.autor_cod=writingtable.author_cod;
  GROUP BY authortable.author;
  ORDER BY writingtable.book_cod ASC

  && ���������� ������� HAVING,������� ���������� �  ���������� �����������.
  SELECT publishingtable.publishing,imprinttowntable.town;
  FROM  maintable,publishingtable,imprinttowntable;
  WHERE maintable.town_cod=imprinttowntable.town_cod ;
  AND maintable.publ_cod=publishingtable.publ_cod;
  GROUP BY publishingtable.publishing;
  HAVING imprinttowntable.town="������"

  && ���������� ������� DISTINCT
  SELECT DISTINCT maintable.book_name From maintable,placetable;
  WHERE maintable.place_cod=placetable.place_cod;
  ORDER BY maintable.book_name DESC

  && �������� ����� ������� � �������� ��
  CREATE TABLE NewTable(book_name C(40),publishing C(20),town C(20),dat n)
  INSERT INTO NewTable(book_name,publishing,town,dat);
  VALUES ("�������������� ������","�����","������",1989)
  INSERT INTO NewTable(book_name,publishing,town,dat);
  VALUES ("������ �����������","���","������",2001)
  INSERT INTO NewTable(book_name,publishing,town,dat);
  VALUES ("������������� ����","���","������",1999)
  INSERT INTO NewTable(book_name,publishing,town,dat);
  VALUES ("�������� � ��������� ��������","���","������",2005)
  CLOSE DATABASES
  Select* From NewTable 

    clear
    ? "������� �������� ������� ������� �� �� ������ ����������"
    accept"a,b,c,d,e,f,g - " to tb
    use maintable IN a again
    use authortable IN b again
    use writingtable IN c again
    use publishingtable IN d again
    use genretable IN e again
    use imprinttowntable IN f again
    use placetable IN g again
    do case
    case tb == "a"
    select a
    case tb == "b" 
    select b
    case tb == "c"
    select c
    case tb == "d"
    select b
    case tb == "e"
    select e
    case tb == "f"
    select f
    case tb == "g"
    select g 
    otherwise
    ?"������������ ���� �������"
    endcase
    list all
    accept "������ �������� ����� � ������� �������� �������� ���������� : " to naz
    ?"���������� � �����:"
   select a
   LOCATE for book_name = naz
   ?"�������� �����: ",book_name
   select c
   LOCATE for book_cod == a.mbook_cod  
   x=author_cod
   select b
   LOCATE for autor_cod == x
   ?"������ :", author
   select d
   LOCATE for publ_cod == a.publ_cod
   ?"������������:" ,publishing
   select a
   LOCATE for book_name = naz
   ?"���� �������:",imprintdat
   select f
   LOCATE for town_cod == a.town_cod
   ?"����� ��� ������:",town
   select e
   LOCATE for genre_cod == a.genre_cod
   ?"����:",genre
   select a
   LOCATE for book_name = naz
   ?"���� �����:",numtoms
   ?"����� ����:",tom
   ?"���������� ����� ����:",copies
   select g 
    LOCATE for place_cod == a.place_cod
   ?"��� ��������:"
   ?"����� �������:",room
   ?"����� �����:"  ,bookcase
   ?"����� �����:"  ,bookshelf





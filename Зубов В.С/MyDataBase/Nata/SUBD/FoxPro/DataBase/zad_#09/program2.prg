&& ��������� ���������� ����
SET DATE TO BRITISH

&& �������� �.�. ������� � ������ �������, ���� ��������, ������, ��������
CREATE DBF table_job(jobs C(10), date_ D, project_ C(10), pay N(10,0))

&& ������� ������ � ��������� �.�.
INSERT INTO table_job(jobs,date_,project_,pay) VALUES("������",{^1960/12/01},;
"�����",30000)
INSERT INTO table_job(jobs,date_,project_,pay) VALUES("������",{^1966/11/02},;
"���",55000)
INSERT INTO table_job(jobs,date_,project_,pay) VALUES("�������",{^1969/02/17},;
"���",50000)
INSERT INTO table_job(jobs,date_,project_,pay) VALUES("�����",{^1971/08/29},;
"�����",40000)
INSERT INTO table_job(jobs,date_,project_,pay) VALUES("��������",{^1955/01/09},;
"���",60000)
INSERT INTO table_job(jobs,date_,project_,pay) VALUES("�����",{^1964/04/26},;
"�����",45000)
CLOSE DATABASES
&& ������� �������
SELECT * FROM table_job ORDER BY project_,jobs
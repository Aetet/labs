Set DEFA TO c:\ALANsProgs\work\FoxPro\MyDB\
select 1
&& Path="c:\ALANsProgs\work\FoxPro\MyDB\"
use table1 alias main
INDEX ON number TO main_indx
SELECT 2
USE table3 alias car_param
&&INDEX ON number TO car_ind
SET RELATION TO number INTO main
list main.title
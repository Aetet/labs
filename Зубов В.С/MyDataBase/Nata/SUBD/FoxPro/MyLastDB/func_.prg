&& ���� � ���������
&& ������� F_Trace
&&	������� ������: A - ������� NxN
&&	�������� ������: T - �������, ������ A �����������������
FUNCTION F_Trace
 PARAM A,N,I,J
 	DECLARE A[N,N],T[N,N]
	FOR I=1 TO N
		FOR J=1 TO N
			T[I,J]=A[J,I]
		ENDFOR
	ENDFOR
	FOR I=1 TO N
		FOR J=1 TO N
			A[I,J]=T[I,J]
		ENDFOR
	ENDFOR
RETURN T
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define pi 3.14159265
#define e exp(1.0)

// ������� ����� �������
double X[200][200];
// ������ �������� ����� ��� ������� eps
double X_old[200][200];
// ��������� �������
double X0[200], Y0[200], X1[200], Y1[200];

double eps;

int n;		/* ����������� ������� n*n*/

double x_0(int i)
{
	double h = i+1;
	h/= (n+1);
	return sin(pi * h);
}


double x_1(int i)
{
	double h = i+1;
	h /= (n+1);
	double a = pow(e, -h);
	return sin(pi * h)*a;
}

double y_0(int i)
{
	return 0;
}

double y_1(int i)
{
	return 0;
}


// ���������� ����� �� ������ ������-�������
// � ���� i, j
double Gauss_Zeid(int i, int j)
{
	double sum = 0;
	if (i != 0)
		sum += X[i-1][j];
	else
		sum += X0[j];

	if (i != n-1)
		sum += X[i+1][j];
	else
		sum += X1[j];


	if (j != 0)
		sum += X[i][j-1];
	else
		sum += Y0[i];

	if (j != n-1)
		sum += X[i][j+1];
	else
		sum += Y1[i];

	sum /= 4;
	return sum;
}

// ������������� ��������� �������� X � �_old
void init_x()
{
	int i = 0, j = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			X[i][j] = 0;
			X_old[i][j] = 0;
			j++;
		}
		X0[i] = x_0(i);
		X1[i] = x_1(i);
		Y0[i] = y_0(i);
		Y1[i] = y_1(i);
		i++;
	}
}

// �������� ���������� �������
// ����������� �������� - ����� ������ � ������� ��� �������� ������������� ������� |x-x_old| <= eps
// � ��������� ������ ������������ �������� -1
bool checkEps()
{
	int i = 0, j = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			if (fabs(X[i][j] - X_old[i][j]) > eps)
				return false;
			j++;
		}
		i++;
	}
	return true;
}

// ����������� X � X_old
void copy_X()
{
	int i = 0, j = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			X_old[i][j] = X[i][j];
			j++;
		}
		i++;
	}
}


// ������� �����
double getSum()
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			sum += X[i][j];
	}
	return sum;
}


int main(int argc, char* argv[])
{
	time_t end;
	double workTime;
	int i = 0, j = 0;
	n = 200;
	eps = 0.0005;
	
	init_x();

	double sum = 0;
	time_t start=clock();
	do{
		// ����������� X
		copy_X();
		int from=0;
		int to=n;
		// ������� ��� ������� �����
		// red
		for (i = from; i < to; i += 2)
			for (j = 0; j < n; j += 2)
				X[i][j] = Gauss_Zeid(i, j);

		for (i = from+1; i < to; i +=2)
			for (j = 1; j < n; j += 2)
				X[i][j] = Gauss_Zeid(i, j);

		// ������� ��� ������ �����
		// black
		for (i = from; i < to; i += 2)
			for (j = 1; j < n; j += 2)
				X[i][j] = Gauss_Zeid(i, j);

		for (i = from+1; i < to; i += 2)
			for (j = 0; j < n; j += 2)
				X[i][j] = Gauss_Zeid(i, j);
	}while(!checkEps());

	sum = getSum();
	printf("Summ = %.5f\n", sum);
	
	end = clock();
	workTime = end-start;
	workTime /= CLOCKS_PER_SEC;
	printf("Calculation takes: %.5f sec\n", workTime);
	return 0;
}


#include <stdio.h>
#include <math.h>

int det(int a[][3], int n);

int main(void)
{
	int a[][3] = {
		{0, 2, 3, '\0',},
		{4, 5, 6, '\0',},
		{7, 8, 9, '\0',},
		{'\0',},
	};
	printf("%d\n", det(a, 3));
	return 0;
}

int det(int a[][], int n)
{
	int sum = 0;
	if (n == 1)
		return a[0][0];
	else
	{
		int b[n-1][n-1];
		for (int i = 0; i < n-1; i++)
			for (int j = 0; j < n-1; j++)
				
		for (int j = 0; j < n; j++)
			sum += pow(-1, j) * a[0][j] * det();
		return sum;
	}
}

void 

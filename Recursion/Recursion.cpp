
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void build(int currl, int* B, int* A, int le)
{
	int j = -2 + 2 * currl;
	int j1 = j + 2 * currl;
	if (j == 0)
	{
		B[j] = fmax(B[j1], B[j1-1]);
		return;
	}

	if (j1 >= le)
	{
		for (int i = currl - 1; i >= 0; i--)
		{
			B[le - i - 1] = A[currl - i - 1];
		}
	}
	else
	{
		for (int k = j; k > j - currl; k--)
		{
			B[k] = fmax(B[j1], B[j1 - 1]);
			j1 -= 2;
		}
	}
	
	build(currl / 2, B, A, le);
	return;
	
}


int main()
{
	int n;
	int currl;
	scanf("%d", &n);
	int k = pow(2, n), le = k * 2 - 1;
	int* A = (int*)malloc(sizeof(int) * k);
	int* B = (int*)malloc(sizeof(int) * le);
	srand(time(NULL));
	for (int i = 0; i < k; i++)
	{
		A[i] = (double)rand() / RAND_MAX * 89 + 10;
		printf("%d ", A[i]);
	}
	printf("\n");
	
	build(k, B, A, le);
	for (int i = 0; i < le; i++)
	{
		printf("%d ", B[i]);
	}
	free(A);
	free(B);
}

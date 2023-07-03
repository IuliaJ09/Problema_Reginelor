#include <stdio.h>
#include <stdlib.h>
#include <cmath>
int st[100], n, k;
int validare(int niv)
{
	int i;
	for (i = 1; i < niv; i++)
		if ((st[i] == st[niv]) || abs(st[niv] - st[i]) == (niv - i))
			return 0;

	return 1;
}
void afisare(int niv)
{
	int i;
	for (i = 1; i <= niv; i++)
		printf("(%d,%d) ", st[i], i);
	printf("\n");
}
int solutie(int niv)
{
	if (niv == k)
		return 1;
	else
		return 0;
}
void bk(int niv)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		st[niv] = i;
		if (validare(niv) == 1)
			if (solutie(niv) == 1)
				afisare(niv);
			else
				bk(niv + 1);
	}
}
int main()
{
	printf("n=");
	scanf("%d", &n);
	printf("k=");
	scanf("%d", &k);
	bk(1);
	return 0;
}
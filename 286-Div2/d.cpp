#include <stdio.h>

int func(int a)
{
	a += 1;
	a += 1;
	a += 1;
	a += 1;
	a += 1;

	return a;
}

int func(int a)
{
	a += 5;
	return a;
}

int main()
{
	int n;
	scanf("%d",&n);

	printf("%d\n",func(n));

	return 0;
}

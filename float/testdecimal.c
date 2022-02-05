#include <stdio.h>

int main()
{
	float num;
	int sindec;
	float rest;

	num = 15.99;
	sindec = (int)num;
	rest = num - sindec;

	printf("%f %i %f\n",num,sindec, rest);
	
	return 0;
}
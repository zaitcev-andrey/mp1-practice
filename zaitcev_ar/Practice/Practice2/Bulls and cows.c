#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10
void main ()
{
	int n;
	srand((unsigned int)time(0));
	do
	{
		printf("Vvedite kolichestvo tcifr v zagadannom chisle (do 10) \n");
		scanf("%d", &n);
	}while ((n <= 0)||(n > N));
}
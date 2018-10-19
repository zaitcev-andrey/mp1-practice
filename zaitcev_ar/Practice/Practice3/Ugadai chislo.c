#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main ()
{
	int a, b, c, d;
	char f;
	c = 0;
	srand ((unsigned int)time(0));
	printf ("Vevedite 1 ili 2 dlya vibora rejima \n");
	scanf("%d", &a);

	if ((a != 1) && (a != 2))
	{
		printf ("Neverni vvod");
	}
	if (a == 1)
	{
		b = rand() % 1001;
		while (1)
		{
			printf ("Vvedite chislo \n");
			scanf ("%d", &d);
			c++;
			if (d == b)
			{
				break;
			}
			if (d > b)
			{
				printf ("Zagadannoe chislo bolshe \n");
			}
			if (d < b)
			{
				printf ("Zagadannoe chislo menshe \n");
			}
		}
		printf ("Vi ugadali chislo \n kolichestvo hodov = %d", c);
		return;

	}
	if (a == 2)
	{
		printf ("Zagadai chislo.");
		b = rand() % 1001;
	    while (1)
		{
			int b2;
			c++;
			printf ("Kak programma reagiruet na chislo b(ot 0 do 1000) %d \n Vvedite znak otnosheniya( >, <, =) \n", b);
			scanf ("%c", &f);
			switch (f)
			{
			case '=':
				break;
			case '>':
				while (b > b2)
				{
					b2 = rand() % 1001; 
				}
				b = b2;
			case '<':
				while (b < b2)
				{
					b2 = rand() % 1001;
				}
				b = b2;
			default: printf ("Neverni vvod.");
			}			
		}
		printf ("Vashe chislo %d \n kolichestvo hodov = %d", b, c);  
		return;
	}
}
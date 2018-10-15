#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main ()
{
	int a, b, c, d;
	char f;
	srand ((unsigned int)time(0));
	printf ("Vevedite 1 or 2 for dibora rejima \n");
	scanf("%d", a);

	if ((a != 1) || (a != 2))
	{
		printf ("Neverni vvod");
		return;
	}
	if (a == 1)
	{
		b = rand() % 1001;
		while (1)
		{
			printf ("Vvedite chislo /n");
			scanf ("%d", &d);
			c++;
			if (d == b)
			{
				break;
			}
			if (d > b)
			{
				printf ("Zagadannoe chislo bolshe");
			}
			if (d < b)
			{
				printf ("Zagadannoe chislo menshe");
			}
		}
		printf ("Vi ugadali chislo");
		return;

	}
	if (a == 2)
	{
		
		printf ("Zagadai chislo");
		b = rand() % 1001
	    while (1)
		{
			int b2;
			c++;
			printf ("Kak programma reagiruet na chislo b(ot 0 do 1000) %d \n Vvedite znak otnosheniya( >, <, =)", b);
			scanf ("%c",f);
			switch (f)
			{
			case '=' : 
			}
			
		}
	}

}
#include <math.h>
#include <stdio.h>

void main()
{
	int o1, o2, r1, r2;
	printf("Vvedite o1, o2, r1, r2 \n");
	scanf("%d %d %d %d", &o1, &o2, &r1, &r2);
	if ((abs(o2 - o1) == abs(r2 - r1)) || (abs(o2 - o1) == abs(r2 + r1)))
	{
		printf("one touch point");
		return;
	}
	if ((abs(o2 - o1) < abs(r2 - r1)) || (abs(o2 - o1) > abs(r2 + r1)))
	{
		printf("do not intersect");
		return;
	}
	if (abs(r2 - r1) < abs(o2 - o1) < abs(r2 + r1))
	{
		printf("intersect");
	}	
}
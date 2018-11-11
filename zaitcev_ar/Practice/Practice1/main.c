#include <stdio.h>
#include <math.h>
void main()
{
	float h, w, d, dcp, dvp, der, m1, m2, m3, m4, m5, m;
    float tdcp, tdvp, tder;   //Tolshina dcp,dvp,dereva

	tdcp = 0.015;
	tdvp = 0.005;
	tder = 0.01;

	printf(" Vvedite plotnost dcp(700-800), dvp(800-900), der(670-770) shkafa \n ");
	scanf("%f %f %f", &dcp, &dvp, &der);

    printf(" Vvedite visotu(1.8m-2.2m), shirinu(0.8m-1.2m) i glubinu (0.5m-0.9m) shkafa \n ");
    scanf("%f %f %f",&h, &w, &d);

    if((h < 1.8) || (h > 2.2))
	{
		printf("Error,nekorrektni vvod");
		return;
	}
	if((w < 0.8) || (w > 1.2)) 
	{
		printf("Error,nekorrektni vvod"); 
		return;
	} 
	if((d < 0.5) || (d > 0.9))
	{
		printf("Error,nekorrektni vvod");
		return;
	} 

	m1 = (h * w * tdvp * dvp);                                                       //Zadnia stenka
	m2 = (2 * h * d * tdcp * dcp);                                                   //Bokovini
	m3 = (2 * w * d * tdcp * dcp);                                                   //Verh i niz
	m4 = (h * w * tder * der);                                                       //2 dveri
	m5 = ((h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005) * dcp);    //Polki

	m = m1 + m2 + m3 + m4 + m5;

    printf(" Macca shkafa(kg)=%f ", m);
    return;
}
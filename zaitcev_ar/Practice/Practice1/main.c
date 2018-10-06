#include <stdio.h>
#include <math.h>
void main()
{
	float h, w, d, dcp, dvp, der, m1, m2, m3, m4, m5, m;
    float tdcp, tdvp, tder;   //Tolshina dcp,dvp,dereva
	float p;                  //Polki

	dcp=750;
	dvp=850;
	der=720;
	tdcp=1,5;
	tdvp=0,5;
	tder=1;

printf(" Vvedite visotu(180cm-220cm), shirinu(80cm-120cm) i glubinu (50cm-90cm) shkafa");
scanf("%f %f %f",&h, &w, &d);

    if((h<180)||(h>220))
	{
		printf("Error,nekorrektni vvod");
		return;
	}
	if((w<80)||(w>120)) 
	{
		printf("Error,nekorrektni vvod"); 
		return;
	} 
	if((d<50)||(d>90))
	{
		printf("Error,nekorrektni vvod");
		return;
	} 

        p=(h/40); 

	m1 = (h * w * tdvp * dvp) / 1000000;        //Zadnia stenka
	m2 = (2 * h * d * tdcp * dcp) / 1000000;    //Bokovini
	m3 = (2 * w * d * tdcp * dcp) / 1000000;    //Verh i niz
	m4 = (h * w * tder * der) / 1000000;        //2 dveri
	m5 = (p * (w-3) * tdcp * dcp) / 1000000;    //Polki

	m = m1 + m2 + m3 + m4 + m5;

printf("Macca shkafa(kg)=%f",m);
return;
}
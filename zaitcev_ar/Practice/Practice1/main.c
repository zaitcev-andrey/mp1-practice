#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	float h, w, d, dcp, dvp, der, m1, m2, m3, m4, m5, m;
    float tdcp, tdvp, tder;   //Толщина дсп,двп,дерева соответсвенно
	float p;                  //Количество полок в шкафу

	dcp=750;
	dvp=850;
	der=720;
	tdcp=1,5;
	tdvp=0,5;
	tder=1;

setlocale (LC_CTYPE,"russian");
printf(" Введите высоту(180см-220см), ширину(80см-120см) и глубину (50см-90см) шкафа");
scanf("%f %f %f",&h, &w, &d);

    if((h<180)||(h>220))
	{
		printf("Ошибка,некорректный ввод");
		return;
	}
	if((w<80)||(w>120))
	{
		printf("Ошибка,некорректный ввод");
		return;
	}
	if((d<50)||(d>90))
	{
		printf("Ошибка,некорректный ввод");
		return;
	} 

p=(h/40); 

	m1 = (h * w * tdvp * dvp) / 1000000;        //Задняя стенка
	m2 = (2 * h * d * tdcp * dcp) / 1000000;    //Боковины
	m3 = (2 * w * d * tdcp * dcp) / 1000000;    //Верх и низ
	m4 = (h * w * tder * der) / 1000000;        //2 двери
	m5 = (p * (w-3) * tdcp * dcp) / 1000000;    //Полки

	m = m1 + m2 + m3 + m4 + m5;

printf("Масса шкафа(кг)=%f",m);
return;
}
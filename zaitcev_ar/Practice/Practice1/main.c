#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	float h, w, d, dcp, dvp, der, m1, m2, m3, m4, m5, m;
    float tdcp, tdvp, tder;   //������� ���,���,������ �������������
	float p;                  //���������� ����� � �����

	dcp=750;
	dvp=850;
	der=720;
	tdcp=1,5;
	tdvp=0,5;
	tder=1;

setlocale (LC_CTYPE,"russian");
printf(" ������� ������(180��-220��), ������(80��-120��) � ������� (50��-90��) �����");
scanf("%f %f %f",&h, &w, &d);

    if((h<180)||(h>220))
	{
		printf("������,������������ ����");
		return;
	}
	if((w<80)||(w>120))
	{
		printf("������,������������ ����");
		return;
	}
	if((d<50)||(d>90))
	{
		printf("������,������������ ����");
		return;
	} 

p=(h/40); 

	m1 = (h * w * tdvp * dvp) / 1000000;        //������ ������
	m2 = (2 * h * d * tdcp * dcp) / 1000000;    //��������
	m3 = (2 * w * d * tdcp * dcp) / 1000000;    //���� � ���
	m4 = (h * w * tder * der) / 1000000;        //2 �����
	m5 = (p * (w-3) * tdcp * dcp) / 1000000;    //�����

	m = m1 + m2 + m3 + m4 + m5;

printf("����� �����(��)=%f",m);
return;
}
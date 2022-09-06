#include <stdio.h>
#include <math.h>
int main()
{
	printf("Hello!");
	int n1 = 2;
	int res = n1 * 3;
	// % - остаток
	n1 = res % 10;
	res /= 10;

	//______________________
	unsigned int un1 = 7U;
	long long int LL1 = 1L;
	short s1;
	char c1 = 'a';
	LL1 = n1 * LL1;
	//______________________

	float f1 = 1.5e-9;
	double d1 = 1.4e-9;
	d1 = 1.0 / n1; // для того чтобы получит дробное значение при делении целочисленних значений, одно из целых надо представить через n.0
	d1 = 1 / (double)n1; // или так
	d1 = sin(d1); // cos, ta, log, log10, asin, atan, acos, exp(x), abs, fabs



	printf(" %d", res);
	getchar();
	return 0;
}

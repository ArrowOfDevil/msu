#include <stdio.h>
#include <math.h>
#include <windows.h>
int main() {
  SetConsoleOutputCP(CP_UTF8);
  int count = 0;
  double S, x, a, b, p, avg, a_n, sum = 0;
  double s1, s2, s3, i;
  scanf("%lf %lf %lf", &x, &a, &b);
  s1 = sin(abs(x * x + a * x + b));
  s2 = abs(x * x + a * x + b) + 1e-5;
  s3 = cos(abs(x * x + a * x + b)) + x;
  S = s1 * s3 / s2;
  printf("%lf \n", S);
  printf("task 2\nВведите сумму покупки и нажмите <Enter>\n");
  scanf("%lf", &p);
  if (p >= 1000) {
    printf("Вам предоставляется скидка 10% \n");
    i = p - 0.1 * p;
    printf("Сумма покупки с учетом скидки: %lf руб.", i);
  } else {
    printf("Скидки нет, сосите бибу \nК оплате %lf руб.\n", p);
  }
  printf("task 3\nВведите последовательность заканчивающуюся 0\n");
  scanf("%lf", &a_n);
 // getchar();
  while (a_n != 0) {
    count += 1;
    sum += a_n;
    avg = sum / count;
    printf("%d Сумма: %lf Сред, арифметическое: %lf \n", count, sum, avg);
    scanf("%lf", &a_n);
//    getchar();
  }
  getchar();
  return 0;
}


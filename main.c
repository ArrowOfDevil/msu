#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
int main() {
  SetConsoleOutputCP(CP_UTF8);
  //перечисляем переменные из условий
  double x, y, z;
  int n, count = 0, ans;
  //перечисляем промежуточные значения
  double a1, a2, a3;
  printf("Task 1\n");
  printf("Введите значения x и y\n");
  scanf("%lf%lf", &x, &y);
  a1 = sqrt(9 + sin((x + y) * (x + y)));
  a2 = pow(sin((x + y) * (x + y)), 2) + y * y + 2 * 1e-5;
  a3 = (-exp((x + y) * (x + y))) + 1. / 3;
  z = a1 / a2 + a3;
  printf("z = %lf", z);
  printf("\nTask 2\n");
  printf("Введите число\n");
  scanf("%d", &n);
  if (n / 3 * 3 != n) printf("Число %d нацело на 3 не делится\n", n);
  else printf("Число %d делится на 3\n", n);
  printf("Task 3\n");
  for (int a = 1, b = 2, i = 0; i < 10; ++i) {
    a = rand() % 10;
    b = (rand() +1) % 10;
    printf("%d) %dx%d=", i + 1, a, b);
    scanf("%d", &ans);
    ans == a * b ? ++count : printf("Опа!! Ошибочки! Ответ: %d\n", a * b);
  }
  printf("Верных ответов %d/10\n", count);
  if (count == 10) {
    printf("Отл");
  } else {
    if (count < 10 && count > 7) {
      printf("Хор");
    } else {
      if (count < 8 && count > 5) printf("Удов");
      else printf("Неуд");
    }
  }
  return 0;
}


//zabiralova 108 task 2 var 7
#include <stdio.h>
#include <math.h>
#include <windows.h>
int main() {
  //  вывести сумму двух целых введенных с клавиатуры чисел
  int a, b, c, d;
  printf("enter a & b\n");
  scanf("%d%d", &a, &b);
  printf("a+b=%d\n", a + b);
  // вывести частное двух целых чисел введенных с клавиатуры
  printf("enter c & d\n");
  scanf("%d%d", &c, &d);
  printf("c/d=%lf", c * 1. / d);
  printf("c/d=%lf", (c + 0.0) / d);
  getchar();
  return 0;
}

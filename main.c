//zabiralova 108 task 3 var 7
#include <stdio.h>
#include <math.h>
#include <windows.h>
int summa(int x, int y);
int multip(int x, int y);
int max_plus_min(int w, int x, int y, int z);
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("max + min = %d", max_plus_min(a, b, c, d));
  printf("\na + b = %d", summa(a, b));
  printf("\nc + d = %d", summa(c, d));
  printf("\nb * b = %d", multip(b, b));
  return 0;
}
int summa(int x, int y) {
  return (x + y);
}
int multip(int x, int y) {
  return (x * y);
}
int max_plus_min(int w, int x, int y, int z) {
  return (max(max(w, x), max(y, z)) + min(min(w, x), min(y, z)));
}

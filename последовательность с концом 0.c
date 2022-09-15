#include <stdio.h>
#include <math.h>
#include <windows.h> //библиотека для руссификации 
int main() {
  SetConsoleOutputCP(CP_UTF8); //руссификация 
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


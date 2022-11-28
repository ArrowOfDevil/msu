#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  FILE *f1, *f2, *f3, *f4;
  char fst[] = "C:\\Users\\Dilya\\CLionProjects\\untitled8\\first.txt";
  char snd[] = "C:\\Users\\Dilya\\CLionProjects\\untitled8\\second.txt";
  char trd[] = "C:\\Users\\Dilya\\CLionProjects\\untitled8\\third.txt";
  char ex2[] = "C:\\Users\\Dilya\\CLionProjects\\untitled8\\ex2.txt";
  const int N = 512;// максимальный размер строки в файле
  char ArrChar1[N];
  char ArrChar2[N];

  f1 = fopen(fst, "rt");
  f2 = fopen(snd, "rt");
  f3 = fopen(trd, "wt");
  f4 = fopen(ex2, "at"); //так как неизвестно существует файл или нет, то сначала создадим его с помощью "а"
  fclose(f4);

  if (!f1) return printf("error opening file1"), -1; // это законно, но правильно ли с точки зрения код стайла (?)
  if (!f2) return printf("error opening file2"), -1;
  if (!f3) return printf("error opening file3"), -1;
  if (!f4) return printf("error opening file4"), -1;

  fgets(ArrChar1, N, f1);
  fgets(ArrChar2, N, f2);

  int i = 0, j = 0;

  while ((i < N) && (j < N)) {
    if (ArrChar1[i] != 0) fputc(ArrChar1[i], f3), ++i;
    if (ArrChar2[j] != 0) fputc(ArrChar2[j], f3), ++j;
    if (ArrChar1[i] == 0 && ArrChar2[j] == 0) break;
  }

  printf("работа с файлом\n");
  int c;
  char str[N];
  printf("1.Записать текст в файл. \n"
         "2.Дописать текст к концу файла. \n"
         "3.Просмотреть файл. \n"
         "4.Удалить файл. \n"
         "0.Закончить работу. \n");
  scanf("%d", &c);
  getchar();
  while (c != 0) {
    switch (c) {
      case 0: break;
      case 1:f4 = fopen(ex2, "wt");

        scanf("%s", str);
        fputs(str, f4);
        fputs("\n", f4);

        fclose(f4);
        break;
      case 2:f4 = fopen(ex2, "at");

        scanf("%s", str);
        fputs(str, f4);
        fputs("\n", f4);

        fclose(f4);
        break;
      case 3:f4 = fopen(ex2, "rt");
        while (
            fgets(str, sizeof(str), f4) != nullptr)
          fputs(str, stdout);

        break;
      case 4:remove(ex2);
        break;
      default:printf("неверная команда");
    }
    printf("1.Записать текст в файл.\n"
           "2.Дописать текст к концу файла.\n"
           "3.Просмотреть файл.\n"
           "4.Удалить файл.\n"
           "0.Закончить работу.\n");
    scanf("%d", &c);
  }
  printf("Работа завершена, спасибо)");

  fclose(f1);
  fclose(f2);
  fclose(f3);

  return 0;
}

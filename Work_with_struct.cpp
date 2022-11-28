//task 7 zabiralova var7 108
// #include <locale.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>//русификация для CLion

//Описание структуры
struct Predmety {
  int code;
  char name[150];
  char teacher_last_n[100];
};
//----------------------------------------
//Ввод структуры
void Enter(Predmety *pr) {
  SetConsoleOutputCP(CP_UTF8);
  printf("Код предмета:\n");
  scanf("%d", &(pr->code));
  getchar();
  printf("Название предмета:\n");
  gets(pr->name);
  printf("Фамилия преподавателя:\n");
  gets((pr->teacher_last_n));
}
//Вывод структуры
void Print(Predmety *pr) {
  printf("%1d %12s %15s\n", pr->code, pr->name, pr->teacher_last_n);
}
//----------------------------------------
//Поиски по разным признакам
void Scan_Code(Predmety TT[], int n, int search) {
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if ((TT[i].code) == search) {
      k++;
      Print(&TT[i]);
    }
  }
  printf("Всего найдено %d предметов c кодом %d\n", k, search);
}
void Scan_Name(Predmety TT[], int n, char search[]) {
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (strcmp(TT[i].name, search) == 0) {
      k++;
      Print(&TT[i]);
    }
  }
  printf("Всего найдено %d предметов c названием %s\n", k, search);
}
void Scan_Tchr_Last_N(Predmety TT[], int n, char search[]) {
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (strcmp(TT[i].teacher_last_n, search) == 0) {
      k++;
      Print(&TT[i]);
    }
  }
  printf("Всего найдено %d предметов c названием %s\n", k, search);
}
//----------------------------------------
int main() {
  SetConsoleOutputCP(CP_UTF8); //русификация для CLion
//  setlocale(LC_ALL, "RUS");
  FILE *ff;
  char ff_path[] = "C:\\Users\\Dilya\\CLionProjects\\untitled2\\Predmety.txt";
  int n = 0;
  Predmety TT[30]; //Массив структур

  ff = fopen(ff_path, "rt");
  if (!ff) return printf("Error opening Predmety.txt"), -1;
  //Заполнение массива структуры данными из файла
  while (fscanf(ff, "%d", &(TT[n].code)) == 1) {
    fscanf(ff, "%s", &(TT[n].name));
    fscanf(ff, "%s", &(TT[n].teacher_last_n));
    ++n;
  }
  fclose(ff);

  printf("Работа с файлом\n");
  int k = 1;//k для работы с меню
  while (k != 0) {
    char search_c[150];
    int search_i;
    printf("1. Ввести данные\n"
           "2. Вывод всех данные\n"
           "3. Поиск по коду\n"
           "4. Поиск по названию\n"
           "5. Поиск по фамилии преподавателя\n"
           "6. Очистить файл.\n"
           "0. Выход\n");
    scanf_s("%d", &k);
    getchar();
    switch (k) {
      case 1: {//Заполнение массива структур из консоли и запись введенных данных в файл
        Enter(&TT[n]);
        ff = fopen(ff_path, "a+t");
        fprintf(ff, "\n%d", TT[n].code);
        fprintf(ff, " %s", TT[n].name);
        fprintf(ff, " %s", TT[n].teacher_last_n);
        fclose(ff);
        ++n;
        break;
      }
      case 2: {//Вывод массива структур (просмотр)
        for (int i = 0; i < n; ++i) Print(&TT[i]);
        break;
      }

      case 3: {//Поиски по разным параметрам
        ff = fopen(ff_path, "at");
        printf("Введите код предмета:\n");
        scanf("%d", &search_i);
        getchar();
        Scan_Code(TT, n, search_i);
        fclose(ff);
        break;
      }
      case 4: {
        printf("Введите название предмета:\n");
        gets(search_c);
        Scan_Name(TT, n, search_c);
        break;
      }
      case 5: {
        printf("Введите фамилия преподавателя:\n");
        gets(search_c);
        Scan_Tchr_Last_N(TT, n, search_c);
        break;
      }

      case 6: {
        ff = fopen(ff_path, "wt");
        fclose(ff);
        printf("Файл очищен\n");
      }
      case 0: {//Выход из меню + копирование новых структур в файл
        printf("Работа завершена, спасибо)");
        break;
      }
      default: printf("Команда не распознана\n");
    }
  }
  return 0;
}

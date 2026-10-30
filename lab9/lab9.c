#include <locale.h>
#include <stdio.h>

#define ROW 9
#define COL 9

int prac1()
{
    int row, col;

    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL;col++)
            printf("%5d", col * row);
        printf("\n");
    }

    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= row;col++)
            printf("%5d", col * row);
        printf("\n");
    }

    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
        {
            printf("%d + %d = %-2d   ", row, col, row + col);
        }
        printf("\n");
    }
    return 0;
}

int prac2()
{
    char choice;

    do
    {
        printf("Введите число: ");

        int c, cifra;
        scanf("%d", &c);

        int chet = 0;

        while (c != 0)
        {
            cifra = c % 10;
            c = c / 10;

            if (cifra % 2 == 0)
            {
                chet += 1;
            }

        }

        printf("Количество четных цифр: %d\n", chet);

        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &choice);
        printf("\n");

    } while (choice != 'n' && choice != 'N');
}

int prac3(char symb, int d1, int d2, double alpha)
{
    for (int i = 0; i < d1; i++)
    {
        for (int s = 0; s < i; s++)
        {
            printf("  ");
        }

        for (int j = 0; j < d2; j++)
        {
            printf("%c ", symb);
        }

        printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    printf("Задание 1\n");
    prac1();

    printf("Задание 2\n\n");
    prac2();

    printf("Задание 3\n");
    char symb;
    int d1, d2;
    double alpha;

    printf("Введите символ для рисования: ");
    scanf(" %c", &symb);

    printf("Введите d1 (высота): ");
    scanf("%d", &d1);

    printf("Введите d2 (ширина основания): ");
    scanf("%d", &d2);

    printf("Введите угол альфа в градусах: ");
    scanf("%lf", &alpha);

    printf("\nРезультат:\n\n");
    prac3(symb, d1,d2,alpha);
    return 0;

}
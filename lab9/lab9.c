#include <locale.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979
#define ROW 9
#define COL 9

double vx(int k, double d1, double d2, double a);
double vy(int k, double d1, double d2, double a);
int in_quad(double x, double y, double d1, double d2, double a);
void draw_figure(char sym, double d1, double d2, double ang);

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

int prac2(int c)
{
    int cifra;

    int chet = 0;
    if (c == 0)
    {
        chet += 1;
    }
    else
    {
        while (c != 0)
        {
            cifra = c % 10;
            c = c / 10;

            if (cifra % 2 == 0)
            {
                chet += 1;
            }

        }
    }


    return chet;

}

void draw_figure(char sym, double d1, double d2, double ang)
{
    if (d1 <= 0 || d2 <= 0 || ang <= 0 || ang >= 180)
    {
        puts("ошибка: d1 и d2 должны быть больше 0, угол от 0 до 180");
        return;
    }

    double ymax = fmax(vy(2, d1, d2, ang), 0);
    double ymin = fmin(vy(4, d1, d2, ang), 0);
    double xmax = fmax(vx(3, d1, d2, ang), vx(2, d1, d2, ang));
    double xmin = fmin(vx(1, d1, d2, ang), vx(4, d1, d2, ang));

    printf("\n");
    for (int r = (int)ceil(ymax); r >= (int)floor(ymin); r--)
    {
        for (int cx = (int)floor(xmin * 2); cx <= (int)ceil(xmax * 2); cx++)
        {
            if (in_quad(cx * 0.5, r, d1, d2, ang))
            {
                printf("%c", sym);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

double vx(int k, double d1, double d2, double a)
{
    double rad = a * PI / 180;
    switch (k)
    {
    case 1:
        return -0.4 * d1;
    case 2:
        return 0.6 * d2 * cos(rad);
    case 3:
        return 0.6 * d1;
    default:
        return -0.4 * d2 * cos(rad);
    }
}

double vy(int k, double d1, double d2, double a)
{
    double rad = a * PI / 180;
    switch (k)
    {
    case 2:
        return 0.6 * d2 * sin(rad);
    case 4:
        return -0.4 * d2 * sin(rad);
    default:
        return 0;
    }
}

int in_quad(double x, double y, double d1, double d2, double a)
{
    int pos = 0, neg = 0;
    for (int k = 1; k <= 4; k++)
    {
        int next = (k == 4) ? 1 : k + 1;
        double x1 = vx(k, d1, d2, a), y1 = vy(k, d1, d2, a);
        double x2 = vx(next, d1, d2, a), y2 = vy(next, d1, d2, a);
        double cross = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
        if (cross > 1e-9)
        {
            pos = 1;
        }
        if (cross < -1e-9)
        {
            neg = 1;
        }
    }
    return !(pos && neg);
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    printf("Задание 1\n");
    prac1();

    printf("Задание 2\n\n");
    char choice;
    int c, cc;

    do
    {
        printf("Введите число: ");
        scanf("%d", &c);
        cc = prac2(c);
        printf("Количество четных цифр: %d\n", cc);
        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &choice);
        printf("\n");
    } while (choice != 'n' && choice != 'N');

    puts("задание 3 (четырёхугольник по диагоналям и углу):");
    while (1)
    {
        char sym;
        double d1, d2, ang;
        printf("Введите символ, из которого будет строиться фигура: ");
        scanf(" %c", &sym);
        printf("Введите d1: ");
        scanf("%lf", &d1);
        printf("Введите d2: ");
        scanf("%lf", &d2);
        printf("Введите угол между диагоналями (в градусах): ");
        scanf("%lf", &ang);

        draw_figure(sym, d1, d2, ang);
        int cont;
        printf("\nПродолжить? (Да - введите любое число, Нет - введите 0): ");
        scanf("%d", &cont);
        if (cont == 0)
        {
            break;
        }
    }
    return 0;

}
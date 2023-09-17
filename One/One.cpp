#include <stdint.h>
#include <iostream>
#include <math.h>

/// <summary>
/// Вывод результата
/// </summary>

void Result(int i, float x1, float x2)
{
    switch (i)
    {
    case 1:
        printf("Корни квадратного уравенения равны %5.2f и %5.2f", x1, x2);
        break;
    case 2:
        printf("Корни линейного уравенения равны %5.2f и %5.2f", x1, x2);
        break;
    case 3:
        printf("Факториал числа равен %5.2f", x1);
        break;
    default:
        break;
    }
}

/// <summary>
/// Вычисление квадратного уравнения
/// </summary>

void SquareEq(float x1, float x2, float x3)
{
    float a, one, two;
    a = pow(x2, 2) - 4 * x1 * x3;
    one = (-x2 + sqrt(a)) / (2 * x1);
    two = (-x2 - sqrt(a)) / (2 * x1);
    Result(1, one, two);
}

/// <summary>
/// Вычисление системы линейных уравнений
/// </summary>

void LinearEq(float x1, float x2, float x3, float x4, float x5, float x6)
{
    float one = (x3 * x5 - x2 * x6) / (x1 * x5 - x2 * x4);
    float two = (x1 * x6 - x4 * x3) / (x1 * x5 - x2 * x4);
    Result(2, one, two);
}

/// <summary>
/// Вычисление перестановки (факториала)
/// </summary>

void Factorial(float x1)
{
    float one = 1;
    for (int i = 1; i <= x1; i++)
    {
        one *= i;
    }
    Result(3, one, one);
}

/// <summary>
/// Ввод данных
/// </summary>

void Enter(int i)
{
    float x1, x2, x3, x4, x5, x6;
    switch (i)
    {
    case 1:
        printf("Введите 3 коэфифцента через Enter\n");
        scanf_s("%f", &x1);
        scanf_s("\n%f", &x2);
        scanf_s("\n%f", &x3);
        SquareEq(x1, x2, x3);
        break;
    case 2:
        printf("Введите три коэффицента первого уравнения через Enter\n");
        scanf_s("%f", &x1);
        scanf_s("\n%f", &x2);
        scanf_s("\n%f", &x3);
        printf("Введите три коэффицента второго уравнения через Enter\n");
        scanf_s("%f", &x4);
        scanf_s("\n%f", &x5);
        scanf_s("\n%f", &x6);
        LinearEq(x1, x2, x3, x4, x5, x6);
        break;
    case 3:
        printf("Введите целое число для вычисления факториала\n");
        scanf_s("%f", &x1);
        Factorial(x1);
        break;
    default:
        printf("Введено некорректное число, повторите ввод: (1, 2 или 3)");
        break;
    }
}


/// <summary>
/// Меню
/// </summary>

void menu()
{
    while (1)
    {
        int i;
        printf("Выберите: \n1)Квадратное уравнение\n2)Система двух линейных уравнений\n3)Перестановка (факториал)\n");
        scanf_s("%d", &i);
        Enter(i);
        printf("\nХотите продолжить работу?\n1)Да\n2)Нет\n");
        scanf_s("%d", &i);
        if (i == 2)
        {
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    menu();
}
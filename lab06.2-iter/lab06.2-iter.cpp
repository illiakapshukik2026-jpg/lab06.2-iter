// Lab_6_2_Iter.cpp
// Капшук Ілля Віталійович
// Лабораторна робота № 6.2. Ітераційний спосіб.
// Варіант 6*

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Формування масиву випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виведення елементів масиву у рядок
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Пошук індексу найменшого парного елемента масиву
int FindMinEven(int* a, const int size)
{
    int imin = -1; // -1 означає, що парних елементів ще не знайдено
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (imin == -1 || a[i] < a[imin])
                imin = i;
        }
    }
    return imin; // повертає індекс або -1, якщо парні відсутні
}

// Обмін місцями першого елемента (a[0]) з найменшим парним елементом
void SwapFirstWithMinEven(int* a, const int size)
{
    int imin = FindMinEven(a, size);
    if (imin != -1) // якщо знайдено хоча б один парний елемент
    {
        int tmp = a[0];
        a[0] = a[imin];
        a[imin] = tmp;
    }
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 10;            // кількість елементів масиву
    int a[n];
    int Low = -10;             // нижня межа діапазону
    int High = 10;             // верхня межа діапазону

    Create(a, n, Low, High);    // формування масиву
    Print(a, n);               // виведення початкового масиву

    SwapFirstWithMinEven(a, n); // перестановка першого з найменшим парним
    Print(a, n);               // виведення модифікованого масиву

    return 0;
}

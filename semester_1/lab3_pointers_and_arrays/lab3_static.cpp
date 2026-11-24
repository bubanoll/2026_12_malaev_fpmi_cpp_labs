#include <iostream>
#include <cmath>
#include <random>
int main()
{
    std::setlocale(LC_ALL, ".UTF8");
    std::random_device rd;
    std::mt19937 gen(rd());
    const int MAX_MAS = 30;
    int M = 0, size = 0;
    int array = 0;
    int a = 0, b = 0;
    int arr[MAX_MAS];
    std::cout << "random - 1; ввод в ручную - 2: ";
    std::cin >> array;
    if (array == 2)
    {
        std::cout << "Введите длину массива (не больше 30): ";
        std::cin >> size;

        if (size > 30 || size <= 0)
        {
            std::cout << "Некорректный размер массива :(";
            return 1;
        }

        for (int i = 0; i < size; i++)
        {
            std::cout << "Введите " << i + 1 << " элемент массива: ";
            std::cin >> arr[i];
        }
    }
    else if (array == 1)
    {
        std::cout << "Введите границу a: ";
        std::cin >> a;
        std::cout << "Введите границу b: ";
        std::cin >> b;
        std::cout << "Введите длину массива: ";
        std::cin >> size;
        std::uniform_int_distribution<int> distrib(a, b);
        for (int i = 0; i < size; i++)
        {
            int random_number = distrib(gen);
            arr[i] = random_number;
        }
    }
    else
    {
        std::cout << "Введено неверное число :(";
        return 1;
    }

    std::cout << "Введите число M: ";
    std::cin >> M;

    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (std::abs(arr[i]) > M)
        {
            arr[index] = arr[i];
            index++;
        }
    }

    for (int i = index; i < size; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
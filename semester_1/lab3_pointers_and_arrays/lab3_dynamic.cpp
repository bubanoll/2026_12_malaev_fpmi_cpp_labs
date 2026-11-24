#include <iostream>
#include <random>
int main()
{
    std::setlocale(LC_ALL, ".UTF8");
    int size = 0;
    int index = 0;
    int array = 0;
    int a = 0, b = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    int *arr = new int[size];
    std::cout << "random - 1; ввод в ручную - 2: ";
    std::cin >> array;
    if (array == 2)
    {
        std::cout << "Введите длину массива: ";
        std::cin >> size;

        if (size <= 0)
        {
            std::cout << "Некорректный размер массива :(";
            delete[] arr;
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
        delete[] arr;
        return 1;
    }

    int max = 1;
    for (int i = 0; i < size; i++)
    {
        int len = 1;
        for (int q = i; q < size; q++)
        {
            bool isPalindrome = true;
            int left = i;
            int right = q;

            while (left < right)
            {
                if (arr[left] != arr[right])
                {
                    isPalindrome = false;
                    break;
                }
                left++;
                right--;
            }

            if (isPalindrome)
            {
                len = q - i + 1;
                if (len > max)
                {
                    max = len;
                    index = i;
                }
            }
        }
    }
    std::cout << "Полиндром: ";
    for (int i = index; i < index + max; i++)
    {

        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Длина: " << max << " :)";

    delete[] arr;
    return 0;
}
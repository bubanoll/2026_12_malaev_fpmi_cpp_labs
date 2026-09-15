#include <iostream>
int main() {
    std::setlocale(LC_ALL, ".UTF8");
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    if (number <= 0) {
        std::cout << "Введено неправильное число";
        return 1;
    }

    int result = 0;
    int d = 1;
    

    int next_number = number; 
    while (next_number > 0) {
        int cifra = next_number % 10;
        int k = 0;
        int check_number = number;
        while (check_number > 0) {
            if (check_number % 10 == cifra) {
                k++;
            }
            check_number /= 10;
        }

        if (k % 2 != 0) {
            result = result + cifra * d;
            d *= 10;
        }
        
        next_number /= 10;
    }
    
    std::cout << "Результат: " << result;
    return 0;
}

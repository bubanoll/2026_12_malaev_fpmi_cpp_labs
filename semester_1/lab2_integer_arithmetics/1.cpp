#include <iostream>
#include <optional>

std::optional<int> removeMinDigit(int number) {
    if (number <= 0) {
        return std::nullopt;
    }

    int min = 9;
    int next_number = number;
    while (next_number > 0) {
        int cifra = next_number % 10;
        if (cifra < min) {
            min = cifra;
        }
        next_number /= 10;
    }

    int result = 0;
    int k = 1;
    next_number = number;
    while (next_number > 0) {
        int cifra = next_number % 10;
        if (min != cifra) {
            result = result + cifra * k;
            k *= 10;
        }
        next_number /= 10;
    }

    return result;
}

int main() {
    std::setlocale(LC_ALL, ".UTF8");
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;

    auto res = removeMinDigit(number);
    if (!res.has_value()) {
        std::cout << "Введено неправильное число";
        return 1;
    }

    std::cout << res.value();
    return 0;
}
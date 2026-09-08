#include <iostream>

int main() {
    std::setlocale(LC_ALL, ".UTF8");
    int m, n;
    std::cout << "Введите первое число:";
    std::cin >> m;
    std::cout << "Введите второе число:";
    std::cin >> n;
    int min;
    if (n>m){
        min=m;
    }
    else{
        min=n;
    }
    std::cout << "Общие делители чисел:" << n << " и " << m << ": ";
    for(int i=1; i<=min; i++){
        if(n % i == 0 && m % i == 0){
            std::cout << i << " ";
        }
    }

    return 0;
}
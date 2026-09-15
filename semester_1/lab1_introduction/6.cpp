#include <iostream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    int a, b, d, next;
    std::cout << "Введите первый член арифметической прогрессии: ";
    std::cin >> a;
    std::cout << "Введите разность арифметической прогрессии: ";
    std::cin >> d;
    std::cout << "Введите диапазон арифметической прогресии: ";
    std::cin >> b;

    next = a;
    while(next<=b){
        if(next%3==0){
            std::cout << next << " ";
        }
        next += d;
    }
    
    

    return 0;

}
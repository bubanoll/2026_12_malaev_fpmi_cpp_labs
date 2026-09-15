#include <iostream>

int main() {
    std::setlocale(LC_ALL, ".UTF8");
    int number, min=9, next_number, cifra, k=1, result=0;
    std::cout<<"Введите число:";
    std::cin>>number;
    if(number<=0){
        std::cout<<"Введено неправильное число";
        return 1;
    }
    next_number=number;
    while(next_number>0){
        cifra=next_number%10;
        if(cifra<min){
            min=cifra;
        }
        next_number/=10;
    }
    next_number=number;
    while(next_number>0){
        cifra=next_number%10;
        if(min!=cifra){
            result=result+cifra*k;
            k*=10;
        }
        next_number/=10;
    }
    std::cout<<result;

    return 0;
}
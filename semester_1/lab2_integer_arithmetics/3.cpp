#include <iostream>

int main() {
    std::setlocale(LC_ALL, ".UTF8");
    int number, min=9, next_number, cifra, k=1, result=0, d=0;
    std::cout<<"Введите число:";
    std::cin>>number;
    if(number<=0){
        std::cout<<"Введено неправильное число";
        return 1;
    }
    next_number=number;
    while(next_number>0){
        cifra=next_number%10;
        if(cifra<min || cifra!=0){
            min=cifra;
        }
        next_number/=10;
        d+=1;
    }
    next_number=number;
    result = min;
    std::cout<<result;
    return 0;
}
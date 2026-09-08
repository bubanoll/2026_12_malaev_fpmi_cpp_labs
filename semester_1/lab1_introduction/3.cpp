#include <iostream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    int a, first, second, third, forth;
    std::cout << "Введите четырехзначное число:";
    std::cin >> a;
    if(a>999 && a<10000){
        first=a/1000;
        second=(a/100)%10;
        third=(a/10)%10;
        forth=a%10;
        if(first==forth && second==third){
            std::cout << "Ваше число палиндромное! :)";
        }
        else{
            std::cout << "Ваше число не палиндромное :(";
        }

    }
    else{
        std::cout << "Вы ввели не четырёхзначное число, попробуйте ещё раз:";
        std::cin >> a;
    }
    return 0;
}
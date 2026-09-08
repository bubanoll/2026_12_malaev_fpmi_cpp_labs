#include <iostream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    int a, first, second, third, forth, fifth, sixth;
    std::cout << "Введите шестизначное число:";
    std::cin >> a;
    if(a>99999 && a<1000000){
        first=a/100000;
        second=(a/10000)%10;
        third=(a/1000)%10;
        forth=(a/100)%10;
        fifth=(a/10)%10;
        sixth=a%10;
        if(first+second+third==forth+fifth+sixth){
            std::cout << "Ваше число счастливое! :)";
        }
        else{
            std::cout << "Ваше число обычное :(";
        }

    }
    else{
        std::cout << "Вы ввели не шестизначное число, попробуйте ещё раз:";
        std::cin >> a;
    }
    return 0;
}
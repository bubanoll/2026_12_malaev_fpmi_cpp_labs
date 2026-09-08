#include <iostream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    int a, b, d, next, m;
    std::cout << "Введите первый член арифметической прогрессии: ";
    std::cin >> a;
    std::cout << "Введите разность арифметической прогрессии: ";
    std::cin >> d;
    std::cout << "Введите диапазон арифметической прогресии: ";
    std::cin >> b;
    m=b/d-1;
    for(int i=0; i<=m; i++){
        std::cout << a << " ";
        next=a+d;
        if(next<b){
            a=next;
        }
        else{
            std::cout << "";
        }
    }

    return 0;

}
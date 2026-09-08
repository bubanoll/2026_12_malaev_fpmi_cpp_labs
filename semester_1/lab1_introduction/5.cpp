#include <iostream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    int N, before=0, number=1, next=0;
    std::cout << "Введите число:";
    std::cin >> N;
    std::cout << "Числа Фибоначчи: ";
    for(int i=1; i<=N; i++){
        std::cout << number << " ";
        next=before+number;
        before=number;
        number=next;
    }
    
    return 0;

}
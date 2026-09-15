#include <iostream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    int N;
    std::cout << "Введите число:";
    std::cin >> N;
    std::cout << "Нечётные числа: ";
    for(int i=0; i<=N; i++){
        if(i%2!=0){
            std:: cout << i << " ";
        }
    }
    // 1 3 5 7 9 11 ....
    return 0;

}
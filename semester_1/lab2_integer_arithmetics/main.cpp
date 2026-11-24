#include <iostream>
int main(){
    setlocale (LC_ALL, ".UTF8");
    int a, b, ans=0;
    std::cout<<"Введите первое число: ";
    if (!(std::cin>>a) || a <=0) {
        std::cout <<"Error: wrong input";
        return 1;
    }
    std::cout<<"Введите второе число: ";
    if (!(std::cin>>a) || a <=0) {
        std::cout <<"Error: wrong input";
        return 1;
    }
    for(int i=a; i<=b; i++){
        int number=i;
        bool f = true;
        while (number > 0)
        {
            if ((number % 10) % 2 ==0)
            {
            f=false;
            break;
            }
        }
        number /=10;
        
    if (f) {
        ans++;
        std::cout << i << std::endl;
    }
    }
    std::cout << "Ответ: " << ans;
    return 0;
}

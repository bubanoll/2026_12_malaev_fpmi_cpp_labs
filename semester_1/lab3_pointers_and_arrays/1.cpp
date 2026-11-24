#include <iostream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    int _judges_;
    std::cout << "Введите количество судей (число должно быть целым): ";
    std::cin >> _judges_;
    const int judges = _judges_;
    double score[judges];
    if (judges <= 2) {
        std::cout << "Некорректное количество судей!";
        return 1;
    }
    double point;
    for(int i = 1; i <= judges; i++){
        std::cout << "Введите балл " << i << " судьи:";
        std::cin >> point;
        if(point < 0){
            std::cout << "Введён некорректный балл :(";
            return 1;
        }
        score[i-1] = point;
    }
    double sum = 0;
    double min = score[0];
    for(int q = 0; q < judges; q++){
        sum += score[q];
        if(min > score[q]){
            min = score[q];
        }
    }
    
    double max = score[0];
    for(int w = 0; w < judges; w++){
        if(max < score[w]){
            max = score[w];
        }
    }
    sum = sum - min - max;
    sum = sum / (judges - 2);
    std::cout << "Количество баллов, набранные спортсменом равняются: " << sum;
    return 0;
}
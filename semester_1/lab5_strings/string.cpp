#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
int main(){
    std::setlocale(LC_ALL, ".UTF8");
    std::string s;
    std::cout << "Введите слова латиницей через пробел: ";
    getline(std::cin, s);
    s = " " + s + " ";
    std::string copy(s);
    for(char &i : copy){
        i = std::tolower(i);
    }
    int copy_length = copy.length();
    while(copy_length != 0){
        std::stringstream stream(copy);
        std::string word;
        if (!(stream >> word)) {
            break;
        }
        int length = word.length();
        std::size_t first_pos = copy.find(" " + word + " ");
        std::size_t index = copy.find(" " + word + " ", first_pos + length + 1); 
        while(index != std::string::npos){
            s.erase(index, length + 1);
            copy.erase(index, length + 1);
            index = copy.find(" " + word + " ", index);
        }
        std::cout << s.substr(first_pos + 1, length) << " ";
        s.erase(first_pos, length + 1);
        copy.erase(first_pos, length + 1);
        copy_length = copy.length();
        
    }
    return 0;
    }
    
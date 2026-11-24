#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <locale>

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable: 4996)
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format
           ? std::put_time(std::gmtime(&time), "%x %X")
           : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
    #pragma warning(pop)
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop
#endif
}


int main(){
    std::setlocale(LC_ALL, ".UTF8");
    std::string pathIn = "input.txt";
    std::string pathOut = "output.txt";
    std::string pathLog = "log.txt";
    std::ifstream file_in;
    std::ofstream file_out;
    std::ofstream file_log;
    std::string s;
    file_log.open(pathLog);

    file_log << FormatTime(Now(), false) << " | opening file \"" << pathIn << "\"\n";
    file_in.open(pathIn);
    if (file_in.is_open()) {
        file_log << FormatTime(Now(), false) << " | file \"" << pathIn << "\" has been opened successfully\n";
    }

    file_log << FormatTime(Now(), false) << " | opening file \"" << pathOut << "\"\n";
    file_out.open(pathOut);
    if (file_out.is_open()) {
        file_log << FormatTime(Now(), false) << " | file \"" << pathOut << "\" has been opened successfully\n";
    }
    
    if(!file_in.is_open()){

        file_log << FormatTime(Now(), false) << " | error opening file \"" << pathIn << "\"\n";
        std::cout << "Ошибка окрытия файла :(";

    }

    else{
        file_log << FormatTime(Now(), false) << " | reading lines from \"" << pathIn << "\"\n";
        std::string str;
        while(!file_in.eof()){
            str = "";
            getline(file_in, str);
            file_log << FormatTime(Now(), false) << " | got line: \"" << str << "\"\n";
            s = s + str;
        }
        file_log << FormatTime(Now(), false) << " | removing duplicate words in line\n";
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
            file_log << FormatTime(Now(), false) << " | writing word \"" << s.substr(first_pos + 1, length) << "\" to \"" << pathOut << "\"\n";
            file_out << s.substr(first_pos + 1, length) << " ";
            s.erase(first_pos, length + 1);
            copy.erase(first_pos, length + 1);
            copy_length = copy.length();
        }
    }
    file_out.close();
    file_in.close();
    file_log << FormatTime(Now(), false) << " | program has ended with code 0\n";
    file_log.close();
    return 0;
    }
    
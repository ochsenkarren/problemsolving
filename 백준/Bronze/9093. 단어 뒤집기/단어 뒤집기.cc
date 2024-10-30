#include <iostream>
#include <sstream>

void reversed_read(const char *c_str, int idx) {
    while (0 < idx)
        std::cout << c_str[--idx];
}

int main() {
    int T;

    std::string input;
    std::getline(std::cin, input);
    T = std::stoi(input);
    
    for (int i = 0; i < T; ++i) {
        std::getline(std::cin, input);
        std::stringstream iss(input);
        std::string word;
        iss >> word;
        reversed_read(word.c_str(), word.size());
        while (iss >> word) {
            std::cout << " ";
            reversed_read(word.c_str(), word.size());
        }
        std::cout << std::endl;
    }
    return 0;
}
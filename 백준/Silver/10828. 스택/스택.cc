#include <iostream>
#include <string>
#include <stack>
int main() {
    int N;
    std::cin >> N;
    std::stack<int> stack;

    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        auto idx = str.find("push");
        if (idx != std::string::npos) {
            int X;
            std::cin >> X;
            stack.push(X);
            continue;
        }
        idx = str.find("pop");
        if (idx != std::string::npos) {
            if (stack.empty())
                std::cout << -1 << std::endl;
            else {
                std::cout << stack.top() << std::endl;
                stack.pop();
            }
            continue;
        }
        idx = str.find("empty");
        if (idx != std::string::npos) {
            std::cout << stack.empty() << std::endl;
            continue;
        }
        idx = str.find("size");
        if (idx != std::string::npos) {
            std::cout << stack.size() << std::endl;
            continue;
        }
        idx = str.find("top");
        if (idx != std::string::npos) {
            if (stack.empty())
                std::cout << -1 << std::endl;
            else
                std::cout << stack.top() << std::endl;
        }
    }
    return 0;
}

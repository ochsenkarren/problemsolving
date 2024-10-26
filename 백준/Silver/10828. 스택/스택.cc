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
        if (str == "push") {
            int X;
            std::cin >> X;
            stack.push(X);
        }
        else if (str == "pop") {
            if (stack.empty())
                std::cout << -1 << std::endl;
            else {
                std::cout << stack.top() << std::endl;
                stack.pop();
            }
        }
        else if (str == "empty") {
            std::cout << stack.empty() << std::endl;
        }
        else if (str == "size") {
            std::cout << stack.size() << std::endl;
        }
        else if (str == "top") {
            if (stack.empty())
                std::cout << -1 << std::endl;
            else
                std::cout << stack.top() << std::endl;
        }
    }
    return 0;
}

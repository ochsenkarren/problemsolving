#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int n = (a == b) + (b == c) + (c == a);
    int answer = a + b + c;
    
    if (n == 0)
        return answer;
    answer *= a * a + b * b + c * c;
    if (n == 1)
        return answer;
    answer *= a * a * a * 3;
    return answer;
}
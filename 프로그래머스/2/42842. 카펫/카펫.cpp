#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int x = brown / 2 + 1;
    int y = 1;
    while (x > y) {
        if (x * y == brown + yellow)
            break;
        --x;
        ++y;
    }
    vector<int> answer(2);
    answer[0] = x, answer[1] = y;
    return answer;
}
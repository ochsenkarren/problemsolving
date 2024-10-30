#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    for (auto it = arr.begin(); it != arr.end(); it++)
        answer.append(*it);
    return answer;
}
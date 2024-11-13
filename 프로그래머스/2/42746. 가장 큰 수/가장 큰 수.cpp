#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Compare {
    bool operator () (string a, string b) {
        return (a + b > b + a);
    }
};

string solution(vector<int> numbers) {
    vector<string> v(numbers.size());
    for (int i = 0; i < numbers.size(); ++i)
        v[i] = to_string(numbers[i]);
    sort(v.begin(), v.end(), Compare());
    string answer = "";
    for (string str : v) {
        if (answer == "0")
            answer = str;
        else
            answer += str;
    }
    return answer;
}
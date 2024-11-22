#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int len = word.size();
    vector<int> acc(5, 0);
    int sum = 0;
    for (int i = 0; i < 5; ++i)
        acc[4 - i] += (sum = sum * 5 + 1);

    vector<int> v('U' + 1, 0);
    string str = "AEIOU";
    for (int i = 0; i < 5; ++i)
        v[str[i]] = i;
    
    int answer = 0;
    for (int i = 0; i < len; ++i)
        answer += acc[i] * v[word[i]];
    return answer + len;
}
#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    vector<char> v;
    for (int i = 0; i < str1.length(); i++) {
        v.push_back(str1[i]);
        v.push_back(str2[i]);
    }
    return string(v.begin(), v.end());
}
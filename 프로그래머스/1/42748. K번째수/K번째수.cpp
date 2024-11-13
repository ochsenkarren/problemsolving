#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); ++i) {
        int a = commands[i][0];
        int b = commands[i][1];
        vector<int> sub(b - a + 1);
        for (int j = a - 1; j < b; ++j)
            sub[j - a + 1] = array[j];
        sort(sub.begin(), sub.end());
        answer.push_back(sub[commands[i][2] - 1]);
    }
    return answer;
}
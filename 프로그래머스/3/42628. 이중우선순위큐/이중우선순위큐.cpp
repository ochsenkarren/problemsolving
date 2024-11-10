#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> ops) {
    multiset<int> ms;
    for (string& op : ops) {
        char o = op[0];
        int num = stoi(op.substr(2));
        if (o == 'I')
            ms.insert(num);
        else if (num == 1 && !ms.empty())
            ms.erase(--(ms.end()));
        else if (num == -1 && !ms.empty())
            ms.erase(ms.begin());
    }
    vector<int> answer(2);
    if (!ms.empty()) {
        answer[0] = *(ms.rbegin());
        answer[1] = *(ms.begin());
    }
    return answer;
}
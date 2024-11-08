#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_multiset<string> ums;
    unordered_set<string> us;
    
    for (auto it = clothes.begin(); it != clothes.end(); ++it) {
        ums.insert((*it)[1]);
        us.insert((*it)[1]);
    }
    int answer = 1;
    for (auto it = us.begin(); it != us.end(); it++)
        answer *= (ums.count(*it) + 1);
    return answer - 1;
}
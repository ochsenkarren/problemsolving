#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int len = prices.size();
    vector<int> answer(len);
    for (int i = 0; i < len; i++) {
        int dur = 0;
        for (int j = i + 1; j < len; j++) {
            ++dur;
            if (prices[j] < prices[i])
                break;    
        }
        answer[i] = dur;
    }
    return answer;
}
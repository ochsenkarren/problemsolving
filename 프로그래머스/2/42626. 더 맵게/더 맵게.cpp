#include <string>
#include <vector>
#include <queue>

using namespace std;
struct Compare {
    bool operator()(unsigned int a, unsigned int b) {
        return a > b;
    }
};

int solution(vector<int> sco, int K) {
    
    priority_queue<unsigned int, vector<unsigned int>, Compare> pq;
    for (int s : sco)
        pq.push(s);
    int answer = 0;
    while (!pq.empty()) {
        int s1 = pq.top();
        if (K <= s1)
            break;
        pq.pop();
        if (pq.empty())
            return -1;
        int s2 = pq.top();
        pq.pop();
        pq.push(s1 + s2 * 2);
        ++answer;
    }
    return answer;
}
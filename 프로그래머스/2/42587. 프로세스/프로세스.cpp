#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> pri, int location) {
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i < pri.size(); i++) {
        q.push(i);
        pq.push(pri[i]);
    }
    int answer = 0;
    
    while (1) {
        int front = q.front();
        if (pri[front] == pq.top()) {
            ++answer;
            if (front == location)
                break;
            q.pop();
            pq.pop();
            continue;
        }
        q.push(q.front());
        q.pop();
    }
    return answer;
}
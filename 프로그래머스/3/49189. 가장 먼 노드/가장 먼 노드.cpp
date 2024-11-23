#include <string>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int INTMAX = ~(1 << 31);
int solution(int n, vector<vector<int>> edge) {
    vector<list<int>> adjList(n + 1);
    vector<int> dst(n + 1, INTMAX);
    int far = 0;
    for (int i = 0; i < edge.size(); ++i) {
        int a = edge[i][0];
        int b = edge[i][1];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dst[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int base = -top.first;
        int from = top.second;
        if (far < base)
            far = base;
        for (int to : adjList[from]) {
            if (base + 1 < dst[to]) {
                dst[to] = base + 1;
                pq.push({-dst[to], to});
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; ++i)
        answer += dst[i] == far ? 1 : 0;
    return answer;
}
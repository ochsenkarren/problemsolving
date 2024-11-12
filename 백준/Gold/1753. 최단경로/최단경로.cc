#include <cstdio>
#include <forward_list>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1 << 31 - 1;
int V, E, K;
int main(void) {
    scanf("%d %d %d", &V, &E, &K);

    forward_list<pair<int, int>> fList[V + 1];
    vector<int> cost(V + 1, INF);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        fList[u].push_front({v, w});
    }
    cost[K] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int node = top.second;
        int base = -top.first;
        for (auto it = fList[node].begin(); it != fList[node].end(); it++) {
            int newly = base + it->second;
            int to = it->first;
            if (newly < cost[to]) {
                cost[to] = newly;
                pq.push({-cost[to], to});
            }
        }
    }
    for (int i = 1; i <= V; i++)
        printf(cost[i] == INF ? "INF\n" : "%d\n", cost[i]);
}
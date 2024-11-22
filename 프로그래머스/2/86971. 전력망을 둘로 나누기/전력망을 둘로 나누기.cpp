#include <string>
#include <vector>
#include <list>
using namespace std;
void go(vector<list<int>> &adj, vector<bool> visit, int node, int &count) {
    visit[node] = true;
    ++count;
    for (int a : adj[node])
        if (!visit[a])
            go(adj, visit, a, count);
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for (int exc = 0; exc < n - 1; ++exc) {
        vector<bool> visit(n + 1, false);
        vector<list<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            if (i == exc)
                continue;
            int a = wires[i][0];
            int b = wires[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);    
        }
        int cnt = 0;
        go(adj, visit, 1, cnt);
        int abs = n - cnt * 2;
        abs = abs < 0 ? -abs : abs;
        if (abs < answer)
            answer = abs;
    }
    return answer;
}

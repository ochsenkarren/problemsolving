#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

int traverse(vector<list<int>> &adjList, vector<bool> &visit, vector<int> &cnt, int node) {
    visit[node] = true;
    int count = 1;
    for (int adj : adjList[node]) {
        if (!visit[adj])
            count += traverse(adjList, visit, cnt, adj);
    }
    cnt[node] = count;
    return count;
}
int solution(int n, vector<vector<int>> wires) {
    
    vector<list<int>> adjList(n + 1);
    vector<int> cnt(n + 1, 0);
    vector<bool> visit(n + 1, false);
    int root;
    for (int i = 0; i < wires.size(); ++i) {
        int a = wires[i][0];
        int b = wires[i][1];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (adjList[i].size() == 1) {
            root = i;
            break;
        }            
    }
    cnt[root] = traverse(adjList, visit, cnt, root);
    int answer = n;
    for (int c : cnt) {
        int abs = n - c * 2;
        abs = abs < 0 ? -abs : abs;
        if (abs < answer)
            answer = abs;
    }
    return answer;
}

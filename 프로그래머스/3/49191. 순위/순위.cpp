#include <string>
#include <vector>
#include <list>
using namespace std;
void go(vector<list<int>> &adjList, vector<bool> &visit, int from, const int n, int &cnt) {
    for (int to : adjList[from]) {
        if (!visit[to]) {
            visit[to] = true;
            ++cnt;
            go(adjList, visit, to, n, cnt);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    vector<list<int>> wList(n + 1);
    vector<list<int>> lList(n + 1);
    vector<int> wCnt(n + 1, 0);
    vector<int> lCnt(n + 1, 0);
    
    for (int i = 0; i < results.size(); ++i) {
        int w = results[i][0];
        int l = results[i][1];
        wList[w].push_back(l);
        lList[l].push_back(w);
    }
    
    
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int wCount = 0, lCount = 0;
        vector<bool> visit(n + 1, false);
        go(wList, visit, i, n, wCount);
        visit.assign(n + 1, false);
        go(lList, visit, i, n, lCount);
        // if (wCnt[i] + lCnt[i] == n - 1)
        if (wCount + lCount == n - 1)
            ++answer;
    }
    return answer;
}
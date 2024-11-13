#include<vector>
#include<queue>

using namespace std;

int mov[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int visit[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; j++)
            visit[i][j] = -1;
    
    queue<pair<int, int> > q;
    q.push({0, 0});
    visit[0][0] = 1;
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int i = node.first;
        int j = node.second;
        int base = visit[i][j];
        for (int k = 0; k < 4; ++k) {
            int i_ = i + mov[k][0];
            int j_ = j + mov[k][1];
            if (i_ < 0 || n <= i_ || j_ < 0 || m <= j_ || !maps[i_][j_] || visit[i_][j_] != -1)
                continue;
            visit[i_][j_] = base + 1;
            q.push({i_, j_});
        }
    }    
    return visit[n - 1][m - 1];
}
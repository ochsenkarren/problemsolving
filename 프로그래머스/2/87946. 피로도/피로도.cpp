#include <string>
#include <vector>

using namespace std;
int N, answer = 0;
vector<bool> visit;

void go(vector<vector<int>>& d, int k, int sum) {
    for (int i = 0; i < N; ++i) {
        if (visit[i] || k < d[i][0])
            continue;
        visit[i] = true;
        go(d, k - d[i][1], sum + 1);
        visit[i] = false;
    }
    if (answer < sum)
        answer = sum;
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    visit.assign(N, false);
    go(dungeons, k, 0);
    return answer;
}
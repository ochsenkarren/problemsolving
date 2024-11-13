#include <string>
#include <vector>

using namespace std;
vector<bool> visit;
int N;
void traverse(vector<vector<int>>& com, int idx) {
    visit[idx] = true;
    for (int i = 0; i < N; ++i) {
        if (com[idx][i] && !visit[i])
            traverse(com, i);
    }
}
int solution(int n, vector<vector<int>> computers) {
    N = n;
    visit.assign(n, false);
    int answer = 0;    
    for (int i = 0; i < n; i++) {
        if (visit[i])
            continue;
        traverse(computers, i);
        ++answer;
    }
    return answer;
}
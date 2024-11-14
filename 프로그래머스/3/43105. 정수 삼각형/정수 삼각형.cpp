#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int sum(int n) { return (n * (n + 1)) / 2; }
int toI(int n, int k) { return sum(n) + k; }

int solution(vector<vector<int>> tri) {
    N = tri.size();
    vector<int> v(sum(N), 0);
    v[0] = tri[0][0];
    for (int i = 1; i < N; ++i) {
        v[toI(i, 0)] = tri[i][0] + v[toI(i - 1, 0)];
        v[toI(i, i)] = tri[i][i] + v[toI(i - 1, i - 1)];
    }
    for (int i = 2; i < N; ++i)
        for (int j = 1; j < i; ++j)
            v[toI(i, j)] = max(v[toI(i - 1, j)], v[toI(i - 1, j - 1)]) + tri[i][j];
    int answer = 0;
    for (int i = sum(N - 1); i < sum(N); ++i)
        answer = max(answer, v[i]);
    return answer;
}
    // (n, k) -> (n * (n + 1)) / 2 + k;
    // 왼쪽 아래로 (n, k) -> (n + 1, k)
    // 오른쪽 아래로 (n, k) -> (n + 1, k + 1)
    // 왼쪽 위로 (n, k) -> (n - 1, k - 1)
    // 오른쪽 위로 (n, k) -> (n - 1, k)

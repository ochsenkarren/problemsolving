#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    vector<vector<int>> v(4);
    for (int i = 0; i < 4; ++i)
        v[i].assign(n, 0);
    v[0][1] = money[1];
    v[3][1] = v[2][0] = money[0];
    for (int i = 2; i < n; ++i) {
        v[0][i] = v[1][i - 1] + money[i];
        v[1][i] = max(v[0][i - 1], v[1][i - 1]);
        v[2][i] = v[3][i - 1] + money[i];
        v[3][i] = max(v[2][i - 1], v[3][i - 1]);
    }
    return max(max(v[0][n - 1], v[1][n - 2]), v[3][n - 1]);
}

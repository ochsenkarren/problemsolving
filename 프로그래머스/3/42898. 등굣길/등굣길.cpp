#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<int> v[100];
    bool p[100][100];
    
    for (int i = 0; i < m; ++i) {
        v[i].assign(n, 0);
        for (int j = 0; j < n; ++j)
            p[i][j] = false;
    }   
    
    for (auto it = puddles.begin(); it != puddles.end(); ++it) {
        p[(*it)[0] - 1][(*it)[1] - 1] = true;
    }
    
    for (int i = 1; i < m && !p[i][0]; ++i)
        v[i][0] = 1;
    for (int i = 1; i < n && !p[0][i]; ++i)
        v[0][i] = 1;
    
    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (p[i][j]) {
                v[i][j] = 0;
                continue;                
            }
            v[i][j] = (v[i - 1][j] + v[i][j - 1]) % 1000000007;
        }
    }
    
    return v[m - 1][n - 1];
}
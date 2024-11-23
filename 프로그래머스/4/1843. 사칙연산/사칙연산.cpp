#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int INTMIN = 1 << 31;
int INTMAX = ~INTMIN;
int solution(vector<string> arr)
{
    int n = arr.size() / 2 + 1;
    vector<vector<int>> maxDP(n);
    vector<vector<int>> minDP(n);
    for (int i = 0; i < n; ++i) {
        maxDP[i].assign(n, INTMIN);
        minDP[i].assign(n, INTMAX);
        maxDP[i][i] = minDP[i][i] = stoi(arr[i * 2]);
    }
    // for (int i = 0; i < n; ++i) {
    //     maxDP[i].assign(i + 1, INTMIN);
    //     minDP[i].assign(i + 1, INTMAX);
    // }
    
    for (int len = 2; len <= n; ++len) {
        
        for (int x = 0; x <= n - len; ++x) {
            int symIdx = x * 2 + 1;
            int maxi = INTMIN;
            int mini = INTMAX;
            for (int xLen = 1; xLen < len; ++xLen) {
                if (arr[symIdx] == "+") {
                    maxi = max(maxi, maxDP[x][x + xLen - 1] + maxDP[x + xLen][x + len - 1]);
                    mini = min(mini, minDP[x][x + xLen - 1] + minDP[x + xLen][x + len - 1]);
                }
                else {
                    maxi = max(maxi, maxDP[x][x + xLen - 1] - minDP[x + xLen][x + len - 1]);
                    mini = min(mini, minDP[x][x + xLen - 1] - maxDP[x + xLen][x + len - 1]);          
                }
                symIdx += 2;
            }
            maxDP[x][x + len - 1] = maxi;
            minDP[x][x + len - 1] = mini;
        }
    }
    return maxDP[0][n - 1];
}
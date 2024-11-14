#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> v(n + 2, 0);
    for (int l : lost)
        v[l] = -1;
    for (int r : reserve)
        ++v[r];
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] == 0) {
            ++answer;
            continue;
        }
        if (v[i] == 1) {   
            ++answer;
            if (v[i - 1] == -1) {
                ++v[i - 1];
                ++answer;
            }
            else if (v[i + 1] == -1) {
                ++v[i + 1];
            }
        }
    }
    return answer;
}
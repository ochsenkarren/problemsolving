#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> v(32001, -1);
unordered_set<int> nums[9];
void input(int num, int tier) {
    if (num <= 0 || 32000 < num)
        return;
    if (v[num] == -1) {
        v[num] = tier;
        nums[tier].insert(num);
    }
}
int solution(int N, int number) {
    int exp = N;
    input(N, 1);
    exp *= 11;
    input(exp, 2);
    input(N * N, 2);
    input(1, 2);
    input(N * 2, 2);
    
    for (int i = 3; i <= 8; ++i) {
        exp = exp * 10 + N;
        input(exp, i);
        for (int j = 1; j <= i / 2; ++j) {
            for (auto it0 = nums[j].begin(); it0 != nums[j].end(); ++it0) {
                int k = i - j;
                for (auto it1 = nums[k].begin(); it1 != nums[k].end(); ++it1) {
                    int a = *it0, b = *it1;
                    input(a + b, i);
                    input(a * b, i);

                    input(a - b, i);
                    input(b - a, i);
                    int div = b / a;
                    input(div <= 1 ? a / b : div, i);
                }
            }
        }
    }
    return v[number];
}
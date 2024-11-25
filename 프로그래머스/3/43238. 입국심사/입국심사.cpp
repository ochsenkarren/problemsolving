#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long l = 1LL, r = 1000000000000000000LL;
    long long answer = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long output = 0;
        for (int t : times)
            output += (mid / t);
        if (n <= output) {
            answer = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return answer;
}
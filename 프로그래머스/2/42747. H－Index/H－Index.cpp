#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cit) {
    
    vector<int> v(10001, 0);
    
    int n = cit.size();
    int max = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        int quote = cit[i];
        ++v[quote];
        sum += quote;
        if (max < quote)
            max = quote;
    }
    int cnt = 0;
    for (int i = max; 0 <= i; --i) {
        cnt += v[i];
        if (i <= cnt)
            return i;
    }
    
    return 0;
}
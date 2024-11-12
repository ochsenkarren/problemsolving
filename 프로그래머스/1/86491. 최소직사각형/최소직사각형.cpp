#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int longer = 0, shorter = 0;
    for (int i = 0; i < sizes.size(); ++i) {
        int l = max(sizes[i][0], sizes[i][1]);
        longer = max(longer, l);
        int s = sizes[i][0] + sizes[i][1] - l;
        shorter = max(shorter, s);
    }
    return longer * shorter;
}
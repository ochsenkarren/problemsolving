#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> us;
    for (auto it = nums.begin(); it != nums.end(); it++)
        us.insert(*it);
    return min(us.size(), nums.size() / 2);
}
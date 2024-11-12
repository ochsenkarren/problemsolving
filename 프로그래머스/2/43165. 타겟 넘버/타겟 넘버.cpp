#include <string>
#include <vector>

using namespace std;

vector<bool> arr(20);
int answer = 0;
void go(vector<int> &numbers, int idx, int sum, int remain, int target) {
    if (idx == numbers.size()) {
        if (sum == target)
            ++answer;
        return;
    }
    if (sum + remain < target || target < sum - remain)
        return ;
    
    int num = numbers[idx];
    go(numbers, idx + 1, sum + num, remain - num, target);
    go(numbers, idx + 1, sum - num, remain - num, target);
}

int solution(vector<int> numbers, int target) {
    int remain = 0;
    for (int n : numbers)
        remain += n;
    go(numbers, 0, 0, remain, target);
    return answer;
}
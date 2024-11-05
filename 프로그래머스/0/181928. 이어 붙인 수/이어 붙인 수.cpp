#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int even = 0, odd = 0;
    for (int n : num_list) {
        if (n % 2)
            odd = odd * 10 + n;
        else
            even = even * 10 + n;
    }
    return odd + even;
}
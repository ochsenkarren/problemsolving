#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    auto it = num_list.rbegin();
    int last = *it;
    int prev = *(++it);
    int add =  prev < last ? last - prev : last * 2;
    num_list.push_back(add);
    return num_list;
}
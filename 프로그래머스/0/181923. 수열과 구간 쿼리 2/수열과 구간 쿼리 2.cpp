#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (auto it = queries.begin(); it != queries.end(); it++) {
        int add = -1;
        for (int i = (*it)[0]; i <= (*it)[1]; i++) {
            if ((*it)[2] < arr[i])
                if (add == -1 || arr[i] < add)
                    add = arr[i];
        }
        answer.push_back(add);
    }
    return answer;
}
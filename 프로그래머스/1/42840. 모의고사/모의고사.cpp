#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int arr2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int arr3[] = {3, 1, 2, 4, 5};
    
    vector<int> answer(3, 0);
    for (int i = 0; i < answers.size(); i++) {
        int a = answers[i];
        answer[0] += (1 + i % 5 == a);
        answer[1] += (arr2[i % 8] == a);
        answer[2] += (arr3[(i % 10) / 2] == a);        
    }
    vector<int> ret;
    for (int i = 0; i < 3; i++) 
        if (answer[i % 3] >= answer[(i + 1) % 3] && answer[i % 3] >= answer[(i + 2) % 3])
            ret.push_back(i + 1);    
    return ret;
}
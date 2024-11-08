#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> pro, vector<int> spd) {
    vector<int> answer;
    int front = 0;
    int len = pro.size();
    
    while (front < len) {
        if (100 <= pro[front]) {
            int add = 0;
            while (front < len && 100 <= pro[front]) {
                ++front;
                ++add;
            }
            answer.push_back(add);
        }
        for (int i = front; i < len; i++)
            pro[i] += spd[i];
    }    
    return answer;
}
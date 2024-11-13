#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool isAdj(string a, string b) {
    int len = a.length();
    int count = 0;
    
    for (int i = 0; i < len; ++i) {
        if (a[i] != b[i]) {
            if (1 < ++count)
                return false;
        }
    }
    return count == 1;
}

int solution(string begin, string target, vector<string> words) {
    int len = words.size();
    int bIdx = -1, tIdx = -1;
    vector<vector<bool>> m(len);
    vector<int> v(len, 0);
    for (int i = 0; i < len; ++i)
    {
        m[i].assign(len, false);
        if (isAdj(words[i], begin)) {
            v[i] = 1;
            bIdx = i;
        }
        if (words[i] == target)
            tIdx = i;
    }
    if (tIdx == -1 || bIdx == -1)
        return 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (isAdj(words[i], words[j])) {
                m[i][j] = true;
                m[j][i] = true;
            }
        }
    }
 
    queue<int> q;
    for (int i = 0; i < len; ++i)
        if (v[i] == 1)
            q.push(i);
    while (!q.empty()) {
        int node = q.front();
        if (node == tIdx)
            return v[node];
        q.pop();
        int cost = v[node] + 1;
        for (int i = 0; i < len; ++i) 
            if (m[node][i]) {
                if(v[i] == 0 || cost < v[i]){
                    v[i] = cost;
                    q.push(i);
                }
            }
        }
    
    return 0;
}

// 이거 풀고 나서
// 메모리/포인터 부분 처리하고
// 커피 드링킹하러 가자
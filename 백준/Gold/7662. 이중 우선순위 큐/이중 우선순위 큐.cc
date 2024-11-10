#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
using namespace std;

void solution(vector<string> ops) {
    multiset<int> ms;
    for (string& op : ops) {
        char o = op[0];
        int num = stoi(op.substr(2));
        if (o == 'I')
            ms.insert(num);
        else if (num == 1 && !ms.empty())
            ms.erase(--(ms.end()));
        else if (num == -1 && !ms.empty())
            ms.erase(ms.begin());
    }
    if (ms.empty()) {
        printf("EMPTY\n");
        return ;
    }
    printf("%d %d\n", *(ms.rbegin()), *(ms.begin()));
}

int main(void) {
    int T, k;
    scanf("%d%*c", &T);
    for (int i = 0; i < T; ++i) {

        scanf("%d%*c", &k);
        vector<string> ops(k);
        for (int j = 0; j < k; ++j)
			getline(cin, ops[j]);
        solution(ops);
    }
    return 0;
}
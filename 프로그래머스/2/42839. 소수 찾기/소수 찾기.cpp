#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int N;
const int LEN = 10000000;
vector<bool> prime(LEN, true);
vector<bool> visit;
unordered_set<int> primes;
void go(vector<string> &v, int cnt, string str) {
    for (int i = 0; i < N; ++i) {
        if (visit[i])
            continue;
        visit[i] = true;
        go(v, cnt + 1, str == "0" ? v[i] : str + v[i]);
        visit[i] = false;
    }
    if (str != "") {
        int p = stoi(str);
        if (prime[p])
            primes.insert(p);
    } 
}

int solution(string numbers) {
    prime[0] = false; prime[1] = false;
    for (int i = 4; i < LEN; i += 2)
        prime[i] = false;
    for (int i = 3; i * i < LEN; i += 2)
        for (int j = i * i; j < LEN; j += i)
            prime[j] = false;
    
    N = numbers.length();
    vector<string> v(N);
    visit.assign(N, false);
    for (int i = 0; i < N; ++i)
        v[i] = numbers.substr(i, 1);
    go(v, 0, "");
    for (int n : primes)
        cout << n << endl;
    return primes.size();
}
// 안나 카레니나, 허클베리 핀
// - 둘중 하나 사러가기
#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> pb) {
    set<string> s;
    for (auto it = pb.begin(); it != pb.end(); it++)
        s.insert(*it);
    
    auto it = s.begin();
    auto pre = it++;
    while (it != s.end()) {
        if (it->find(*pre) == 0)
            return false;
        pre = it++;
    }
    return true;
}
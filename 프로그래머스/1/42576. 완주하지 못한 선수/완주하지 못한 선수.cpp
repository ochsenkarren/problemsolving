#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

string solution(vector<string> par, vector<string> com) {
    unordered_multiset<string> ums;
    for (auto it = par.begin(); it != par.end(); ++it)
        ums.insert(*it);    
    for (auto it = com.begin(); it != com.end(); ++it)
        ums.erase(ums.find(*it));
    return (*ums.begin());
}
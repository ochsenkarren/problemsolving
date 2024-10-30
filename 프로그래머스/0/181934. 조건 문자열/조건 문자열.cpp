#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    bool gt = ineq == "<";
    bool e = eq == "=";

    if (gt) {        
        if (n < m)
            return true;
    }
    else if (n > m)
        return true;
    
    return (n == m && e);
}
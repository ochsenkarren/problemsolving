#include <string>
#include <sstream>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string aStr = to_string(a);
    string bStr = to_string(b);
    
    int A, B;
    stringstream istream1(aStr + bStr);
    istream1 >> A;
    stringstream istream2(bStr + aStr);
    istream2 >> B;    
    return A > B ? A : B;
}
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(int a, int b) {
    int A;
    int B;
    istringstream st(to_string(a) + to_string(b));
    st >> A;
    B = a * b * 2;
    return A < B ? B : A;    
}
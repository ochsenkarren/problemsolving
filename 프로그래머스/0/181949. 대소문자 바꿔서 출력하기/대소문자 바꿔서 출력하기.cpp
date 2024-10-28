#include <iostream>
#include <string>

using namespace std; 

int main(void) {
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        cout << ('a' <= str[i] ? (char)(str[i] - 32) : (char)(str[i] + 32)) ;
    return 0;
}
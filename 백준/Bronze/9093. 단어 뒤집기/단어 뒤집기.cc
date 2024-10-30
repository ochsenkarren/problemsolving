#include <iostream>
#include <stack>
using namespace std;
int main (void) {
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        string s;
        getline(cin, s);
        s += '\n';
        stack<char> st;
        for (char ch : s) {
            if (ch == ' ' || ch == '\n') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ch;
            }
            else
                st.push(ch);
        }
    }
}
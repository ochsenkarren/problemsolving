#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> st;
    
    st.push(arr[0]);
    
    for (int i = 1; i < arr.size(); ++i)
        if (st.top() != arr[i])
            st.push(arr[i]);
    int idx = st.size();
    vector<int> answer(idx--);
    while (!st.empty()) {
        answer[idx--] = st.top();
        st.pop();
    }
    return answer;
}
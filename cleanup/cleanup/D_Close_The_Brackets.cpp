#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#endif

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (s[0] == '?') {
            cout << "impossible" << endl;
        }
        else {
            stack <char> st;
            for (int i = 0 ; i < s.size() ; i++) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
                    st.push(s[i]);
                else if (s[i] == ')' && st.top() == '(') st.pop();
                else if (s[i] == '}' && st.top() == '{') st.pop();
                else if (s[i] == ']' && st.top() == '[') st.pop();
                else {
                    if (s[i] == '?' && st.empty()) {
                        cout << "impossible" << endl;
                        goto JUMP;
                    }
                    else if (s[i] == '?' && st.top() == '(') {
                        s[i] = ')';
                        st.pop();
                    }
                    else if (s[i] == '?' && st.top() == '[') {
                        s[i] = ']';
                        st.pop();
                    }
                    else if (s[i] == '?' && st.top() == '{') {
                        s[i] = '}';
                        st.pop();
                    }
                }
            }
            if (st.empty()) cout << s << endl;
            else cout << "impossible" << endl;
        }
        JUMP:
    }
    return 0;
}
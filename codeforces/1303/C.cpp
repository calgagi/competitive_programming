// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;


void solve() {
    string s;
    cin >> s;
    
    // If there are > 2 letters adjacent to a letter, then good
    // Must have at least two letters with <= 1 adjacent letter
    // Can do this with graph construction
    // Graph will be in the form of straight line (basically linked list)

    int n = s.length();
    map<char, set<char>> graph;
    for (int i = 0; i < n; i++) {
        if (i) {
            graph[s[i]].insert(s[i-1]);
        }
        if (i < n-1) {
            graph[s[i]].insert(s[i+1]);
        }
    }

    vector<char> one_items;
    int two_items = 0;

    if (n == 1) {
        one_items.push_back(s[0]);
    }

    for (auto& item : graph) {
        if (item.second.size() > 2) {
            cout << "NO" << endl;
            return;
        } else if (item.second.size() == 1) {
            one_items.push_back(item.first);
        } else {
            two_items++;
        }
    }

    if (one_items.size() != 2 && two_items != 0) {
        cout << "NO" << endl;
        return;
    }


    // Generate string
    string r;    
    vector<bool> seen(26, 0);
    stack<char> st;
    st.push(one_items[0]);
    while (!st.empty()) {
        char c = st.top();
        st.pop();
        if (seen[c-'a']) {
           continue;
        } 
        seen[c-'a'] = 1;
        r += c;
        for (auto e : graph[c]) {
            st.push(e);
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!seen[i]) {
            r += (char) i + 'a';
        }
    }

    cout << "YES" << endl;
    cout << r << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

bool is_simple(const string& s) {
    int st = 0;
    for (auto& c : s) {
        if (c == '(') {
            st++;
        } else {
            if (st > 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    string s;
    cin >> s;
    if (is_simple(s)) {
        cout << 0 << endl;
        return 0;
    } else {
        vector<int> idx;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            vector<int> open, close;
            for (int j = 0; j < i; j++) {
                if (s[j] == '(') {
                    open.push_back(j);
                }
            } 
            for (int j = n-1; j >= i; j--) {
                if (s[j] == ')') {
                    close.push_back(j);
                }
            }
            if (idx.size()/2 < min(open.size(), close.size())) {
                idx.clear();
                for (int j = 0; j < (int)min(open.size(), close.size()); j++) {
                    idx.push_back(open[j]);
                    idx.push_back(close[j]);
                }
            }
        }
        sort(idx.begin(), idx.end());
        cout << 1 << endl;
        cout << idx.size() << endl;
        for (auto& i : idx) {
            cout << i+1 << " ";
        }
        cout << endl;
    }
            
    return 0;
}

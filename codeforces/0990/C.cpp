// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    map<int,int> count;
    int n; cin >> n;
    long long ans = 0;
    while (n--) {
        string s; cin >> s;
        int st = 0, m = (int) s.length();
        bool back = 0, front = 0;
        for (int i = m-1; i >= 0; i--) {
            if (s[i] == ')') {
                st++;
            } else if (s[i] == '(') {
                st--;
                if (st < 0)
                    front = 1;
            }
        }
        st = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == '(') {
                st++;
            } else if (s[i] == ')') {
                st--;
                if (st < 0)
                    back = 1;
            }
        }
        if (back && front) continue;
        if (st == 0) {
            ans += count[0];
        }
        count[st]++; 
        ans += count[-st];
    } 
                 
    cout << ans << endl; 

    return 0;
}

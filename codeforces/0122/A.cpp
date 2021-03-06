// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int n; cin >> n;
    
    stack<int> dfs;
    dfs.push(4);
    dfs.push(7);
    bool flag = false;
    while (!dfs.empty()) {
        int t = dfs.top();
        dfs.pop();
        if (t >= 1000) continue;
        if (n % t == 0) {
            flag = true;
            break;
        }
        dfs.push(10*t + 4);
        dfs.push(10*t + 7);
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl; 

    return 0;
}

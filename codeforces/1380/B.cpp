/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define double double double
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long, long>
#define ar array
#define f first
#define s second

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> cnt(3, 0);
    map<char,int> translate = {{'R', 0}, {'S', 1}, {'P', 2}};
    map<char,char> win = {{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};

    for (int i = 0; i < n; i++) {
        cnt[translate[s[i]]]++;
    }

    string ans = ""; 
    for (int i = 0; i < n; i++) {
        int mx = max({cnt[0], cnt[1], cnt[2]});
        if (mx == cnt[0]) {
            ans += win['R'];
        } else if (mx == cnt[1]) {
            ans += win['S'];
        } else {
            ans += win['P'];
        }
    }
    
    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

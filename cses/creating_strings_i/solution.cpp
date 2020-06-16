/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

set<string> ans;
int n;

void build(int i, string& cur, vector<int>& available) {
    if (i >= n) {
        ans.insert(cur);
    }
    for (int j = 0; j < 26; j++) {
        if (available[j]) {
            available[j]--;
            cur[i] = (char) j + 'a';
            build(i+1, cur, available);
            available[j]++;
        }
    }
    return;
}

void solve() {
    string s;
    cin >> s;
    n = s.length();

    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }

    string cur(n, ' '); 
    build(0, cur, cnt);

    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}

/*
ID: calgagi1
LANG: C++
TASK: prefix
*/
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

struct Trie {
    vector<Trie*> c;
    bool v;
    Trie() {
        c.assign(26, 0);
        v = 0;
    }
};

vector<bool> dp;
Trie* t = new Trie;
string x = "";
int ans = 0;

void dfs(int i) {
    //cerr << i << endl;
    if (i >= x.length()) {
        return;
    }
    if (dp[i]) {
        return;
    }
    dp[i] = 1;
    Trie* it = t;
    for (int j = i; j < (int) x.length(); j++) {
        it = it->c[x[j]-'A'];
        if (!it) {
            break;
        }
        if (it->v) {
            ans = max(ans, j+1);
            dfs(j+1);
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("prefix.in", "r", stdin), *OUT = freopen("prefix.out", "w", stdout); 


    string s;
    while (1) {
        cin >> s;
        if (s == ".") {
            break;
        }
        //cerr << s << endl;
        Trie* it = t;
        for (int i = 0; i < (int) s.length(); i++) {
            if (it->c[s[i]-'A'] == NULL) {
                it->c[s[i]-'A'] = new Trie;
            }
            it = it->c[s[i]-'A'];
        }
        it->v = 1;
    }

    while (cin >> s) {
        x += s;
    }

    dp.assign(x.length(), 0);
    dfs(0);

    cout << ans << endl;

    return 0;
}

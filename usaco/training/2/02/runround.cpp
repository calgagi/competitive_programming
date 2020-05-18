/*
ID: calgagi1
LANG: C++
TASK: runround 
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

vector<ll> run;

void test(string s) {
    int start = 0, n = s.length();
    vector<bool> used(n, 0);
    while (!used[start]) {
        used[start] = 1;
        start = (start + s[start]-'0') % n;
    }
    if (start != 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            return;
        }
    }
    run.push_back(stoll(s));
    return;
}



void make(string cur, int used) {
    if (cur != "") {
        test(cur);
    }
    for (int i = 1; i < 10; i++) {
        if (!(used & (1 << i))) {
            string cur2 = cur;
            cur2 += (i + '0');
            make(cur2, used | (1 << i));
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("runround.in", "r", stdin), *OUT = freopen("runround.out", "w", stdout); 
    
    ll m;
    cin >> m;

    make("", 0);
    ll ans = LLONG_MAX;
    for (ll x : run) {
        if (x-m > 0) {
            ans = min(x, ans);
        }
    }

    cout << ans << endl;

    return 0;
}

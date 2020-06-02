/*
ID: calgagi1
LANG: C++
TASK: fracdec
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

void solve() {
    int n, d;
    cin >> n >> d;

    string ans = "";

    map<int,int> seen;

    if (n >= d) {
        int x = n / d;
        n %= d;
        ans += to_string(x);
    }

    if (ans == "") {
        ans += "0";
    }
    ans += "."; 

    seen[n] = ans.size();

    do {
        n *= 10;
        int x = n / d;
        n %= d;
        ans += to_string(x);
        if (seen.find(n) != seen.end()) {
            if (n != 0) {
                ans.insert(ans.begin() + seen[n], '(');
                ans.push_back(')');
            }
            break;
        }    
        seen[n] = ans.size();
    } while (n);

    int i = 0;
    while (i < (int) ans.size()) {
        cout << ans.substr(i, 76) << endl; 
        i += 76;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("fracdec.in", "r", stdin), *OUT = freopen("fracdec.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}

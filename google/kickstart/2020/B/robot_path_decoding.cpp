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

const int M = 1e9;

void check(int& r, int& c) {
    if (r < 0) {
        while (r < 0) {
            r += M;
        }
    } else if (r >= M) {
        r %= M;
    }
    if (c < 0) {
        while (c < 0) {
            c += M;
        }
    } else if (c >= M) {
        c %= M;
    }
}

ii expand(string& s, int& w) {
    int n = s.length();
    int change1 = 0, change2 = 0;
    for (; w < n && s[w] != ')'; w++) {
        if (s[w] <= '9' && s[w] >= '2') {
            int d = s[w] - '0';
            w += 2;
            ii x = expand(s, w);
            for (int i = 0; i < d; i++) {
                change1 += x.f;
                change2 += x.s;
                check(change1, change2);
            }
        } else {
            change1 += (s[w] == 'S' ? 1 : (s[w] == 'N' ? -1 : 0));
            change2 += (s[w] == 'E' ? 1 : (s[w] == 'W' ? -1 : 0));
        }
    }
    check(change1, change2);
    return {change1, change2};
}

void solve() {
    string e;
    cin >> e;
   
    int w = 0;

    ii x = expand(e, w);
    x.f++;
    x.s++;


    cout << x.s << " " << x.f << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}

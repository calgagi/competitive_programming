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


void solve() {
    int n; cin >> n;
    unordered_map<string,int> a;
    unordered_map<char,int> b;
    vector<string> arr(n);
    int res = 0;
    forn(i, n) {
        cin >> arr[i];
        b[arr[i][0]]++;
        a[arr[i]]++;
    }
    forn(i, n) {
        if (a[arr[i]] > 1) {
            res++;
            b[arr[i][0]]--;
            a[arr[i]]--;
            forn(j, 10) {
                if (b[j + '0'] == 0) {
                   arr[i][0] = j + '0';
                   b[arr[i][0]]++; 
                   break;
                } 
            }
        }
    }
    cout << res << endl;
    for (auto& i : arr) cout << i << endl;
    return;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    int n; cin >> n;
    while (n--) solve(); 

    return 0;
}

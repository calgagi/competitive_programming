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
    vector<int> a(n);
    unordered_map<int,int> s;
    int counter = 0;
    forn(i,n) {
        cin >> a[i];
        s[a[i]]++;
        if (s[a[i]] == 2)
            counter++;
    }
    int b = 0, e = 0, m = INT_MAX;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    while (e < n) {
        s[a[e]]--;
        if (s[a[e]] == 1)
            counter--;
        while (counter == 0 && b < n) {
            m = min(m, e-(b-1));
            s[a[b]]++;
            if (s[a[b]] > 1) {
                counter++;
            }
            b++;
        }
        e++;
    }
    cout << m << endl;

    return 0;
}

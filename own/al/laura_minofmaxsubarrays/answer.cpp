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
	
    int n, s; cin >> n >> s;
    vector<int> a(n);
    forn(i, n) cin >> a[i];

    deque<int> q;
    int res = INT_MAX;
    forn(i, n) {
        while (!q.empty() && q.back() < a[i])
           q.pop_back();
        q.push_back(a[i]); 
        if (i >= s-1) {
            res = min(q.front(), res);  
            if (q.front() == a[i-(s-1)])
                q.pop_front();
        }
    }
    cout << res << endl;
         

    return 0;
}

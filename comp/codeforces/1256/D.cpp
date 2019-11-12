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
	
    int Q; cin >> Q;
    forn(z, Q) {
        ll k;
        int N; cin >> N >> k;
        vector<char> b(N); 
        forn(i, N) cin >> b[i]; 
        queue<int> q;
        for (int i = 0; i < b.size() && k; i++) {
            if (b[i] == '1') q.push(i);
            else if (b[i] == '0' && !q.empty()) {
                while (!q.empty() && i - q.front() > k) q.pop();
                if (!q.empty()) {
                    swap(b[i], b[q.front()]);
                    k -= i - q.front();
                    q.push(i);
                    q.pop();
                }
            }
        }
        forn(i, N) cout << b[i];
        cout << endl;
        
    }

    return 0;
}

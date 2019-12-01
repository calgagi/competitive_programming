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
    int T; cin >> T;
    forn(t, T) {
        string s;
        cin >> s;
        queue<char> o, e;
        for (auto& c : s) 
            if ((c - '0') % 2) o.push(c);
            else e.push(c);
        int i = 0;
        while (i < s.length()) {
            if (!o.empty() && !e.empty()) {
                if (o.front() < e.front()) {
                    s[i] = o.front();
                    o.pop();
                } else {
                    s[i] = e.front();
                    e.pop();
                }
            } else if (!o.empty()) {
                s[i] = o.front();
                o.pop();
            } else {
                s[i] = e.front();
                e.pop();
            }
            i++;
        }
        cout << s << endl;        
    }


    return 0;
}
